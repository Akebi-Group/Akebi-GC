#pragma once
#include <string>
#include <mutex>
#include <cheat-base/events/event.hpp>

#define EXTLOG(level, fmt, ...) Logger::Log(level, __FILE__, __LINE__, fmt, __VA_ARGS__)
#define LOG_CRIT(fmt, ...) EXTLOG(Logger::Level::Critical, fmt, __VA_ARGS__)
#define LOG_ERROR(fmt, ...) EXTLOG(Logger::Level::Error, fmt, __VA_ARGS__)
#define LOG_WARNING(fmt, ...) EXTLOG(Logger::Level::Warning, fmt, __VA_ARGS__)
#define LOG_INFO(fmt, ...) EXTLOG(Logger::Level::Info, fmt, __VA_ARGS__)
#define LOG_DEBUG(fmt, ...) EXTLOG(Logger::Level::Debug, fmt, __VA_ARGS__)
#define LOG_TRACE(fmt, ...) EXTLOG(Logger::Level::Trace, fmt, __VA_ARGS__)

class Logger 
{
public:
	enum class Level 
	{
		None,
		Critical,
		Error,
		Warning,
		Info,
		Debug,
		Trace
	};

	enum class LoggerType 
	{
		Any,
		ConsoleLogger,
		FileLogger
	};

	static void SetLevel(Level level, LoggerType type = LoggerType::Any);
	static Level GetLevel(LoggerType type);

	static void Log(Level logLevel, const char* filename, int line, const char* fmt, ...);

	static void PrepareFileLogging(std::string directory);

	static inline TEvent<Logger::Level, const char*, int, const char*> LogEvent;

private:
	static Level s_FileLogLevel;
	static Level s_ConsoleLogLevel;

	static std::mutex _mutex;

	static std::string directory;
	static std::string logfilepath;
};