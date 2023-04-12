#pragma once
#include "PrecompileHeader.hpp"
#include "TTEngine/Core.hpp"
#include "TTEngine/events/Event.hpp"


namespace TTEngine {
    struct WindowProps {
        int height;
        int width;
        std::string title;
    };

    class TTE_API Window {
        public:
            virtual int getWidth() = 0;
            virtual int getHeight() = 0;

            virtual void setDispatcher(std::shared_ptr<EventDispatcher> dispatcher) = 0;
            virtual void onUpdate() = 0;
            virtual void init() = 0;
            virtual void shutdown() = 0;
    };
}