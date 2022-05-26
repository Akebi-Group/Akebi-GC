#include "pch-il2cpp.h"
#include "PacketInfo.h"

#include <misc/cpp/imgui_stdlib.h>

namespace sniffer
{
	PacketInfo::PacketInfo(PacketData packetData)
		: m_Data(packetData),
		m_JObject(nlohmann::json::parse(packetData.messageJson)),
		m_Time(util::GetCurrentTimeMillisec()),
		m_DrawBeauty(false)
	{

	}

	PacketIOType PacketInfo::type() const
	{
		return m_Data.ioType;
	}

	uint32_t PacketInfo::id() const
	{
		return m_Data.messageID;
	}

	size_t PacketInfo::size() const
	{
		return m_Data.messageRawData.size();
	}

	int64_t PacketInfo::time() const
	{
		return m_Time;
	}

	std::string PacketInfo::name() const
	{
		return m_Data.name;
	}

	nlohmann::json PacketInfo::object() const
	{
		return m_JObject;
	}

	void DrawPrimitive(const std::string& key, nlohmann::json& jsonPrimitive)
	{
		if (jsonPrimitive.is_boolean())
		{
			bool primitive = jsonPrimitive;
			ImGui::Checkbox(key.c_str(), &primitive);
		}
		else if (jsonPrimitive.is_number_integer() || jsonPrimitive.is_number_unsigned())
		{
			int primitive = jsonPrimitive;
			ImGui::InputInt(key.c_str(), &primitive);
		}
		else if (jsonPrimitive.is_number_float())
		{
			float primitive = jsonPrimitive;
			ImGui::InputFloat(key.c_str(), &primitive);
		}
		else if (jsonPrimitive.is_string())
		{
			std::string primitive = jsonPrimitive;
			ImGui::InputText(key.c_str(), &primitive);
		}
		else if (jsonPrimitive.is_null())
		{
			ImGui::Text("%s: <null>", key.c_str());
		}
	}

	void DrawObject(const std::string& key, nlohmann::json& jsonObject);

	void DrawArray(const std::string& key, nlohmann::json& jsonArray)
	{
		ImGui::PushID(key.c_str());

		if (ImGui::TreeNode(key.c_str()))
		{
			int i = 0;
			for (auto& el : jsonArray)
			{
				DrawObject(std::to_string(i), el);
				i++;
			}
			ImGui::TreePop();
		}

		ImGui::PopID();
	}

	void DrawObject(const std::string& key, nlohmann::json& jsonObject)
	{
		if (jsonObject.is_array())
			DrawArray(key, jsonObject);
		else if (jsonObject.is_primitive())
			DrawPrimitive(key, jsonObject);
		else
		{
			ImGui::PushID(key.c_str());

			if (ImGui::TreeNode(key.c_str()))
			{
				for (auto& el : jsonObject.items())
					DrawObject(el.key(), el.value());

				ImGui::TreePop();
			}

			ImGui::PopID();
		}
	}

	void PacketInfo::Draw()
	{
		ImGui::PushID(this);

		if (m_Header.empty())
			m_Header = fmt::format("[{}] {} | {}. Size: {}", magic_enum::enum_name(type()), id(), name(), size());

		if (ImGui::TreeNode(m_Header.c_str()))
		{
			if (ImGui::Checkbox("## Beauty", &m_DrawBeauty) && m_DrawBeauty && m_JsonMessageBeauty.empty())
			{
				m_JsonMessageBeauty = m_JObject.dump(2);
			}
			ImGui::SameLine();

			if (m_DrawBeauty)
				ImGui::InputTextMultiline("JSON Message", &m_JsonMessageBeauty);
			else
				ImGui::InputText("JSON Message", &m_Data.messageJson);


			DrawObject("Data", m_JObject);
			ImGui::TreePop();
		}

		ImGui::PopID();
	}
}

