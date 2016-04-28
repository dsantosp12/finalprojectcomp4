#include "Universe.hpp"

void Universe::Universe::run() {
  unsigned int winWidth = 800, winHeight = 200;
  sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), "Solar");

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {

    }
    window.clear();
    window.display();
  }
}