#include <iostream>
#include <memory>
#include <TTEngine/TTEngine.hpp>


class RacingApplication : public TTEngine::Application {
public:
    RacingApplication() {
        std::cout << "RacingApplication constructor" << std::endl;
    }
    ~RacingApplication() {
        std::cout << "RacingApplication destructor" << std::endl;
    }
};


int main(int argc, char* argv[]) {
    // TTEngine::Application* app = new RacingApplication();
    std::cout << MAX_FRAMES << std::endl;
    std::shared_ptr<TTEngine::Application> app = std::make_shared<RacingApplication>();
    // app->run();
    // delete app;
    return 0;
}