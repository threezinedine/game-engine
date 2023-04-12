#pragma once

#include "TTEngine/Core.hpp"
#include "Event.hpp"
#include "PrecompileHeader.hpp"


namespace TTEngine {
    class KeyEvent : public Event {
        public:
            inline int getKeyCode() { return keyCode; }
            EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

        protected:
            KeyEvent(int keyCode): keyCode(keyCode) {}

        private:
            int keyCode;
    };

    class KeyPressedEvent: public KeyEvent {
        public:
            KeyPressedEvent(int keyCode, int repeatCount):
                KeyEvent(keyCode), repeatCount(repeatCount) {}
            
            virtual std::string toString() override {
                std::stringstream ss;
                ss << getName() << ": " << getKeyCode() << " (" << repeatCount << " repeats)";
                return ss.str();
            }

            EVENT_CLASS_TYPE(KeyPressed)

        private:
            int repeatCount;
    };

    class KeyReleasedEvent: public KeyEvent {
        public:
            KeyReleasedEvent(int keyCode):
                KeyEvent(keyCode) {}

            virtual std::string toString() override {
                std::stringstream ss;
                ss << getName() << ": " << getKeyCode();
                return ss.str();
            }

            EVENT_CLASS_TYPE(KeyReleased)
    };
}