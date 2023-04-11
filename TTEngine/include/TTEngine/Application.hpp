#pragma once

#include "Core.hpp"
#include <iostream>


namespace TTEngine {
    class TTE_API Application {
        public:
            Application();
            ~Application();
            void run();
    };
}