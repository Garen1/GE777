#pragma 

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace GE777 
{

	class GE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;	

	};
}

//Core Log macros. by levels
#define GE_CORE_TRACE(...) ::GE777::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GE_CORE_INFO(...)  ::GE777::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GE_CORE_WARN(...)  ::GE777::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GE_CORE_ERROR(...) ::GE777::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GE_CORE_FATAL(...) ::GE777::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client macros. by levels
#define GE_TRACE(...) ::GE777::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GE_INFO(...)  ::GE777::Log::GetClientLogger()->info(__VA_ARGS__)
#define GE_WARN(...)  ::GE777::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GE_ERROR(...) ::GE777::Log::GetClientLogger()->error(__VA_ARGS__)
#define GE_FATAL(...) ::GE777::Log::GetClientLogger()->fatal(__VA_ARGS__)

