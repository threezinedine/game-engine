#pragma once
#include "TTEngine/TTEngine.hpp"
#include "PrecompileHeader.hpp"


namespace TTEngine {
    enum class EventType {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
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
        friend class EventDispatcher;
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
            EventDispatcher(Event& event) : m_event(event) {}
            void dispatch(Event& event) {
                TTE_CORE_TRACE("Event: {0}", event.toString());
            }
        private:
            Event& m_event;
    };
}