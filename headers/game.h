#pragma once

#include<SFML/Graphics.hpp>
class Game{
   public:
         Game();
         void Run();

   private:
   sf::RenderWindow window;
   sf::Event event;

};
