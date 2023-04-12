#pragma once

#include "PrecompileHeader.hpp"
#include "Application.hpp"
#include "Logging.hpp"


#ifndef BUILD_DLL
namespace TTEngine {
    std::shared_ptr<Application> createApplication();
}

int main(int argc, char* argv[]) {
    TTEngine::Logging::init();
    TTE_CORE_INFO("Initialize Logging");
    std::shared_ptr<TTEngine::Application> app = TTEngine::createApplication();
    app->run();
    return 0;
}
#endif