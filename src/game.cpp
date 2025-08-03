#include"../headers/game.h"

Game::Game(){

  window.create(sf::VideoMode(800,600),"Ctrl+Z");
}
  void Game::Run()
  {
    while (window.isOpen()){
      while(window.pollEvent(event))
        switch(event.type)
        {
          case sf::Event::Closed:
            window.close();
            break;
            default:
          break;
        }
    
    window.clear();
    window.display();
    }
  }
