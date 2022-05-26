#include <Windows.h>
#include <iostream>
#include <sstream>
#include <filesystem>

#include <SimpleIni.h>
#include <cheat-base/Logger.h>

#include "injector.h"
#include "util.h"

const std::string GlobalGenshinProcName = "GenshinImpact.exe";
const std::string ChinaGenshinProcName = "YuanShen.exe";

static CSimpleIni ini;

bool OpenGenshinProcess(HANDLE* phProcess, HANDLE* phThread);

int main(int argc, char* argv[])
{
    Logger::SetLevel(Logger::Level::Debug, Logger::LoggerType::ConsoleLogger);

    auto path = std::filesystem::path(argv[0]).parent_path();
    current_path(path);
    
    WaitForCloseProcess(GlobalGenshinProcName);
    WaitForCloseProcess(ChinaGenshinProcName);

    Sleep(1000); // Wait for unloading all dlls.

    ini.SetUnicode();
    ini.LoadFile("cfg.ini");

    HANDLE hProcess, hThread;
    if (!OpenGenshinProcess(&hProcess, &hThread))
    {
        std::cout << "Failed to open GenshinImpact process." << std::endl;
        return 1;
    }

    current_path(path);
    ini.SaveFile("cfg.ini");

    std::string filename = (argc == 2 ? argv[1] : "CLibrary.dll");
    std::filesystem::path currentDllPath = std::filesystem::current_path() / filename;

#ifdef _DEBUG
    std::filesystem::path tempDllPath = std::filesystem::temp_directory_path() / filename;

    std::error_code ec;
    std::filesystem::copy_file(currentDllPath, tempDllPath, std::filesystem::copy_options::update_existing, ec);
    if (ec)
    {
        LOG_ERROR("Copy dll failed: %s", ec.message().c_str());
        std::system("pause");
    }

    InjectDLL(hProcess, tempDllPath.string());
#else
    InjectDLL(hProcess, currentDllPath.string());
#endif

    Sleep(2000);
    ResumeThread(hThread);

    CloseHandle(hProcess);
}

bool OpenGenshinProcess(HANDLE *phProcess, HANDLE* phThread)
{
    STARTUPINFOA startInfo{};
    PROCESS_INFORMATION processInformation{};

    auto filePath = util::GetOrSelectPath(ini, "Inject", "GenshinPath", "genshin path", "Executable\0GenshinImpact.exe;YuanShen.exe\0");
    auto commandline = ini.GetValue("Inject", "GenshinCommandLine");

    LPSTR lpstr = commandline == nullptr ? nullptr : const_cast<LPSTR>(commandline);

    if (!filePath)
        return false;

    BOOL result = CreateProcessA(filePath->c_str(),
        lpstr, 0, 0, FALSE, CREATE_SUSPENDED, nullptr, nullptr, &startInfo, &processInformation);
    if (result == FALSE) 
    {
        LOG_LAST_ERROR("Failed to create game process.");
        LOG_ERROR("If you have problem with GenshinImpact.exe path. You can change it manually in cfg.ini.");
        return false;
    }

    ini.SaveFile("cfg.ini");

    *phThread = processInformation.hThread;
    *phProcess = processInformation.hProcess;
    return true;
}
