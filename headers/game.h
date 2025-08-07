#pragma once

#define SFML_ENABLE_COMPAT

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
class Game {
public:
    Game();
    void Run();
private:
    sf::Texture backgroundtexture;
    sf::Sprite  background;
    sf::RenderWindow window;
    sf::Event event;
};

