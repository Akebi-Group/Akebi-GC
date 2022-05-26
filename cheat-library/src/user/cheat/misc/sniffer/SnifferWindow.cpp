#include "pch-il2cpp.h"
#include "SnifferWindow.h"
#include <imgui_internal.h>
#include <misc/cpp/imgui_stdlib.h>
#include <regex>

namespace sniffer
{
	SnifferWindow& SnifferWindow::GetInstance()
	{
		static SnifferWindow instance;
		return instance;
	}

	static auto nameCompare = [](const PacketInfo& a, const PacketInfo& b) { return a.name() < b.name(); };
	static auto sizeCompare = [](const PacketInfo& a, const PacketInfo& b) { return a.size() < b.size(); };
	static auto idCompare =   [](const PacketInfo& a, const PacketInfo& b) { return a.id() < b.id(); };
	static auto typeCompare = [](const PacketInfo& a, const PacketInfo& b) { return a.type() < b.type(); };
	static auto timeCompare = [](const PacketInfo& a, const PacketInfo& b) { return a.time() < b.time(); };

	void SnifferWindow::OnPacketIO(const PacketInfo& info)
	{
		const std::lock_guard<std::mutex> lock(m_CapturePacketLock);

		if (m_SortValue == SortValue::Time)
		{
			m_CapturedPackets.push_back(info);
			if (m_FilterGroup.Execute(info))
				m_CachedPackets.push_back(info);
			return;
		}

		switch (m_SortValue)
		{
		case sniffer::SnifferWindow::SortValue::Name:
			m_CapturedPackets.insert(std::lower_bound(m_CapturedPackets.begin(), m_CapturedPackets.end(), info, nameCompare), info);
			if (m_FilterGroup.Execute(info))
				m_CachedPackets.insert(std::lower_bound(m_CapturedPackets.begin(), m_CapturedPackets.end(), info, nameCompare), info);
			break;
		case sniffer::SnifferWindow::SortValue::Size:
			m_CapturedPackets.insert(std::lower_bound(m_CapturedPackets.begin(), m_CapturedPackets.end(), info, sizeCompare), info);
			if (m_FilterGroup.Execute(info))
				m_CachedPackets.insert(std::lower_bound(m_CapturedPackets.begin(), m_CapturedPackets.end(), info, nameCompare), info);
			break;
		case sniffer::SnifferWindow::SortValue::Id:
			m_CapturedPackets.insert(std::lower_bound(m_CapturedPackets.begin(), m_CapturedPackets.end(), info, idCompare), info);
			if (m_FilterGroup.Execute(info))
				m_CachedPackets.insert(std::lower_bound(m_CapturedPackets.begin(), m_CapturedPackets.end(), info, nameCompare), info);
			break;
		case sniffer::SnifferWindow::SortValue::Type:
			m_CapturedPackets.insert(std::lower_bound(m_CapturedPackets.begin(), m_CapturedPackets.end(), info, typeCompare), info);
			if (m_FilterGroup.Execute(info))
				m_CachedPackets.insert(std::lower_bound(m_CapturedPackets.begin(), m_CapturedPackets.end(), info, nameCompare), info);
			break;
		default:
			break;
		}
	}

#undef min
#undef max

	void SnifferWindow::Draw()
	{

		const std::lock_guard<std::mutex> lock(m_CapturePacketLock);

		bool showPrev = m_Show;
		bool windowShowed = ImGui::Begin("Packet sniffer", m_Show);
		
		if (showPrev != m_Show)
			m_Show.FireChanged();
		
		if (!windowShowed)
		{
			ImGui::End();
			return;
		}

		if (ComboEnum("## SortValue", &m_SortValue))
		{
			switch (m_SortValue)
			{
			case sniffer::SnifferWindow::SortValue::Name:
				m_CapturedPackets.sort(nameCompare);
				m_CachedPackets.sort(nameCompare);
				break;
			case sniffer::SnifferWindow::SortValue::Size:
				m_CapturedPackets.sort(sizeCompare);
				m_CachedPackets.sort(sizeCompare);
				break;
			case sniffer::SnifferWindow::SortValue::Id:
				m_CapturedPackets.sort(idCompare);
				m_CachedPackets.sort(idCompare);
				break;
			case sniffer::SnifferWindow::SortValue::Type:
				m_CapturedPackets.sort(typeCompare);
				m_CachedPackets.sort(typeCompare);
				break;
			case sniffer::SnifferWindow::SortValue::Time:
				m_CapturedPackets.sort(timeCompare);
				m_CachedPackets.sort(timeCompare);
				break;
			default:
				break;
			}
		}
		ImGui::SameLine();
		ComboEnum("Sort ## SortType", &m_SortType);

		m_FilterGroup.Draw(false);

		if (ImGui::Button("Apply filter"))
		{
			m_CachedPackets.clear();
			for (auto& info : m_CapturedPackets)
			{
				if (m_FilterGroup.Execute(info))
				{
					m_CachedPackets.push_back(info);
				}
			}
		}
		ImGui::SameLine();

		if (ImGui::Button("Clear history"))
		{
			m_CapturedPackets.clear();
			m_CachedPackets.clear();
		}

		ImGui::BeginChild("Packets");

		if (m_SortType == SortType::Asc)
		{
			for (auto& info : m_CachedPackets)
				info.Draw();
		}
		else
		{
			for (auto it = m_CachedPackets.rbegin(); it != m_CachedPackets.rend(); it++)
				it->Draw();
		}

		ImGui::EndChild();

		ImGui::End();
	}

	SnifferWindow::SnifferWindow() :
		NF(m_Show, "Show capturing window", "SnifferWindow", false),
		m_SortType(SortType::Desc),
		m_SortValue(SortValue::Time)
	{

	}

	bool Filter::Draw(bool canBeRemoved)
{
		ImGui::PushID(this);
		ComboEnum("## ObjectType", &m_ObjectType); ImGui::SameLine();
		ComboEnum("## CompareType", &m_CompareType); ImGui::SameLine();

		if (m_ObjectType != ObjectType::AnyValue)
		{
			ImGui::SetNextItemWidth(200);
			ImGui::InputText("## Key", &m_KeyPattern); ImGui::SameLine();
		}

		if (m_ObjectType == ObjectType::AnyValue || m_ObjectType == ObjectType::KeyValue)
		{
			ImGui::SetNextItemWidth(200);
			ImGui::InputText("## Value", &m_ObjectPattern); ImGui::SameLine();
		}

		bool removed = false;
		if (canBeRemoved && ImGui::Button("Remove"))
			removed = true;

		ImGui::PopID();
		return removed;
	}

	static std::vector<std::string> StringSplit(const std::string& delimiter, const std::string& content)
	{
		std::vector<std::string> tokens; 
		size_t pos = 0;
		size_t prevPos = 0;
		std::string token;
		while ((pos = content.find(delimiter, prevPos)) != std::string::npos) {
			token = content.substr(prevPos, pos - prevPos);
			tokens.push_back(token);
			prevPos = pos + delimiter.length();
		}
		tokens.push_back(content.substr(prevPos));
		return tokens;
	}

	static bool ApplyCompareString(const std::string& value, const std::string& pattern, Filter::CompareType compare)
	{
		std::string lowerValue = value;
		std::transform(lowerValue.begin(), lowerValue.end(), lowerValue.begin(),
			[](unsigned char c) { return std::tolower(c); });

		std::string lowerPattern = pattern;
		std::transform(lowerPattern.begin(), lowerPattern.end(), lowerPattern.begin(),
			[](unsigned char c) { return std::tolower(c); });

		switch (compare)
		{
		case sniffer::Filter::CompareType::Regex:
		{
			std::regex _regex(lowerPattern.c_str());
			return std::regex_match(lowerValue, _regex);
		}
		case sniffer::Filter::CompareType::Equal:
			return lowerValue == lowerPattern;
		case sniffer::Filter::CompareType::Contains:
			return lowerValue.find(lowerPattern) != std::string::npos;
		default:
			return false;
		}
	}

	template <typename T>
	static bool ApplyCompareAnyType(const nlohmann::json& object, const T& value, Filter::CompareType compare)
	{
		switch (compare)
		{
		case sniffer::Filter::CompareType::Equal:
			return object == value;
		case sniffer::Filter::CompareType::Less:
			return object < value;
		case sniffer::Filter::CompareType::LessEqual:
			return object <= value;
		case sniffer::Filter::CompareType::More:
			return object > value;
		case sniffer::Filter::CompareType::MoreEqual:
			return object >= value;
		default:
			return false;
		}
	}

	static bool ApplyCompareValue(const nlohmann::json& object, const std::string& pattern, Filter::CompareType compare)
	{
		if (object.is_string())
			return ApplyCompareString(object, pattern, compare);

		if (object.is_boolean())
		{
			if (compare != Filter::CompareType::Equal)
				return false;

			bool value = pattern == "true" || pattern == "1";
			return object == value;
		}

		if (!object.is_number())
			return false;

		if (object.is_number_float())
		{
			auto value = std::stof(pattern);
			return ApplyCompareAnyType(object, value, compare);
		}

		if (object.is_number_integer())
		{
			auto value = std::stoi(pattern);
			return ApplyCompareAnyType(object, value, compare);
		}

		if (object.is_number_unsigned())
		{
			auto value = std::stoul(pattern);
			return ApplyCompareAnyType(object, value, compare);
		}
		
		return false;
	}

	static bool HasValue(const nlohmann::json& object, const std::string& pattern, Filter::CompareType compare)
	{
		if (object.is_array())
		{
			for (auto& nested : object)
			{
				if (HasValue(nested, pattern, compare))
					return true;
			}
			return false;
		}


		if (object.is_object())
		{
			for (auto& item : object.items())
			{
				if (HasValue(item.value(), pattern, compare))
					return true;
			}
			return false;
		}

		return ApplyCompareValue(object, pattern, compare);
	}

	bool Filter::FindAnyValue(const sniffer::PacketInfo& info)
	{
		if (m_ObjectPattern.empty())
			return true;

		return HasValue(info.object(), m_ObjectPattern, m_CompareType);
	}

	bool Filter::FindAnyKey(const sniffer::PacketInfo& info)
	{
		if (m_KeyPattern.empty())
			return true;

		return !FindKeys(info, true).empty();
	}

	bool Filter::FindKeyValue(const sniffer::PacketInfo& info)
	{
		if (m_KeyPattern.empty())
			return true;

		auto objects = FindKeys(info);
		for (auto& obj : objects)
		{
			if (ApplyCompareValue(info.object(), m_ObjectPattern, m_CompareType))
				return true;
		}
		return false;
	}

	static std::vector<nlohmann::json> FindKey(const nlohmann::json& object, const std::string& pattern, Filter::CompareType compareType, bool onlyFirst, bool recursive)
	{
		std::vector<nlohmann::json> objects;

		if (object.is_array())
		{
			if (!recursive)
				return objects;

			for (auto& nested : object)
			{
				auto nestedResult = FindKey(nested, pattern, compareType, onlyFirst, recursive);
				if (nestedResult.size() > 0)
				{
					objects.insert(objects.end(), nestedResult.begin(), nestedResult.end());
					if (onlyFirst)
						return objects;
				}

			}
		}
		else if (object.is_object())
		{
			for (auto& item : object.items())
			{
				bool correct = ApplyCompareString(item.key(), pattern, compareType);
				if (!correct)
				{
					if (recursive)
					{
						auto nestedResult = FindKey(item.value(), pattern, compareType, onlyFirst, recursive);
						if (nestedResult.size() > 0)
						{
							objects.insert(objects.end(), nestedResult.begin(), nestedResult.end());
							if (onlyFirst)
								return objects;
						}
					}
					continue;
				}
					
				objects.push_back(item.value());
				if (onlyFirst)
					return objects;
			}
		}
		return objects;

	}

	std::vector<nlohmann::json> Filter::FindKeys(const sniffer::PacketInfo& info, bool onlyFirst)
	{
		auto equalType = m_ObjectType == ObjectType::KeyValue ? CompareType::Regex : m_CompareType;
		auto tokens = StringSplit("::", m_KeyPattern);

		std::string& mainToken = tokens[0];
		if (tokens.size() == 1) 
		{
			auto mainObjects = FindKey(info.object(), mainToken, equalType, onlyFirst, true);
			return mainObjects;
		}
		
		auto objects = FindKey(info.object(), m_KeyPattern, equalType, false, true);

		for (auto it = tokens.begin() + 1; it != tokens.end(); it++)
		{
			if (objects.empty())
				return {};

			bool last_token = (tokens.end() - 1) == it;
			bool _onlyFirst = onlyFirst && last_token;

			objects = FindKey(objects, *it, equalType, _onlyFirst, false);
		}

		return objects;
	}


	bool Filter::Execute(const sniffer::PacketInfo& info)
	{
		try 
		{
			switch (m_ObjectType)
			{
			case sniffer::Filter::ObjectType::KeyValue:
				return FindKeyValue(info);
			case sniffer::Filter::ObjectType::AnyKey:
				return FindAnyKey(info);
			case sniffer::Filter::ObjectType::AnyValue:
				return FindAnyValue(info);
			case sniffer::Filter::ObjectType::Name:
				return ApplyCompareString(info.name(), m_KeyPattern, m_CompareType);
			case sniffer::Filter::ObjectType::PacketId:
				return ApplyCompareString(std::to_string(info.id()), m_KeyPattern, m_CompareType);
			default:
				return true;
			}
		}
		catch (const std::regex_error& e)
		{
			UNREFERENCED_PARAMETER(e);
			return false;
		}
	}

	nlohmann::json Filter::Serialize()
	{
		return {};
	}

	Filter::Filter()
		: m_CompareType(CompareType::Equal),
		m_ObjectType(ObjectType::KeyValue)
	{

	}

	Filter::Filter(nlohmann::json& object)
		: Filter()
	{

	}

	bool FilterGroup::Draw(bool canBeRemoved)
{
		ImGui::PushID(this);
		
		bool removed = false;
		auto name = fmt::format("Group {}", magic_enum::enum_name(m_Rule));
		ImGui::BeginGroupPanel(name.c_str());
		{
			ComboEnum("Rule", &m_Rule);
			
			if (canBeRemoved)
			{
				ImGui::SameLine();
				if (ImGui::Button("Remove"))
					removed = true;
			}

			std::optional<IFilter*> removeFilter = {};
			for (auto& filter : m_Filters)
			{
				if (filter->Draw())
					removeFilter = filter;
			}

			if (removeFilter)
			{
				m_Filters.remove(*removeFilter);
				delete* removeFilter;
			}
			
			if (ImGui::Button("Add group", ImVec2(70, 0)))
				m_Filters.push_back(new FilterGroup());

			ImGui::SameLine();
			
			if (ImGui::Button("Add filter", ImVec2(70, 0)))
				m_Filters.push_back(new Filter());

		}
		ImGui::EndGroupPanel();

		ImGui::PopID();

		return removed;
	}


	bool FilterGroup::Execute(const sniffer::PacketInfo& info)
	{
		if (m_Filters.empty())
			return true;

		for (auto& filter : m_Filters)
		{
			bool result = filter->Execute(info);
			if (m_Rule == Rule::AND && !result)
				return false;

			if (m_Rule == Rule::NOT && result)
				return false;

			if (m_Rule == Rule::OR && result)
				return true;
		}
		return m_Rule != Rule::OR;
	}


	nlohmann::json FilterGroup::Serialize()
	{
		return {};
	}

	FilterGroup::FilterGroup() :
		m_Rule(Rule::AND),
		m_Filters()
	{

	}

	FilterGroup::FilterGroup(nlohmann::json& object) : FilterGroup()
	{
	}

}
