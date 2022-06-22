#pragma once

#include <string>
#include <optional>
#include <map>
#include <filesystem>
#include <cheat-base/util.h>
class PatternScanner
{
public:
	PatternScanner();

	uintptr_t Search(const std::string& name);
	virtual uintptr_t Search(const std::string& moduleName, const std::string& name);

	virtual void SearchAll();

	void Save(const std::filesystem::path& filename);
	void Save(std::string& outContent);

	bool Load(const std::filesystem::path& filename);
	bool Load(const std::string& content);

	virtual void SaveJson(nlohmann::json& outObject);
	virtual bool LoadJson(const nlohmann::json& object);

	void ParseSignatureFile(const std::string& signaturesContent);

	bool IsUpdated();

	bool IsValidModuleHash(HMODULE HMODULE, const nlohmann::json& hashObject);
	bool IsValidModuleHash(const std::string& moduleName, const nlohmann::json& hashObject);

	int64_t GetModuleTimestamp(const std::string& moduleName);
	int64_t GetModuleTimestamp(HMODULE hModule);
	
	uintptr_t SearchInModule(const std::string& moduleName, const std::string& pattern);
	uintptr_t SearchInModule(HMODULE hModule, const std::string& pattern);

protected:

	class AddressCounter
	{
	public:
		AddressCounter();
		void Add(uintptr_t address);
		uintptr_t GetMax();
	
	private:
		std::map<uintptr_t, size_t> m_Counts;
	};

	struct OffsetSignature
	{
		std::string pattern;
		uint32_t offset;
	};

	struct PatternInfo
	{
		std::vector<std::string> signatures;
		std::vector<OffsetSignature> xrefs;
	};

	std::map<std::string, std::map<std::string, PatternInfo>> m_ModulePatterns;
	std::map<std::string, std::map<std::string, uintptr_t>> m_CacheOffsets;
	bool m_CacheChanged;
	std::string m_LoadCache;
	
	std::map<HMODULE, int64_t> m_ComputedHashes;


	struct RegionInfo
	{
		uintptr_t base;
		size_t size;
	};

	struct ModuleInfo
	{
		HMODULE handle = 0;
		uintptr_t base = 0;
		size_t size = 0;
		std::string filePath;
		std::vector<RegionInfo> execRegions;
	};
	
	void AddOffset(const std::string& moduleName, const std::string& name, uintptr_t offset);

	void SaveModuleHash(HMODULE hModule, nlohmann::json& outObject);
	void SaveModuleHash(const std::string& moduleName, nlohmann::json& outObject);
	
	ModuleInfo& GetModuleInfo(HMODULE hModule);
	ModuleInfo& GetModuleInfo(const std::string& moduleName);

	virtual void ParseSignatureJson(void* signatureJson);

	virtual uintptr_t Search(const std::string& moduleName, const std::string& name, const PatternInfo& info);
	uintptr_t SearchFunction(const std::string& moduleName, const std::string& pattern);

	uintptr_t SearchXref(const std::string& moduleName, const OffsetSignature& xrefPattern);
	uintptr_t SearchXref(HMODULE hModule, const OffsetSignature& xrefPattern);

	uintptr_t GetOffsetInt(const nlohmann::json& value);
	std::string GetOffsetStr(uintptr_t offset);

	template<typename R>
	std::optional<R> SearchValue(HMODULE hModule, const std::string& pattern, uint32_t codeOffset)
	{
		auto address = SearchInModule(hModule, pattern);
		if (address == 0)
			return {};

		int offset = util::ReadMapped<int>((void*)address, codeOffset, true);
		return reinterpret_cast<R>(address + offset + codeOffset + sizeof(int));
	}

	enum class SRStatus
	{
		Unique,
		NotUnique,
		NotFound
	};

	struct SearchResult
	{
		SRStatus status;
		uintptr_t value;
	};

	SearchResult SearchSignature(PBYTE input, size_t inputLen, const std::vector<std::optional<uint8_t>>& sig);
	SearchResult SearchSignatureAVX2(PBYTE input, size_t inputLen, const std::vector<std::optional<uint8_t>>& sig);
	SearchResult SearchInRange(uintptr_t start, uintptr_t end, const std::vector<std::optional<uint8_t>>& pattern);

	virtual bool IsFunctionEntry(uintptr_t address);
	virtual uintptr_t FindFunctionEntry(uintptr_t address);
};

