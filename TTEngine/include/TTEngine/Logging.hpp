#pragma once

#include <spdlog/spdlog.h>
#include "PrecompileHeader.hpp"
#include "Core.hpp"


namespace TTEngine {
    class TTE_API Logging {
        private:
            static std::shared_ptr<spdlog::logger> coreLogger;
            static std::shared_ptr<spdlog::logger> clientLogger;
        public:
            static void init();
            inline static std::shared_ptr<spdlog::logger> getCoreLogger() { return coreLogger; }
            inline static std::shared_ptr<spdlog::logger> getClientLogger() { return clientLogger; }
    };
}

#define TTE_CORE_TRACE(...) ::TTEngine::Logging::getCoreLogger()->trace(__VA_ARGS__)
#define TTE_CORE_INFO(...) ::TTEngine::Logging::getCoreLogger()->info(__VA_ARGS__)
#define TTE_CORE_WARN(...) ::TTEngine::Logging::getCoreLogger()->warn(__VA_ARGS__)
#define TTE_CORE_ERROR(...) ::TTEngine::Logging::getCoreLogger()->error(__VA_ARGS__)

#define TTE_TRACE(...) ::TTEngine::Logging::getClientLogger()->trace(__VA_ARGS__)
#define TTE_INFO(...) ::TTEngine::Logging::getClientLogger()->info(__VA_ARGS__)
#define TTE_WARN(...) ::TTEngine::Logging::getClientLogger()->warn(__VA_ARGS__)
#define TTE_ERROR(...) ::TTEngine::Logging::getClientLogger()->error(__VA_ARGS__)