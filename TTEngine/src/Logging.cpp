#include "TTEngine/Logging.hpp"
#include <spdlog/sinks/stdout_color_sinks.h>


namespace TTEngine {
    std::shared_ptr<spdlog::logger> Logging::coreLogger;
    std::shared_ptr<spdlog::logger> Logging::clientLogger;

    void Logging::init() {
        spdlog::set_pattern("%^[%c] %n: %v%$");
        coreLogger = spdlog::stdout_color_mt("TTEngine");
        coreLogger->set_level(spdlog::level::trace);
        clientLogger = spdlog::stdout_color_mt("APP");
        clientLogger->set_level(spdlog::level::trace);
    }
}

