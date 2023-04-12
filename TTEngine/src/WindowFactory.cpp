#include "TTEngine/Window.hpp"
#include "TTEngine/platforms/WindowFactory.hpp"
#include "TTEngine/platforms/WindowsWindow.hpp"


namespace TTEngine {
    Window& createWindow(PlatformType type, WindowProps props) {
        switch (type) {
            case Windows:
                return *(new WindowsWindow(props));
            default:
                return *(new WindowsWindow(props));
        }
    }
}