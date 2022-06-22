#include <pch.h>
#include "Logger.h"

#include <Windows.h>
#include <iostream>
#include <chrono>
#include <cstdarg>
#include <fstream>
#include <filesystem>

#include <cheat-base/util.h>

Logger::Level Logger::s_FileLogLevel = Logger::Level::None;
Logger::Level Logger::s_ConsoleLogLevel = Logger::Level::None;

std::string Logger::directory = "";
std::string Logger::logfilepath = "";
std::mutex Logger::_mutex{};

void Logger::SetLevel(Level level, LoggerType type)
{
	switch (type)
	{
	case Logger::LoggerType::Any:
		s_FileLogLevel = level;
		s_ConsoleLogLevel = level;
		break;
	case Logger::LoggerType::ConsoleLogger:
		s_ConsoleLogLevel = level;
		break;
	case Logger::LoggerType::FileLogger:
		s_FileLogLevel = level;
		break;
	default:
		break;
	}
}

Logger::Level Logger::GetLevel(Logger::LoggerType type)
{
	switch (type)
	{
	case Logger::LoggerType::Any:
		return s_FileLogLevel < s_ConsoleLogLevel ? s_FileLogLevel : s_ConsoleLogLevel;
	case Logger::LoggerType::ConsoleLogger:
		return s_ConsoleLogLevel;
	case Logger::LoggerType::FileLogger:
		return s_FileLogLevel;
	default:
		return Logger::Level::None;
	}
}

void LogToFile(std::string& filepath, std::string& msg) 
{
	std::ofstream myfile;
	myfile.open(filepath, std::ios::out | std::ios::app | std::ios::binary);
	myfile << msg << std::endl;
	myfile.close();
}

struct Prefix 
{
	char color;
	const char* text;
};

Prefix GetLevelPrefix(Logger::Level level) 
{
	switch (level)
	{
	case Logger::Level::Critical:
		return { 0x04, "Critical" };
	case Logger::Level::Error:
		return { 0x0C, "Error" };
	case Logger::Level::Warning:
		return { 0x06, "Warning" };
	case Logger::Level::Info:
		return { 0x02, "Info" };
	case Logger::Level::Debug:
		return { 0x0B, "Debug" };
	case Logger::Level::Trace:
		return { 0x08, "Trace" };
	default:
		return { 0x00, "" };
	}
} 

void Logger::Log(Logger::Level logLevel, const char* filepath, int line, const char* fmt, ...)
{
	char buffer[1024];

	va_list args;
	va_start(args, fmt);
	vsprintf_s(buffer, fmt, args);
	va_end(args);

	LogEvent(logLevel, filepath, line, buffer);
	if (Logger::s_ConsoleLogLevel == Logger::Level::None && Logger::s_FileLogLevel == Logger::Level::None)
		return;

	auto filename = std::filesystem::path(filepath).filename().string();
	auto prefix = GetLevelPrefix(logLevel);

	if (Logger::s_ConsoleLogLevel != Logger::Level::None && Logger::s_ConsoleLogLevel >= logLevel) 
	{
		const std::lock_guard<std::mutex> lock(_mutex);

		auto logLineConsole = util::string_format("[%s:%d] %s", filename.c_str(), line, buffer);
		std::cout << "[";

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, prefix.color);
		std::cout << prefix.text;
		SetConsoleTextAttribute(hConsole, 15);

		std::cout << "] " << logLineConsole << std::endl;
	}

	if (Logger::s_FileLogLevel != Logger::Level::None && Logger::s_FileLogLevel >= logLevel) 
	{
		const std::lock_guard<std::mutex> lock(_mutex);

		auto rawTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		struct tm gmtm;
		gmtime_s(&gmtm, &rawTime);
		auto logLineFile = util::string_format("[%02d:%02d:%02d] [%s] [%s:%d] %s", gmtm.tm_hour, gmtm.tm_min, gmtm.tm_sec, 
			prefix.text, filename.c_str(), line, buffer);
		LogToFile(Logger::logfilepath, logLineFile);
	}
}

void Logger::PrepareFileLogging(std::string directory)
{
	auto rawTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	struct tm gmtm;
	gmtime_s(&gmtm, &rawTime);

	Logger::directory = directory;
	if (!std::filesystem::is_directory(directory))
		std::filesystem::create_directories(directory);

	Logger::logfilepath = util::string_format("%s\\log_%04d-%02d-%02d_%02d-%02d.txt", directory.c_str(), 
		1900 + gmtm.tm_year, gmtm.tm_mon, gmtm.tm_mday, gmtm.tm_hour, gmtm.tm_min);
}