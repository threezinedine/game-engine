#include <iostream>
#include "TTEngine/Application.hpp"


namespace TTEngine {
    Application::Application() {
        std::cout << "Application created!" << std::endl;
    }

    Application::~Application() {
        std::cout << "Application destroyed!" << std::endl;
    }

    void Application::run() {
        std::cout << "Application running!" << std::endl;
    }
}