#pragma once
#include "TTEngine/Window.hpp"
#include "TTEngine/platforms/PlatformType.hpp"


namespace TTEngine {
    Window& createWindow(PlatformType type, WindowProps props); 
}