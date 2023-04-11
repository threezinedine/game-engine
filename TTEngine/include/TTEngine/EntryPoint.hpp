#pragma once

#include <memory>
#include "Application.hpp"

#ifndef BUILD_DLL
namespace TTEngine {
    std::shared_ptr<Application> createApplication();
}

int main(int argc, char* argv[]) {
    std::shared_ptr<TTEngine::Application> app = TTEngine::createApplication();
    app->run();
    return 0;
}
#endif