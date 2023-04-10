#include <TTEngine/TTEngine.hpp>
#include <iostream>
#include <memory>


int main(int argc, char* argv[]) {
    std::cout << "Hello World" << std::endl;
    std::shared_ptr<TTEngine::Application> app = std::make_shared<TTEngine::Application>();
    // app->run();
    return 0;
}