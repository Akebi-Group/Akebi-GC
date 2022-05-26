#include "pch-il2cpp.h"
#include "ProtoManager.h"

#include <fstream>

namespace sniffer
{

	class ErrorCollector : public google::protobuf::compiler::MultiFileErrorCollector
	{
		// Inherited via MultiFileErrorCollector
		virtual void AddError(const std::string& filename, int line, int column, const std::string& message) override
		{
			LOG_ERROR("Error while parsing %s file, line %d, column %d, error: %s\n", filename.c_str(), line, column, message.c_str());
		}
	};

	void ProtoManager::LoadProtoDir(const std::string& dirPath)
	{
		const std::lock_guard<std::mutex> lock(_mutex);

		diskTree = std::shared_ptr<google::protobuf::compiler::DiskSourceTree>(new google::protobuf::compiler::DiskSourceTree());
		if (!dirPath.empty())
			diskTree->MapPath("", dirPath);

		auto errorCollector = new ErrorCollector();
		importer = std::shared_ptr<google::protobuf::compiler::Importer>(new google::protobuf::compiler::Importer(diskTree.get(), errorCollector));
		factory = std::shared_ptr<google::protobuf::DynamicMessageFactory>(new google::protobuf::DynamicMessageFactory(importer->pool()));
	}

	void ProtoManager::LoadIDFile(const std::string& filepath)
	{
		if (filepath.empty())
			return;
		
		const std::lock_guard<std::mutex> lock(_mutex);

		nameMap.clear();

		std::ifstream file;
		file.open(filepath);
		if (!file.is_open())
		{
			LOG_WARNING("Failed to load proto id file.");
			return;
		}
			
		auto content = nlohmann::json::parse(file);
		for (nlohmann::json::iterator it = content.begin(); it != content.end(); ++it)
		{
			auto id = std::stoi(it.key().c_str());
			nameMap[id] = it.value();
			idMap[it.value()] = id;
		}
		file.close();
	}

	google::protobuf::Message* ProtoManager::ParseMessage(const std::string& name, std::vector<byte> data)
	{
		const std::lock_guard<std::mutex> lock(_mutex);

		auto fileDescriptor = importer->Import(name + ".proto");
		if (fileDescriptor == nullptr || fileDescriptor->message_type_count() == 0)
			return nullptr;

		auto message = factory->GetPrototype(fileDescriptor->message_type(0))->New();

		std::string stringData((char*)data.data(), data.size());
		message->ParseFromString(stringData);
		return message;
	}

	ProtoManager::ProtoManager() {}
	
	void ProtoManager::Load(const std::string& idFilePath, const std::string& protoDir)
	{
		LoadIDFile(idFilePath);
		LoadProtoDir(protoDir);
	}

	std::optional <std::string> ProtoManager::GetJson(const std::string& name, std::vector<byte>& data)
	{
		auto message = ParseMessage(name, data);
		if (message == nullptr)
		{
			LOG_ERROR("Failed to parse message with name %s.", name.c_str());
			return {};
		}

		std::string jsonMessage = {};
		google::protobuf::util::MessageToJsonString(*message, &jsonMessage);

		delete message;

		return jsonMessage;
	}

	std::optional<std::string> ProtoManager::GetJson(uint32_t id, std::vector<byte>& data)
	{
		auto name = GetName(id);
		if (!name)
			return {};
		
		return GetJson(*name, data);
	}

	std::optional<std::string> ProtoManager::GetName(uint32_t id)
	{
		const std::lock_guard<std::mutex> lock(_mutex);

		if (nameMap.count(id) == 0)
		{
			LOG_WARNING("Failed to find proto with id %u", id);
			return {};
		}

		return nameMap[id];
	}

	uint16_t ProtoManager::GetId(const std::string& name)
	{
		return idMap.count(name) == 0 ? 0 : idMap[name];
	}

}