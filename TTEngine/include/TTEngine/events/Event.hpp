#pragma once
#include "PrecompileHeader.hpp"
#include "TTEngine/TTEngine.hpp"


namespace TTEngine {
    enum class EventType {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved, WindowIntialize,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum EventCategory {
        None = 0,
        EventCategoryApplication = BIT(0),
        EventCategoryInput = BIT(1),
        EventCategoryKeyboard = BIT(2),
        EventCategoryMouse = BIT(3),
        EventCategoryMouseButton = BIT(4)
    };

#define EVENT_CLASS_TYPE(type) virtual EventType getEventType() override { return EventType::type; }\
                               virtual std::string getName() override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryValue() override { return category; }

    class Event {
        public:
            virtual EventType getEventType() = 0;
            virtual std::string getName() = 0;
            virtual std::string toString() = 0;
            virtual int getCategoryValue() = 0;

            inline bool isInCategory(EventCategory category) {
                return getCategoryValue() & category;
            }
    };

    class EventDispatcher {
        public:
            EventDispatcher() {
                TTE_CORE_INFO("Initializing dispatcher");
            }

            ~EventDispatcher() {
                TTE_CORE_INFO("Destructuring dispatcher");
            }

            void setOnEventCallback(std::function<void(Event&)> eventCallback) {
                TTE_CORE_TRACE("Set onEvent callback");
                m_eventCallback = eventCallback;
            }

            void dispatch(Event& event) {
                m_eventCallback(event);
            }
        private:
            std::function<void(Event&)> m_eventCallback;
    };
}