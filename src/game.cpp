#include "../headers/game.h"

#include <iostream>

using namespace std;  
void update();

Game::Game():circle(60.f) 
{
  

    window.create(sf::VideoMode(800, 600), "Ctrl+Z");
    window.setFramerateLimit(60);


circle.setOrigin(circle.getRadius(),circle.getRadius());    
circle.setPosition(window.getSize().x/2,window.getSize().y/2);
circle.setFillColor(sf::Color::Red);
}


void Game::Run() {
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
                if(event.type == sf::Event::KeyPressed && event.key.code==sf::Keyboard::Escape){
           window.close();
         }
        }
     
       update();
       draw();
    }
}
    
void Game::draw(){
  window.clear();
   window.draw(circle);
   window.display();
} 


void Game::update() {
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
        circle.getPosition().x - circle.getRadius() > 0) {
        circle.move(-0.5f, 0);
    }

  
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) &&
        circle.getPosition().x + circle.getRadius() < window.getSize().x) {
        circle.move(0.5f, 0);
    }

    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
        circle.getPosition().y + circle.getRadius() < window.getSize().y) {
        circle.move(0, 0.5f);
    }

    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
        circle.getPosition().y - circle.getRadius() > 0) {
        circle.move(0, -0.5f);
    }
}









