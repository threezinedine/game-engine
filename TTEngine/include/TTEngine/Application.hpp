#pragma once

#include "Core.hpp"
#include "PrecompileHeader.hpp"


namespace TTEngine {
    class TTE_API Application {
        public:
            Application();
            ~Application();
            virtual void run();
    };
}