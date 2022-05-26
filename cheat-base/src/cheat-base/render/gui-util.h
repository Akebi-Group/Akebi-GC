#pragma once

#include <imgui.h>
#include <filesystem>
#include <cheat-base/config/config.h>
#include <cheat-base/Hotkey.h>
#include <cheat-base/config/fields/Toggle.h>
#include <cheat-base/config/fields/Enum.h>

#define BLOCK_FOCUS() 

bool TypeWidget(const char* label, bool& value, const char* desc = nullptr);
bool TypeWidget(const char* label, int& value, int step = 1, int start = 0, int end = 0, const char* desc = nullptr);
bool TypeWidget(const char* label, float& value, float step = 1.0F, float start = 0, float end = 0, const char* desc = nullptr);
bool TypeWidget(const char* label, Hotkey& value, bool clearable = true, const char* desc = nullptr);
bool TypeWidget(const char* label, std::string& value, const char* desc = nullptr);
bool TypeWidget(const char* label, ImColor& value, const char* desc = nullptr);
bool TypeWidget(const char* label, config::Toggle<Hotkey>& value, const char* desc = nullptr, bool hotkey = false);

bool ConfigWidget(const char* label, config::Field<bool>& field, const char* desc = nullptr);
bool ConfigWidget(const char* label, config::Field<int>& field, int step = 1, int start = 0, int end = 0, const char* desc = nullptr);
bool ConfigWidget(const char* label, config::Field<float>& field, float step = 1.0F, float start = 0, float end = 0, const char* desc = nullptr);
bool ConfigWidget(const char* label, config::Field<Hotkey>& field, bool clearable = true, const char* desc = nullptr);
bool ConfigWidget(const char* label, config::Field<std::string>& field, const char* desc = nullptr);
bool ConfigWidget(const char* label, config::Field<ImColor>& field, const char* desc = nullptr);

template<typename T>
bool ConfigWidget(const char* label, config::Field<config::Toggle<T>>& field, const char* desc = nullptr)
{
	ImGui::PushID(&field);
	bool result = TypeWidget("", field.value().enabled);
	ImGui::SameLine();
	result |= TypeWidget(label, field.value().value, desc);
	ImGui::PopID();
	if (result)
		field.FireChanged();

	return result;
}
bool ConfigWidget(const char* label, config::Field<config::Toggle<float>>& field, float step = 1.0F, float start = 0, float end = 0, const char* desc = nullptr, bool hotkey = false);
bool ConfigWidget(const char* label, config::Field<config::Toggle<Hotkey>>& field, const char* desc = nullptr, bool hotkey = false);

bool ConfigWidget(config::Field<bool>& field, const char* desc = nullptr);
bool ConfigWidget(config::Field<int>& field, int step = 1, int start = 0, int end = 0, const char* desc = nullptr);
bool ConfigWidget(config::Field<float>& field, float step = 1.0F, float start = 0, float end = 0, const char* desc = nullptr);
bool ConfigWidget(config::Field<Hotkey>& field, bool clearable = true, const char* desc = nullptr);
bool ConfigWidget(config::Field<std::string>& field, const char* desc = nullptr);
bool ConfigWidget(config::Field<ImColor>& field, const char* desc = nullptr);

template<typename T>
bool ConfigWidget(config::Field<config::Toggle<T>>& field, const char* desc = nullptr)
{
	return ConfigWidget(field.friendName().c_str(), field, desc);
}

bool ConfigWidget(config::Field<config::Toggle<float>>& field, float step = 1.0F, float start = 0, float end = 0, const char* desc = nullptr);
bool ConfigWidget(config::Field<config::Toggle<Hotkey>>& field, const char* desc = nullptr, bool hotkey = false);

void ShowHelpText(const char* text);
void HelpMarker(const char* desc);

bool InputHotkey(const char* label, Hotkey* hotkey, bool clearable);

// Thanks to https://gist.github.com/dougbinks/ef0962ef6ebe2cadae76c4e9f0586c69
void AddUnderLine(ImColor col_);
void TextURL(const char* name_, const char* URL_, bool SameLineBefore_, bool SameLineAfter_);

enum class OutlineSide : uint32_t
{
	Left = 1,
	Right = 2,
	Top = 4,
	Bottom = 8,
	All = Left | Right | Top | Bottom
};

bool operator&(OutlineSide lhs, OutlineSide rhs);

void DrawTextWithOutline(ImDrawList* drawList, ImFont* font, float fontSize, const ImVec2& screenPos, const char* text, const ImColor& textColor, 
	float outlineThickness = 0.0f, OutlineSide sides = OutlineSide::All, const ImColor& outlineColor = ImColor(0.0f, 0.0f, 0.0f));
void DrawTextWithOutline(ImDrawList* drawList, const ImVec2& screenPos, const char* text, const ImColor& textColor, 
	float outlineThickness = 0.0f, OutlineSide sides = OutlineSide::All, const ImColor& outlineColor = ImColor(0.0f, 0.0f, 0.0f));

namespace ImGui
{
	bool HotkeyWidget(const char* label, Hotkey& hotkey, const ImVec2& size = ImVec2(0, 0));

	float CalcContrastRatio(const ImU32& backgroundColor, const ImU32& foreGroundColor);
	ImColor CalcContrastColor(const ImColor& foreground, float maxContrastRatio = 2.0f, const ImColor& background = ImColor(1.0f, 1.0f, 1.0f), const ImColor& inverted = ImColor(0.0f, 0.0f, 0.0f));
	bool PushStyleColorWithContrast(ImU32 backGroundColor, ImGuiCol foreGroundColor, ImU32 invertedColor, float maxContrastRatio);

	void OpenRenamePopup(const std::string& initName);
	bool IsRenamePopupOpened();
	bool DrawRenamePopup(std::string& out);

	bool BeginGroupPanel(const char* label, bool node = false, const ImVec2& size = ImVec2(-1.0f, 0.0f));
	void EndGroupPanel();

	bool BeginSelectableGroupPanel(const char* label, bool& value, bool& changed, bool node = false, const ImVec2& size = ImVec2(-1.0f, 0.0f), const char* selectLabel = "Select");
	void EndSelectableGroupPanel();

	void NextGroupPanelHeaderItem(const ImVec2& size, bool rightAlign = false);

	ImVec2 CalcButtonSize(const char* label);
}

float CalcWidth(const std::string_view& view);

template <typename T>
float GetMaxEnumWidth()
{
	constexpr auto names = magic_enum::enum_names<T>();
	auto maxComboName = std::max_element(names.begin(), names.end(),
		[](const auto& a, const auto& b) { return CalcWidth(a) < CalcWidth(b); });
	return CalcWidth(*maxComboName);
}

template <typename T>
bool ComboEnum(const char* label, T* currentValue, std::vector<T>* whitelist = nullptr)
{
	auto name = magic_enum::enum_name(*currentValue);
	auto& current = *currentValue;
	bool result = false;
	static auto width = GetMaxEnumWidth<T>();

	std::unordered_set<T> whiteSet;
	if (whitelist != nullptr)
	{
		for (auto& value : *whitelist)
		{
			whiteSet.insert(value);
		}
	}
	ImGui::SetNextItemWidth(width);
	if (ImGui::BeginCombo(label, name.data()))
	{
		for (auto& entry : magic_enum::enum_entries<T>())
		{
			if (whitelist != nullptr && whiteSet.count(entry.first) == 0)
				continue;

			bool is_selected = (name == entry.second);
			if (ImGui::Selectable(entry.second.data(), is_selected))
			{
				current = entry.first;
				result = true;
			}
			if (is_selected)
				ImGui::SetItemDefaultFocus();
		}
		ImGui::EndCombo();
	}
	return result;
}

template <typename T>
bool ConfigWidget(const char* label, config::Field<config::Enum<T>>& field, const char* desc = nullptr)
{
	bool result = false;
	if (ComboEnum(label, &field.value()))
	{
		field.FireChanged();
		result = true;
	}
	
	if (desc != nullptr) { ImGui::SameLine(); HelpMarker(desc); };
	return result;
}

template <typename T>
bool ConfigWidget(config::Field<config::Enum<T>>& field, const char* desc = nullptr)
{
	return ConfigWidget(field.friendName().c_str(), field, desc);
}