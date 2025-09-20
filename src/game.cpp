#include "game.h"

Game::Game()
    : window(sf::VideoMode(800,600), "SFML Game"),
      state(GameState::MainMenu)
{
    if (!font.openFromFile("arial.ttf"))
        std::cerr << "Font missing\n";

    if (!playerTexture.loadFromFile("player.png"))
        std::cerr << "Player texture missing\n";

    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition({400.f, 300.f});

    menuText.setFont(font);
    menuText.setString("Press Enter to Play");
    menuText.setCharacterSize(50);

    sf::Vector2f textCenter = {
        menuText.getLocalBounds().width / 2.f,
        menuText.getLocalBounds().height / 2.f
    };
    menuText.setOrigin(textCenter);
    menuText.setPosition({400.f, 300.f});
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    while (auto eventOpt = window.pollEvent()) {
        auto event = *eventOpt;

        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Key::Escape)
                window.close();

            if (event.key.code == sf::Key::Enter && state == GameState::MainMenu)
                state = GameState::Playing;
        }
    }
}

void Game::update() {
    if (state == GameState::Playing) {
        sf::Vector2f move{0.f, 0.f};
        if (sf::Keyboard::isKeyPressed(sf::Key::A)) move.x -= 0.5f;
        if (sf::Keyboard::isKeyPressed(sf::Key::D)) move.x += 0.5f;
        if (sf::Keyboard::isKeyPressed(sf::Key::W)) move.y -= 0.5f;
        if (sf::Keyboard::isKeyPressed(sf::Key::S)) move.y += 0.5f;

        playerSprite.move(move);
    }
}

void Game::render() {
    window.clear();
    if (state == GameState::MainMenu)
        window.draw(menuText);
    else if (state == GameState::Playing)
        window.draw(playerSprite);
    window.display();
}

