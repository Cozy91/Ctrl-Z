#pragma once
#include<SFML/graphics.hpp>

#define MAX_NUMBER_OF_ITEMS 3

class Menu{
  public:
    Menu(float width,float height);
    ~Menu;

    void (sf::RenderWindow &window);
    void Moveup();
    void Movedown();
  private:
    int selectedoption;
    sf::Text text[MAX_NUMBER_OF_ITEMS];
};
