#include <pch-il2cpp.h>

#include "ILPatternScanner.h"
#include <psapi.h>
#include <cheat-base/util.h>
#include <fmt/format.h>
#include <helpers.h>

#define SET_API_FUNC(r, n, p)                     \
	{                                                      \
		auto address = GetProcAddress(hMono, #n);          \
		if (address == nullptr)                            \
		{                                                  \
			LOG_ERROR("Failed to get function '%s'.", #n); \
			return;                                        \
		}                                                  \
		n = (r (*) p) address;                             \
	} 

#define FIND_VALUE(t, n, pat, o) static t n = nullptr; static t* p ##n = nullptr; \
	if (n == nullptr) \
	{ \
		auto result = PatternScanner::SearchValue<t*>(ILPatternScanner::GetMonoHandle(), pat, o); \
		if (!result) \
		{ \
			LOG_DEBUG("Failed to get " #n " address"); \
		} \
		else \
		{ \
			n = **result; \
				p##n = *result; \
				LOG_DEBUG(#n " at 0x%p", *result); \
		} \
	}

#define GET_FUNC_BY_XREF(r, n, p, pattern, offset) static r (*n) p = nullptr;         \
	if (n == nullptr)\
	{																				  \
		auto result = PatternScanner::SearchValue<r (*) p>(ILPatternScanner::GetMonoHandle(), pattern, offset); \
		if (!result) LOG_ERROR("Failed to find pattern '%s' for function '%s'.", pattern, #n); \
		else n = *result;											      \
	}

#define SET_API_FUNC_P(r, n, p, pattern) static r (*n) p = nullptr;                   \
	if (n == nullptr)\
	{																				  \
		auto address = SearchInModule(ILPatternScanner::GetMonoHandle(), pattern);	  \
		if (address == 0)																  \
		{																			  \
			LOG_ERROR("Failed to find pattern '%s' for function '%s'.", pattern, #n); \
		}																			  \
		n = (r (*) p) address;											      \
	}

void ILPatternScanner::ParseSignatureJson(void* signatureJson)
{
	nlohmann::json& jsonContent = *reinterpret_cast<nlohmann::json*>(signatureJson);
	PatternScanner::ParseSignatureJson(&jsonContent["method"]);

	ParseXrefsJson(jsonContent["methodInfo"], m_MethodInfoPattern);
	ParseXrefsJson(jsonContent["typeInfo"], m_TypeInfoPattern);
}

std::map<std::string, uintptr_t> ILPatternScanner::LoadOffsetMap(const nlohmann::json& inObject)
{
	std::map<std::string, uintptr_t> result;
	for (auto& entry : inObject.items())
		result[entry.key()] = GetOffsetInt(entry.value());
	return result;
}

void ILPatternScanner::SaveOffsetMap(nlohmann::json& outObject, const std::map<std::string, uintptr_t>& map)
{
	for (auto& [key, value] : map)
		outObject[key] = GetOffsetStr(value);
}

void ILPatternScanner::SaveJson(nlohmann::json & outObject)
{
	PatternScanner::SaveJson(outObject["moduleInfo"]);

	PatternScanner::SaveModuleHash(GetMonoHandle(), outObject["monoHash"]);
	SaveOffsetMap(outObject["apiFunctions"], m_ApiMethodsCache);
	SaveOffsetMap(outObject["typeInfo"], m_TypeInfoCache);
	SaveOffsetMap(outObject["methodInfo"], m_MethodInfoCache);
}

bool ILPatternScanner::LoadJson(const nlohmann::json & object)
{
	if (object.contains("moduleInfo"))
		PatternScanner::LoadJson(object["moduleInfo"]);

	if (object.contains("monoHash") && !PatternScanner::IsValidModuleHash(GetMonoHandle(), object["monoHash"]))
	{
		LOG_DEBUG("Mono module hash mismatch. Seems game was updated.");
		return false;
	}

	if (object.contains("apiFunctions"))
		m_ApiMethodsCache = LoadOffsetMap(object["apiFunctions"]);

	if (object.contains("typeInfo"))
		m_TypeInfoCache = LoadOffsetMap(object["typeInfo"]);

	if (object.contains("methodInfo"))
		m_MethodInfoCache = LoadOffsetMap(object["methodInfo"]);

	return true;
}

std::string SubstrFromLastOccur(const std::string & value, char findChar)
{
	size_t lastCharPos = value.find_last_of(findChar);
	if (lastCharPos != std::string::npos)
		return value.substr(lastCharPos + 1);
	return value;
}

void ReplaceAllOccur(std::string & value, char findChar, char replaceChar)
{
	size_t pos = value.find(findChar);

	char* data = const_cast<char*>(value.data());
	while (pos != std::string::npos)
	{
		data[pos] = replaceChar;
		pos = value.find(findChar, pos + 1);
	}
}

HMODULE ILPatternScanner::GetMonoHandle()
{
	return (HMODULE)il2cpp_get_mono_base_address();
}

ILPatternScanner::MetadataInfo* ILPatternScanner::GetMetadataInfo()
{
	FIND_VALUE(void*, s_GlobalMetadata, "48 89 05 ?? ?? ?? ?? 48 85 C0 75 13", 3);
	static ModifiedMetadataHeader* s_GlobalMetadataHeader = *reinterpret_cast<ModifiedMetadataHeader**>(ps_GlobalMetadata + 1);

	FIND_VALUE(Il2CppMetadataRegistration*, s_Il2CppMetadataRegistration, "48 8B 05 ?? ?? ?? ?? 48 63 48 30", 3);
	static Il2CppCodeRegistration* s_Il2CppCodeRegistration = *reinterpret_cast<Il2CppCodeRegistration**>(ps_Il2CppMetadataRegistration - 1);
	static MetadataInfo registrationInfo = { s_GlobalMetadata, s_GlobalMetadataHeader, s_Il2CppCodeRegistration , s_Il2CppMetadataRegistration };
	return &registrationInfo;
}

ILPatternScanner::ILPatternScanner() : PatternScanner() { }

uintptr_t ILPatternScanner::SearchAPI(const std::string& apiFunctionName)
{
	uintptr_t monoBase = il2cpp_get_mono_base_address();
	HMODULE hMono = GetMonoHandle();

	if (m_ApiMethodsCache.count(apiFunctionName) > 0)
		return monoBase + m_ApiMethodsCache[apiFunctionName];

	uintptr_t apiFuncAddress = reinterpret_cast<uintptr_t>(GetProcAddress(hMono, apiFunctionName.c_str()));
	if (apiFuncAddress == 0)
	{
		LOG_LAST_ERROR("API %s not found.", apiFunctionName.c_str());

		return 0;
	}

	LOG_DEBUG("API %s was found at UserAssembly.dll + 0x%p.", apiFunctionName.c_str(), apiFuncAddress - monoBase);
	m_ApiMethodsCache[apiFunctionName] = apiFuncAddress - monoBase;
	m_CacheChanged = true;
	return apiFuncAddress;
}

uintptr_t ILPatternScanner::SearchTypeInfo(const std::string& typeName)
{
	HMODULE hMono = GetMonoHandle();
	uintptr_t monoBase = il2cpp_get_mono_base_address();
	if (m_TypeInfoCache.count(typeName) > 0)
		return m_TypeInfoCache[typeName] == 0 ? 0 : monoBase + m_TypeInfoCache[typeName];

	auto& xrefs = m_TypeInfoPattern[typeName];
	AddressCounter counter;
	for (auto& xrefInfo : xrefs)
	{
		uintptr_t address = SearchXref(hMono, xrefInfo);
		if (address == 0)
			continue;
		counter.Add(address);
	}

	uintptr_t address = counter.GetMax();
	if (address == 0)
	{
		address = GetUsageOffset(typeName);
		address = address == 0 ? 0 : address + monoBase;
	}

	if (address == 0)
		LOG_WARNING("TypeInfo '%s' not found.", typeName.c_str());
	else
		LOG_DEBUG("TypeInfo '%s' was found at UserAssembly.dll + 0x%p.", typeName.c_str(), address - monoBase);

	m_TypeInfoCache[typeName] = address == 0 ? 0 : address - monoBase;
	m_CacheChanged = true;
	return address;
}

uintptr_t ILPatternScanner::SearchMethodInfo(const std::string& methodName)
{
	HMODULE hMono = GetMonoHandle();
	uintptr_t monoBase = il2cpp_get_mono_base_address();
	if (m_MethodInfoCache.count(methodName) > 0)
		return m_MethodInfoCache[methodName] == 0 ? 0 : monoBase + m_MethodInfoCache[methodName];

	auto& xrefs = m_MethodInfoPattern[methodName];
	AddressCounter counter;
	for (auto& xrefInfo : xrefs)
	{
		uintptr_t address = SearchXref(hMono, xrefInfo);
		if (address == 0)
			continue;
		counter.Add(address);
	}

	uintptr_t address = counter.GetMax();
	if (address == 0)
	{
		address = GetUsageOffset(methodName);
		address = address == 0 ? 0 : address + monoBase;
	}

	if (address == 0)
		LOG_WARNING("MethodInfo '%s' not found.", methodName.c_str());
	else
		LOG_DEBUG("MethodInfo '%s' was found at UserAssembly.dll + 0x%p.", methodName.c_str(), address - monoBase);

	m_MethodInfoCache[methodName] = address == 0 ? 0 : address - monoBase;
	m_CacheChanged = true;
	return address;
}

uintptr_t ILPatternScanner::Search(const std::string& moduleName, const std::string& name)
{
	bool isSaved = m_CacheOffsets.count(moduleName) > 0 && m_CacheOffsets[moduleName].count(name) > 0;
	if (!isSaved && m_ModulePatterns.count(moduleName) > 0 && m_ModulePatterns[moduleName].count(name) > 0)
	{
		auto& methodPatternData = m_ModulePatterns[moduleName][name];
		if (methodPatternData.signatures.size() == 0 && methodPatternData.xrefs.size() == 0)
		{
			LOG_DEBUG("Method '%s::%s' has not signatures, will be used manual specified offset.", moduleName.c_str(), name.c_str());
			AddOffset(moduleName, name, 0);
			return 0;
		}
	}

	uintptr_t result = PatternScanner::Search(moduleName, name);
	if (result != 0 || isSaved)
	{
		if (!isSaved)
			LOG_DEBUG("Method '%s::%s' was found at %s + 0x%p.", moduleName.c_str(), name.c_str(),
				moduleName.c_str(), result - il2cpp_get_mono_base_address());

		return result;
	}

	if (GetModuleInfo(moduleName).handle != GetMonoHandle())
	{
		LOG_WARNING("Method '%s::%s' not found.", moduleName.c_str(), name.c_str());
		return 0;
	}

	uintptr_t address = GetMethodAddress(name);
	if (address != 0)
	{
		LOG_DEBUG("Method '%s::%s' was found at %s + 0x%p by name.", moduleName.c_str(), name.c_str(),
			moduleName.c_str(), result - il2cpp_get_mono_base_address());

		AddOffset(moduleName, name, address - il2cpp_get_mono_base_address());
	}
	return address;
}

void ILPatternScanner::SearchAll()
{
	PatternScanner::SearchAll();

	for (auto& [name, entry] : m_MethodInfoPattern)
		SearchMethodInfo(name);

	for (auto& [name, entry] : m_TypeInfoPattern)
		SearchMethodInfo(name);
}

void ILPatternScanner::ParseXrefsJson(const nlohmann::json& xrefsJson, std::map<std::string, std::vector<OffsetSignature>>& out)
{
	for (auto& entry : xrefsJson.items())
	{
		std::string name = entry.key();
		out[name] = {};
		auto& newPatternEntry = out[name];

		for (auto& xrefInfo : entry.value())
			newPatternEntry.push_back({ xrefInfo["sig"], xrefInfo["offset"] });
	}
}

uintptr_t ILPatternScanner::GetUsageOffset(const std::string& name)
{
	if (m_UsageOffsetMap.size() == 0)
		LoadUsage();

	if (m_UsageOffsetMap.count(name) == 0)
		return 0;
	return m_UsageOffsetMap[name];
}

uintptr_t ILPatternScanner::GetMethodAddress(const std::string& name)
{
	if (m_MethodNameMap.size() == 0)
		LoadUsage();

	if (m_MethodNameMap.count(name) == 0)
		return 0;

	return m_MethodNameMap[name];
}

uintptr_t ILPatternScanner::FindFunctionEntry(uintptr_t address)
{
	auto& monoModuleInfo = GetModuleInfo(GetMonoHandle());
	if (address < monoModuleInfo.base || address > monoModuleInfo.base + monoModuleInfo.size)
		return address;

	if (m_MethodPointers.size() == 0)
		LoadMethodPointers();

	auto iter = std::upper_bound(m_MethodPointers.begin(), m_MethodPointers.end(), address);
	if (iter != m_MethodPointers.begin())
	{
		iter--;
		return *iter;
	}

	return 0;
}

void ILPatternScanner::LoadMethodPointers()
{
	/* Outdated. Need update to version 2.7
	auto info = GetMetadataInfo();

#define LOAD_METHOD_POINTERS(countField, field) LOG_DEBUG( #field ": %d", info->codeRegistration->##countField); \
	for (uint32_t i = 0; i < info->codeRegistration->##countField##; i++) \
		m_MethodPointers.push_back((uintptr_t)info->codeRegistration->##field[i]);

	LOAD_METHOD_POINTERS(methodPointersCount, methodPointers);
	LOAD_METHOD_POINTERS(reversePInvokeWrapperCount, reversePInvokeWrappers);
	LOAD_METHOD_POINTERS(genericMethodPointersCount, genericMethodPointers);
	LOAD_METHOD_POINTERS(invokerPointersCount, invokerPointers);
	LOAD_METHOD_POINTERS(unresolvedVirtualCallCount, unresolvedVirtualCallPointers);

#undef LOAD_METHOD_POINTERS

	std::sort(m_MethodPointers.begin(), m_MethodPointers.end());
	LOG_DEBUG("Loaded %llu method pointers.", m_MethodPointers.size());
	*/
}

template<typename T>
static T MetadataOffset(void* metadata, size_t sectionOffset, size_t itemIndex)
{
	return reinterpret_cast<T>(reinterpret_cast<uint8_t*>(metadata) + sectionOffset) + itemIndex;
}

const MethodInfo* ILPatternScanner::GetMethodInfoFromIndex(uint32_t methodIndex)
{
	/* Outdated. Need update to version 2.7
	SET_API_FUNC_P(Il2CppGenericMethod*, GetGenericMethodFromIndex, (uint32_t index), "40 53 48 83 EC 20 48 8B 05 ?? ?? ?? ?? 48 63");

	GET_FUNC_BY_XREF(MethodInfo*, GetMethod, (const Il2CppGenericMethod * gmethod), "E8 ?? ?? ?? ?? 48 8B C8 0F B7 FE", 1);
	GET_FUNC_BY_XREF(MethodInfo*, GetMethodInfoFromMethodDefinitionIndex, (uint32_t index), "E8 ?? ?? ?? ?? 48 8B 40 18 48 83 C4 28", 1);
	
	uint32_t index = GetDecodedMethodIndex(methodIndex);

	if (index == 0)
		return NULL;

	if (GetEncodedIndexType(methodIndex) == kIl2CppMetadataUsageMethodRef)
		return GetMethod(GetGenericMethodFromIndex(index));
	else
		return GetMethodInfoFromMethodDefinitionIndex(index);
		*/
	return nullptr;
}

std::string ILPatternScanner::ComputeGenericParamsPrefix(const Il2CppGenericInst* inst)
{
	std::stringstream paramsPrefix;
	for (uint32_t i = 0; i < inst->type_argc; i++)
	{
		if (i > 0)
			paramsPrefix << "_";

		const Il2CppType* type = inst->type_argv[i];
		std::string typeName = il2cpp_type_get_name(type);
		//if (m_TranslationMap.count(typeName) > 0)
		//	typeName = m_TranslationMap[typeName];

		paramsPrefix << typeName;
	}

	return paramsPrefix.str();
}

std::string ILPatternScanner::ComputeInspectorClassName(const Il2CppClass* klass)
{
	std::string className = il2cpp_class_get_name(const_cast<Il2CppClass*>(klass));

	std::stringstream fullNameStream;

	if (className != "<Module>")
	{
		className = SubstrFromLastOccur(className, '.');
		ReplaceAllOccur(className, '`', '_');
		fullNameStream << className;
	}

	bool isInflated = il2cpp_class_is_inflated(klass);
	bool isGeneric = il2cpp_class_is_generic(klass);
	
	Il2CppGenericClass* genericClass = klass->generic_class;
	if (isGeneric || !isInflated || genericClass == nullptr)
		return fullNameStream.str();

	const Il2CppGenericInst* classInst = genericClass->context.class_inst;
	if (classInst != nullptr)
		fullNameStream << "_" << ComputeGenericParamsPrefix(classInst) << "_";
	return fullNameStream.str();
}

std::string ILPatternScanner::ComputeInspectorMethodName(const MethodInfo* method)
{
	static std::map<std::string, uint32_t> countNames;

	Il2CppClass* klass = il2cpp_method_get_class(method);
	std::string methodName = il2cpp_method_get_name(method);

	std::stringstream fullNameStream;

	fullNameStream << ComputeInspectorClassName(klass);

	fullNameStream << "_" << methodName;

	//bool isInflated = il2cpp_method_is_inflated(method);
	//bool isGeneric = il2cpp_method_is_generic(method);

	//const Il2CppGenericMethod* genericMethod = method->genericMethod;
	//if (isGeneric || !isInflated || genericMethod == nullptr)
	//	return fullNameStream.str();

	std::string currentNamePart = fullNameStream.str();
	if (countNames.count(currentNamePart) == 0)
	{
		countNames[currentNamePart] = 0;
		return fullNameStream.str();
	}

	auto& count = countNames[currentNamePart];
	count++;
	fullNameStream << "_" << count;

	return fullNameStream.str();
}

void ILPatternScanner::LoadUsage()
{
	/* Outdated. Need update to version 2.7.
	SET_API_FUNC_P(Il2CppClass*, GetTypeInfoFromTypeIndex, (uint32_t index), "48 83 EC 28 83 F9 FF 75");

	auto info = GetMetadataInfo();

	auto s_GlobalMetadata = info->globalMeadata;
	auto s_GlobalMetadataHeader = info->metadataHeader;
	auto s_Il2CppMetadataRegistration = info->metadataRegistration;
	
	auto monoModuleBase = il2cpp_get_mono_base_address();

	uint32_t usageListCount = static_cast<uint32_t>(s_GlobalMetadataHeader->metadataUsageListsCount) / sizeof(Il2CppMetadataUsagePair);
	for (uint32_t index = 0; index < usageListCount; index++)
	{
		const Il2CppMetadataUsageList* metadataUsageLists = MetadataOffset<const Il2CppMetadataUsageList*>(s_GlobalMetadata, s_GlobalMetadataHeader->metadataUsageListsOffset, index);

		uint32_t start = metadataUsageLists->start;
		uint32_t count = metadataUsageLists->count;

		for (uint32_t i = 0; i < count; i++)
		{
			uint32_t offset = start + i;
			const Il2CppMetadataUsagePair* metadataUsagePairs = MetadataOffset<const Il2CppMetadataUsagePair*>(s_GlobalMetadata, s_GlobalMetadataHeader->metadataUsagePairsOffset, offset);
			uint32_t destinationIndex = metadataUsagePairs->destinationIndex;
			uint32_t encodedSourceIndex = metadataUsagePairs->encodedSourceIndex;

			Il2CppMetadataUsage usage = GetEncodedIndexType(encodedSourceIndex);
			uint32_t decodedIndex = GetDecodedMethodIndex(encodedSourceIndex);
			
			void** container = s_Il2CppMetadataRegistration->metadataUsages[destinationIndex];
			uintptr_t containerOffset = reinterpret_cast<uintptr_t>(container) - monoModuleBase;

			switch (usage)
			{
			case kIl2CppMetadataUsageTypeInfo:
			{
				Il2CppClass* klass = GetTypeInfoFromTypeIndex(decodedIndex);

				std::string className = ComputeInspectorClassName(klass) + "__TypeInfo";
				m_UsageOffsetMap[className] = offset;

				*container = klass;
			}
			break;
			case kIl2CppMetadataUsageMethodDef:
			case kIl2CppMetadataUsageMethodRef:
			{
				MethodInfo* method = const_cast<MethodInfo*>(GetMethodInfoFromIndex(encodedSourceIndex));
				*container = method;

				if (method->is_generic || method->methodPointer == nullptr)
					break;

				std::string methodName = ComputeInspectorMethodName(method);
				std::string methodInfoName = methodName + "__MethodInfo";

				m_UsageOffsetMap[methodInfoName] = offset;

				uintptr_t pointer = reinterpret_cast<uintptr_t>(method->methodPointer);
				m_MethodNameMap[methodName] = pointer;
				// m_MethodPointerMap[pointer] = methodName;
			}
				break;
			default:
				break;
			}
		}
	}
	LoadMetadata();*/
}

void ILPatternScanner::LoadMetadata()
{
	LOG_DEBUG("Loading methods...");

	if (!GetMonoHandle())
	{
		LOG_ERROR("Mono module not found in game process.");
		return;
	}

	SET_API_FUNC_P(void, image_get_types, (const Il2CppImage * image, bool exportedOnly, std::vector<const Il2CppClass*>*target), "48 89 5C 24 18 55 56 41 56 48 83 EC 20 8B");

	size_t assembliesCount = 0;
	auto assemblies = il2cpp_domain_get_assemblies(il2cpp_domain_get(), &assembliesCount);

	for (size_t i = 0; i < assembliesCount; i++)
	{
		auto assembly = assemblies[i];
		auto image = il2cpp_assembly_get_image(assembly);

		std::vector<const Il2CppClass*> types;
		image_get_types(image, true, &types);

		for (auto& type : types)
			LoadClassMethods(const_cast<Il2CppClass*>(type));
	}
	// LoadGenericMethods();

	LOG_DEBUG("Loaded %llu method names.", m_MethodNameMap.size());
	LOG_DEBUG("Loaded %llu usages.", m_UsageOffsetMap.size());
}

void ILPatternScanner::LoadClassMethods(Il2CppClass* klass)
{
	void* iter = nullptr;
	const MethodInfo* method = nullptr;
	std::string className = il2cpp_class_get_name(klass);
	do
	{
		method = il2cpp_class_get_methods(klass, &iter);
		if (method == nullptr)
			break;

		uintptr_t methodPtr = *(uintptr_t*)method;
		if (methodPtr == 0)
			continue;

		std::string methodName = ComputeInspectorMethodName(method);

		m_MethodNameMap[methodName] = methodPtr;
		//m_MethodPointerMap[methodPtr] = name;
	} while (method);

	iter = nullptr;
	const Il2CppClass* nested = nullptr;
	do
	{
		nested = il2cpp_class_get_nested_types(klass, &iter);
		if (nested == nullptr)
			break;
		LoadClassMethods((Il2CppClass*)nested);

	} while (true);
}

// 
//void ILPatternScanner::LoadGenericMethods()
//{
//	SET_API_FUNC_P(Il2CppGenericMethod*, MetadataCache_GetGenericMethodFromIndex, (uint32_t index), "40 53 48 83 EC 20 48 8B 05 ?? ?? ?? ?? 48 63");
//	FIND_VALUE(MethodInfo**, s_MethodInfoDefinitionTable, "48 8B 05 ?? ?? ?? ?? 48 C1 E2 06", 3);
//	
//	auto registration = GetMetadataInfo();
//
//	LOG_DEBUG("Count generic functions: %d", registration->metadataRegistration->genericMethodTableCount);
//	for (int i = 0; i < registration->metadataRegistration->genericMethodTableCount; i++)
//	{
//		auto genericMethodIndices = registration->metadataRegistration->genericMethodTable + i;
//		auto index = genericMethodIndices->genericMethodIndex;
//
//		auto methodSpec = registration->metadataRegistration->methodSpecs + index;
//		auto methodInfoOffset = ps_MethodInfoDefinitionTable + methodSpec->methodDefinitionIndex;
//
//		auto genericMethod = MetadataCache_GetGenericMethodFromIndex(index);
//		auto methodDefinition = genericMethod->methodDefinition;
//		auto methodName = il2cpp_method_get_name(methodDefinition);
//		if (strcmp(methodName, "get_Instance") != 0)
//			continue;
//
//		auto klass = il2cpp_method_get_class(methodDefinition);
//		auto className = il2cpp_class_get_name(klass);
//
//		std::string name = className;
//
//		auto classInst = genericMethod->context.class_inst;
//		for (int i = 0; i < classInst->type_argc; i++)
//		{
//			auto type = classInst->type_argv[i];
//			auto typeName = il2cpp_type_get_name(type);
//			name = fmt::format("{}_{}", name, typeName);
//		}
//		LOG_DEBUG("%s_%s : %d", name.c_str(), methodName, methodSpec->methodDefinitionIndex);
//	}
//} 
#undef SET_API_FUNC
#undef SET_API_FUNC_P
#undef FIND_VALUE