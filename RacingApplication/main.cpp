#include <TTEngine/TTEngine.hpp>
#include <iostream>
#include <memory>


std::shared_ptr<TTEngine::Application> TTEngine::createApplication() {
    return std::make_shared<TTEngine::Application>();
}