#pragma once

#include "Core.hpp"
#include "PrecompileHeader.hpp"
#include "Window.hpp"
#include "events/Event.hpp"
#include "LayerStack.hpp"
#include "Layer.hpp"
#include "constants.hpp"


namespace TTEngine {
    class Window;
    class Event;
    class EventDispatcher;

    class TTE_API Application {
        public:
            Application();
            ~Application();
            virtual void run();
            void onEvent(Event& event);
            void onCloseWindow();

            void pushLayer(Layer* layer);
            void popLayer(Layer* layer);

        private:
            bool m_running = true;
            Window& m_window;
            std::shared_ptr<EventDispatcher> m_eventDispatcher;
            LayerStack m_layerStack;
    };
}