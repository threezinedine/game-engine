#include <TTEngine/TTEngine.hpp>
#include <iostream>
#include <memory>


class MyLayer : public TTEngine::Layer {
    public:
        MyLayer(const std::string& name): TTEngine::Layer(name) {
        }
        ~MyLayer() {
        }

        void onAttach() {

        }

        void onDetach() {

        }

        void onEvent(TTEngine::Event& event) {
            event.stopPropagation();
            TTE_CORE_INFO("[{1}] Event: {0}", event.toString(), getName());
        }

        void onUpdate() {
        }
};


class RacingApplication: public TTEngine::Application {
    public:
        RacingApplication(): TTEngine::Application() {
            std::string firstLayerTitle = "First Layer";
            std::string secondLayerTitle = "Second Layer";

            pushLayer(new MyLayer(firstLayerTitle));
            pushLayer(new MyLayer(secondLayerTitle));
        }
        ~RacingApplication() {
            TTEngine::Application::~Application();
        }
};


std::shared_ptr<TTEngine::Application> TTEngine::createApplication() {
    return std::make_shared<RacingApplication>();
}