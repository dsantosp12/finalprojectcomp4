#include "Universe.hpp"

const unsigned int numStars = 100;  ///< Number of stars

Universe::Universe::Universe() {
  // Seed for the random generators
  std::srand(time(0));
  // Window properties
  winWidth_ = 800;
  winHeight_ = 600;
  window_.create(sf::VideoMode(winWidth_, winHeight_), "Solar");
  // Generate the stars
  fetchStar();
}

Universe::Universe::~Universe() {

}
/* **********************************
@ Implemented by Daniel Santos
@ Note:
* ***********************************/
void Universe::Universe::run() {
  while (window_.isOpen()) {
    sf::Event event;
    while (window_.pollEvent(event)) {
      switch (event.type) {
        case sf::Event::Closed:
          window_.close();
          break;
        default:
          break;
      }
    }
    window_.clear();

    // Draw the stars. Check draw stars for reference
    drawStars();

    window_.display();
  }
}

/* **********************************
@ Implemented by Hung Q. Nguyen & Daniel Santos
@ Note:
	+ 4/30: First time Implemented
  + 5/01: Modified the method
* ***********************************/
void Universe::Universe::fetchStar() {
  // Instanciate Stars and push it to starList
  for (unsigned int i = 0; i < numStars; i++)
		starList_.push_back(Star(window_.getSize()));
}

/* **********************************
@ Implemented by Daniel Santos
@ Note:
    + 5/01: Implemented the method
* ***********************************/
void Universe::Universe::drawStars() {
  for (unsigned int i = 0; i < starList_.size(); i++)
    window_.draw(starList_.at(i));  // Draw the stars
}

/* **********************************
@ Implemented by Hung Q. Nguyen
@ Note:
	+ 4/30: First time Implemented
* ***********************************/
void Universe::Universe::fetchBody() {

}
