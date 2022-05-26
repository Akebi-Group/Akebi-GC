#pragma once
#include <cheat-base/PatternScanner.h>
class ILPatternScanner :
    public PatternScanner
{

public:
	ILPatternScanner();
	
	uintptr_t SearchAPI(const std::string& apiFunctionName);
	uintptr_t SearchTypeInfo(const std::string& typeName);
	uintptr_t SearchMethodInfo(const std::string& methodName);

	uintptr_t Search(const std::string& moduleName, const std::string& name) override;

	void SearchAll() override;

	void SaveJson(nlohmann::json& outObject) override;
	bool LoadJson(const nlohmann::json& object) override;

protected:

	std::map<std::string, uintptr_t> m_MethodNameMap;
	//std::map<uintptr_t, std::string> m_MethodPointerMap;
	std::map<std::string, uintptr_t> m_UsageOffsetMap;

	std::map<std::string, std::vector<OffsetSignature>> m_MethodInfoPattern;
	std::map<std::string, std::vector<OffsetSignature>> m_TypeInfoPattern;

	// Maybe in future I do search method/type info by translated name, but not now, not now
	// std::map<std::string, std::string> m_TranslationMap;

	std::map<std::string, uintptr_t> m_ApiMethodsCache;
	std::map<std::string, uintptr_t> m_MethodInfoCache;
	std::map<std::string, uintptr_t> m_TypeInfoCache;

	std::vector<uintptr_t> m_MethodPointers;

	uintptr_t GetUsageOffset(const std::string& name);
	uintptr_t GetMethodAddress(const std::string& name);
	uintptr_t FindFunctionEntry(uintptr_t address) override;

	static HMODULE GetMonoHandle();

	void ParseXrefsJson(const nlohmann::json& xrefsJson, std::map<std::string, std::vector<PatternScanner::OffsetSignature>>& out);

	std::map<std::string, uintptr_t> LoadOffsetMap(const nlohmann::json& inObject);
	void SaveOffsetMap(nlohmann::json& outObject, const std::map<std::string, uintptr_t>& map);

	void LoadMetadata();
	void LoadMethodPointers();

	std::string ComputeGenericParamsPrefix(const Il2CppGenericInst* inst);
	std::string ComputeInspectorClassName(const Il2CppClass* klass);
	std::string ComputeInspectorMethodName(const MethodInfo* method);
	const MethodInfo* GetMethodInfoFromIndex(uint32_t methodIndex);
	void LoadUsage();

	// void LoadGenericMethods();
	void LoadClassMethods(Il2CppClass* klass);

	struct ModifiedMetadataHeader
	{
		char unk[0x28];

		int genericContainersOffset; // Il2CppGenericContainer
		int genericContainersCount;
		int nestedTypesOffset; // TypeDefinitionIndex
		int nestedTypesCount;
		int interfacesOffset; // TypeIndex
		int interfacesCount;
		int vtableMethodsOffset; // EncodedMethodIndex
		int vtableMethodsCount;
		int interfaceOffsetsOffset; // Il2CppInterfaceOffsetPair
		int interfaceOffsetsCount;
		int typeDefinitionsOffset; // Il2CppTypeDefinition
		int typeDefinitionsCount;
		
		int rgctxEntriesOffset; // Il2CppRGCTXDefinition
		int rgctxEntriesCount;
		
		int unk1;
		int unk2;
		int unk3;
		int unk4;
		
		int imagesOffset; // Il2CppImageDefinition
		int imagesCount;
		int assembliesOffset; // Il2CppAssemblyDefinition
		int assembliesCount;
		
		int fieldsOffset;
		int fieldsCount;
		int genericParametersOffset; // Il2CppGenericParameter
		int genericParametersCount;
		
		int fieldAndParameterDefaultValueDataOffset; // uint8_t
		int fieldAndParameterDefaultValueDataCount;
		
		int fieldMarshaledSizesOffset; // Il2CppFieldMarshaledSize
		int fieldMarshaledSizesCount;
		int referencedAssembliesOffset; // int32_t
		int referencedAssembliesCount;
		
		int attributesInfoOffset; // Il2CppCustomAttributeTypeRange
		int attributesInfoCount;
		int attributeTypesOffset; // TypeIndex
		int attributeTypesCount;
		
		int unresolvedVirtualCallParameterTypesOffset; // TypeIndex
		int unresolvedVirtualCallParameterTypesCount;
		int unresolvedVirtualCallParameterRangesOffset; // Il2CppRange
		int unresolvedVirtualCallParameterRangesCount;
		
		int windowsRuntimeTypeNamesOffset; // Il2CppWindowsRuntimeTypeNamePair
		int windowsRuntimeTypeNamesSize;
		int exportedTypeDefinitionsOffset; // TypeDefinitionIndex
		int exportedTypeDefinitionsCount;
		
		int unk5;
		int unk6;
		
		int parametersOffset; // Il2CppParameterDefinition
		int parametersCount;
		
		int genericParameterConstraintsOffset; // TypeIndex
		int genericParameterConstraintsCount;
		
		int unk7;
		int unk8;
		
		int metadataUsagePairsOffset; // Il2CppMetadataUsagePair
		int metadataUsagePairsCount;

		int unk9;
		int unk10;
		int unk11;
		int unk12;

		int fieldRefsOffset; // Il2CppFieldRef
		int fieldRefsCount;

		int eventsOffset; // Il2CppEventDefinition
		int eventsCount;
		int propertiesOffset; // Il2CppPropertyDefinition
		int propertiesCount;
		int methodsOffset; // Il2CppMethodDefinition
		int methodsCount;

		int parameterDefaultValuesOffset; // Il2CppParameterDefaultValue
		int parameterDefaultValuesCount;

		int fieldDefaultValuesOffset; // Il2CppFieldDefaultValue
		int fieldDefaultValuesCount;

		int unk13;
		int unk14;
		int unk15;
		int unk16;

		int metadataUsageListsOffset; // Il2CppMetadataUsageList
		int metadataUsageListsCount;
	};

	struct MetadataInfo
	{
		void* globalMeadata;
		ModifiedMetadataHeader* metadataHeader;

		Il2CppCodeRegistration* codeRegistration;
		Il2CppMetadataRegistration* metadataRegistration;
	};

	MetadataInfo* GetMetadataInfo();


	void ParseSignatureJson(void* signatureJson) override;

};

