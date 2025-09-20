#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>

enum class GameState {
    MainMenu,
    Playing
};

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow window;
    GameState state;

    sf::Texture texture;
    sf::Sprite sprite;

    sf::Font font;
    sf::Text menuText;

    sf::CircleShape player;
};

#endif

