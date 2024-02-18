#include <glad/glad.h>
#include "engine.h"

Engine::Engine()
{
    std::cout << "Engine constructor" << std::endl;
}

Engine::~Engine()
{
    std::cout << "Engine destructor" << std::endl;
}

void Engine::init()
{
    std::cout << "Engine init" << std::endl;
}

void Engine::display()
{
    std::cout << "Engine display" << std::endl;
}
