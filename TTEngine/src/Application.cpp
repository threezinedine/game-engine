#include <iostream>
#include "TTEngine/Application.hpp"
#include "TTEngine/platforms/PlatformType.hpp"
#include "TTEngine/platforms/WindowFactory.hpp"
#include "TTEngine/Window.hpp"
#include "TTEngine/events/WindowEvent.hpp"
#include "TTEngine/events/Event.hpp"


namespace TTEngine {
    Application::Application():
        m_window(createWindow(Windows, WindowProps{
            DEFAULT_WINDOW_HEIGHT,
            DEFAULT_WINDOW_WIDTH,
            DEFAULT_WINDOW_TITLE
        })), m_eventDispatcher(std::make_shared<EventDispatcher>()) {
            m_eventDispatcher->setOnEventCallback([this](Event& event) {
                onEvent(event);
            });
            m_window.setDispatcher(m_eventDispatcher);
            m_window.init();
        }

    Application::~Application() {
    }

    void Application::onEvent(Event& event) {
        TTE_CORE_TRACE("Event: {0}", event.toString());
        switch(event.getEventType()) {
            case EventType::WindowClose:
                onCloseWindow();
                break;
        }

        m_layerStack.onEvent(event);
    }

    void Application::onCloseWindow() {
        m_running = false;
    }

    void Application::run() {
        while (m_running) {
            m_window.onUpdate();
            m_layerStack.onUpdate();
        };
    }

    void Application::pushLayer(Layer* layer) {
        m_layerStack.pushLayer(layer);
    }

    void Application::popLayer(Layer* layer) {
        m_layerStack.popLayer(layer);
    }
}