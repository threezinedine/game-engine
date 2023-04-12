#pragma once

#include "PrecompileHeader.hpp"
#include "TTEngine/Core.hpp"
#include "TTEngine/Window.hpp"
#include <GLFW/glfw3.h>


namespace TTEngine {
    class TTE_API WindowsWindow: public Window {
        public:
            WindowsWindow(const WindowProps props);
            ~WindowsWindow();

            virtual int getWidth() override { return m_data.width; }
            virtual int getHeight() override { return m_data.height; }

            virtual void setDispatcher(std::shared_ptr<EventDispatcher> dispatcher) override {
                this->dispatcher = dispatcher;
            }

            virtual void onUpdate() override;
            virtual void init() override;
            virtual void shutdown() override;

        struct WindowsData {
            int width;
            int height;
            std::string title;
        };

        private:
            std::shared_ptr<EventDispatcher> dispatcher;
            WindowsData m_data; 
            GLFWwindow* window;
    };
}