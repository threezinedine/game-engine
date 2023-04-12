#include <TTEngine/TTEngine.hpp>
#include <iostream>
#include <memory>
#include <TTEngine/events/Event.hpp>
#include <TTEngine/events/KeyEvent.hpp>


class RacingApplication: public TTEngine::Application {
    public:
        RacingApplication(): TTEngine::Application() {}
        ~RacingApplication() {
            TTEngine::Application::~Application();
        }
};


std::shared_ptr<TTEngine::Application> TTEngine::createApplication() {
    return std::make_shared<RacingApplication>();
}