#include <iostream>
#include "TTEngine/Application.hpp"


namespace TTEngine {
    Application::Application() {
        std::cout << "Application created! (TESTED)" << std::endl;
    }

    Application::~Application() {
        std::cout << "Application destroyed! (TESTED)" << std::endl;
    }

    void Application::run() {
        std::cout << "Application running!" << std::endl;
        while (true);
    }
}