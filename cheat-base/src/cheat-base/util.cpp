#include <pch.h>
#include <framework.h>
#include "util.h"

#include <Windows.h>
#include <commdlg.h>
#include <shtypes.h>
#include <shobjidl_core.h>
#include <shlobj_core.h>

#include <sstream>
#include <string>
#include <iomanip>
#include <codecvt>
#include <filesystem>

namespace util
{

    std::string GetLastErrorAsString(DWORD errorId /*= 0*/)
	{
        //Get the error message ID, if any.
        DWORD errorMessageID = errorId == 0 ? ::GetLastError() : errorId;
        if (errorMessageID == 0)
        {
            return std::string(); //No error message has been recorded
        }

        LPSTR messageBuffer = nullptr;

        //Ask Win32 to give us the string version of that message ID.
        //The parameters we pass in, tell Win32 to create the buffer that holds the message for us (because we don't yet know how long the message string will be).
        size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
            NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

        //Copy the error message into a std::string.
        std::string message(messageBuffer, size);

        //Free the Win32's string's buffer.
        LocalFree(messageBuffer);

        return message;
    }

    std::string to_hex_string(uint8_t* barray, int length)
    {
        if (barray == nullptr || length == 0)
            return std::string();

        std::stringstream stream;
        for (size_t i = 0; i < length; i++)
            stream << std::setfill('0') << std::setw(2) << std::hex << (int)barray[i];

        return stream.str();
    }

	bool IsLittleEndian()
	{
		unsigned int i = 1;
		char* c = (char*)&i;
		return (*c);
	}

	std::optional<std::string> SelectDirectory(const char* title)
    {
        auto currPath = std::filesystem::current_path();

        if (!SUCCEEDED(CoInitialize(nullptr)))
            return {};

        IFileDialog* pfd;
        if (!SUCCEEDED(CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pfd))))
            return {};

        const size_t titleSize = strlen(title) + 1;
        wchar_t* wcTitle = new wchar_t[titleSize];
        mbstowcs(wcTitle, title, titleSize);

        DWORD dwOptions;
        IShellItem* psi;
        if (!SUCCEEDED(pfd->GetOptions(&dwOptions)) ||
            !SUCCEEDED(pfd->SetOptions(dwOptions | FOS_PICKFOLDERS)) ||
            !SUCCEEDED(pfd->SetTitle(wcTitle)) ||
            !SUCCEEDED(pfd->Show(NULL)) ||
            !SUCCEEDED(pfd->GetResult(&psi)))
        {
            pfd->Release();
            return {};
        }

        WCHAR* folderName;
        if (!SUCCEEDED(psi->GetDisplayName(SIGDN_DESKTOPABSOLUTEPARSING, &folderName)))
        {
            pfd->Release();
            psi->Release();
            return {};
        }

        pfd->Release();
        psi->Release();

        std::filesystem::current_path(currPath);

        std::u16string u16(reinterpret_cast<const char16_t*>(folderName));
        return std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t>{}.to_bytes(u16);
    }

    std::optional<std::string> SelectFile(const char* filter, const char* title)
    {
        auto currPath = std::filesystem::current_path();

        // common dialog box structure, setting all fields to 0 is important
        OPENFILENAME ofn = { 0 };
        TCHAR szFile[260] = { 0 };

        // Initialize remaining fields of OPENFILENAME structure
        ofn.lStructSize = sizeof(ofn);
        ofn.hwndOwner = NULL;
        ofn.lpstrFile = szFile;
        ofn.nMaxFile = sizeof(szFile);
        ofn.lpstrFilter = filter;
        ofn.lpstrTitle = title;
        ofn.nFilterIndex = 1;
        ofn.lpstrFileTitle = NULL;
        ofn.nMaxFileTitle = 0;
        ofn.lpstrInitialDir = NULL;
        ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

        std::optional<std::string> result = {};
        if (GetOpenFileName(&ofn) == TRUE)
            result = std::string(szFile);

        std::filesystem::current_path(currPath);
        return result;
    }

    std::optional<std::string> GetOrSelectPath(CSimpleIni& ini, const char* section, const char* name, const char* friendName, const char* filter)
    {
        auto savedPath = ini.GetValue(section, name);
        if (savedPath != nullptr)
            return std::string(savedPath);

        LOG_DEBUG("%s path not found. Please point to it manually.", friendName);

        auto titleStr = string_format("Select %s", friendName);
        auto selectedPath = filter == nullptr ? SelectDirectory(titleStr.c_str()) : SelectFile(filter, titleStr.c_str());
        if (!selectedPath)
            return {};

        ini.SetValue(section, name, selectedPath->c_str());
        return selectedPath;
    }
	
	int64_t GetCurrentTimeMillisec()
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	}

	std::vector<std::string> StringSplit(const std::string& delimiter, const std::string& content)
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

	static const std::string base64_chars =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"0123456789+/";

	static inline bool is_base64(BYTE c) {
		return (isalnum(c) || (c == '+') || (c == '/'));
	}

	std::string base64_encode(BYTE const* buf, unsigned int bufLen) {
		std::string ret;
		int i = 0;
		int j = 0;
		BYTE char_array_3[3];
		BYTE char_array_4[4];

		while (bufLen--) {
			char_array_3[i++] = *(buf++);
			if (i == 3) {
				char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
				char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
				char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
				char_array_4[3] = char_array_3[2] & 0x3f;

				for (i = 0; (i < 4); i++)
					ret += base64_chars[char_array_4[i]];
				i = 0;
			}
		}

		if (i)
		{
			for (j = i; j < 3; j++)
				char_array_3[j] = '\0';

			char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
			char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
			char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
			char_array_4[3] = char_array_3[2] & 0x3f;

			for (j = 0; (j < i + 1); j++)
				ret += base64_chars[char_array_4[j]];

			while ((i++ < 3))
				ret += '=';
		}

		return ret;
	}

	std::vector<BYTE> base64_decode(std::string const& encoded_string) {
		size_t in_len = encoded_string.size();
		int i = 0;
		int j = 0;
		int in_ = 0;
		BYTE char_array_4[4], char_array_3[3];
		std::vector<BYTE> ret;

		while (in_len-- && (encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
			char_array_4[i++] = encoded_string[in_]; in_++;
			if (i == 4) {
				for (i = 0; i < 4; i++)
					char_array_4[i] = static_cast<BYTE>(base64_chars.find(char_array_4[i])); // base64_chars len < 255

				char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
				char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
				char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

				for (i = 0; (i < 3); i++)
					ret.push_back(char_array_3[i]);
				i = 0;
			}
		}

		if (i) {
			for (j = i; j < 4; j++)
				char_array_4[j] = 0;

			for (j = 0; j < 4; j++)
				char_array_4[j] = static_cast<BYTE>(base64_chars.find(char_array_4[j]));

			char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
			char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
			char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

			for (j = 0; (j < i - 1); j++) ret.push_back(char_array_3[j]);
		}

		return ret;
	}

	int64_t GetTimezoneBias()
	{
		_TIME_ZONE_INFORMATION timezoneInfo{};
		if (GetTimeZoneInformation(&timezoneInfo) == TIME_ZONE_ID_INVALID)
			LOG_LAST_ERROR("Failed to get timezone.");

		return static_cast<int64_t>(timezoneInfo.Bias) * 60;
	}
}