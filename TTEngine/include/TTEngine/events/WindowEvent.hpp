#pragma once

#include "PrecompileHeader.hpp"
#include "TTEngine/Core.hpp"
#include "Event.hpp"


namespace TTEngine {
    class TTE_API WindowEvent : public Event {
        public:
            EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class TTE_API WindowCloseEvent : public WindowEvent {
        public:
            EVENT_CLASS_TYPE(WindowClose)
            std::string toString() override {
                return getName();
            }
    };

    class TTE_API WindowIntializeEvent: public WindowEvent {
        public: 
            EVENT_CLASS_TYPE(WindowIntialize)
            std::string toString() override {
                return getName();
            }
    };
}