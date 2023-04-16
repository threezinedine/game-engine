#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "TTEngine/platforms/WindowsWindow.hpp"
#include "TTEngine/events/WindowEvent.hpp"
#include "TTEngine/events/KeyEvent.hpp"


namespace TTEngine {
    WindowsWindow::WindowsWindow(const WindowProps props) {
        m_data.width = props.width;
        m_data.height = props.height;
        m_data.title = props.title;
    }

    WindowsWindow::~WindowsWindow() {
        TTE_CORE_INFO("Destroying window");
        shutdown();
    }

    void WindowsWindow::shutdown() {
        glfwDestroyWindow(window);
    }

    void WindowsWindow::onUpdate() {
        glfwPollEvents();
    }

    void WindowsWindow::init() {
        TTE_CORE_INFO("Initialized Windows Window!");
        char* description;

        if (!glfwInit()) {
            TTE_CORE_ERROR("Failed to initialize GLFW!");
            return;
        }

        window = glfwCreateWindow(
                                m_data.width, 
                                m_data.height, 
                                m_data.title.c_str(), 
                                NULL, 
                                NULL
                            );

        gladLoadGL();

        if (!window) {
            TTE_CORE_ERROR("Failed to create GLFW window!");
            glfwTerminate();
            return;
        }

        dispatcher->dispatch(*(new WindowIntializeEvent()));

        glfwSetWindowUserPointer(window, this);

        glfwSetWindowCloseCallback(window, [](GLFWwindow* window) {
            WindowsWindow* instance = reinterpret_cast<WindowsWindow*>(glfwGetWindowUserPointer(window));
            WindowCloseEvent event;
            instance->dispatcher->dispatch(event);
        });

        glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
            WindowsWindow* instance = reinterpret_cast<WindowsWindow*>(glfwGetWindowUserPointer(window));

            switch (action) {
                case GLFW_PRESS: {
                    KeyPressedEvent event(key, 0);
                    instance->dispatcher->dispatch(event);
                    break;
                }
                case GLFW_RELEASE: {
                    KeyReleasedEvent event(key);
                    instance->dispatcher->dispatch(event);
                    break;
                }
                case GLFW_REPEAT:
                    KeyPressedEvent event(key, 1);
                    instance->dispatcher->dispatch(event);
                    break;
            }
        });
    }
}