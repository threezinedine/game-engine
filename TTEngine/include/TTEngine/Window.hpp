#pragma once
#include "PrecompileHeader.hpp"
#include "TTEngine/Core.hpp"
#include "TTEngine/events/Event.hpp"


namespace TTEngine {
    class TTE_API Window {
        public:
            virtual int getWidth() = 0;
            virtual int getHeight() = 0;

            virtual void setEventCallback(const std::function<void(Event&)>& callback) = 0;
            virtual void onUpdate() = 0;
            virtual void init() = 0;
            virtual void shutdown() = 0;
    };
}