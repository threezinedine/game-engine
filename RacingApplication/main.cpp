#include <TTEngine/TTEngine.hpp>
#include <iostream>
#include <memory>


class RacingApplication: public TTEngine::Application {
    public:
        RacingApplication() {
            std::cout << "RacingApplication constructor" << std::endl;
        }

        ~RacingApplication() {
            std::cout << "RacingApplication destructor" << std::endl;
        }

        void run() override {
            std::cout << "RacingApplication run" << std::endl;
            TTEngine::KeyPressedEvent event(1, 2);
            TTEngine::KeyEvent& e = event;
            TTE_CORE_INFO("Event: {0}", e.getName());

            if (e.isInCategory(TTEngine::EventCategory::EventCategoryKeyboard)) {
                TTE_CORE_INFO("Event is in category EventCategoryKeyboard");
            } else {
                TTE_CORE_INFO("Event is not in category EventCategoryKeyboard");
            }
        }
};


std::shared_ptr<TTEngine::Application> TTEngine::createApplication() {
    return std::make_shared<RacingApplication>();
}