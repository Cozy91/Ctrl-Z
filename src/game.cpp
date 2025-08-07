#include "../headers/game.h"

#include <iostream>

using namespace std;  

Game::Game() {
    if (!backgroundtexture.loadFromFile("/home/cozy/Downloads/ChatGPT Image Aug 7, 2025, 03_38_41 PM.png")) {
        cout << "Failed to load background image!" << endl;
    }
    background.setTexture(backgroundtexture);

    window.create(sf::VideoMode(800, 600), "Ctrl+Z");
}

void Game::Run() {
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(background);
        window.display();
    }
}

