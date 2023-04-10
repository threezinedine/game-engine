#include "Core.hpp"


#define MAX_FRAMES 60


namespace TTEngine {
    class TTE_API Application {
        public:
            Application();
            ~Application();

            void run();
    };
}