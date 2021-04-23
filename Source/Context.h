#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "Config.h"

struct Context {
    Context(const Config &config);

    sf::RenderWindow window;
};
