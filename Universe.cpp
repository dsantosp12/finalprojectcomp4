#include "Universe.hpp"

const unsigned int numStars = 100;  ///< Number of stars
const unsigned int numBodies = 6;

Universe::Universe::Universe(int size, std::vector<Body*>& planetList)
  :winSize_(size) {
  // Seed for the random generators
  std::srand(time(0));

  // Create the window
  window_.create(sf::VideoMode(winSize_, winSize_), "Solar");

  // Generate the stars and bodies
  fetchStar();
  fetchBody();
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
    // Clear the windows
    window_.clear();

    // Draw the stars. Check draw stars for reference
    drawStars();
    drawBodies();

    // Draw everything in on the window
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
		starList_.push_back(Star(window_.getSize(), starList_));
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
  for (unsigned int i = 0; i < numBodies; i++) {
    Body* body = new Body(winSize_);
    bodyList_.push_back(body);
  }
}

/* **********************************
@ Implemented by Hung Q. Nguyen
@ Note:
  + 5/1: First time Implemented
* ***********************************/
void Universe::Universe::drawBodies() {
  std::vector<Body*>::iterator iter;
  for (iter = bodyList_.begin(); iter != bodyList_.end(); iter++) {
    window_.draw(*(*iter));
  }
}
