#include "Universe.hpp"

const unsigned int numStars = 200;  ///< Number of stars
const unsigned int numBodies = 6;

Universe::Universe::Universe(double rad, int size, std::vector<Body*>& planetList)
  :uni_rad(rad), winSize_(size) {
  // Seed for the random generators
  std::srand(time(0));


  // Create the window
  window_.create(sf::VideoMode(winSize_, winSize_), "Solar");
  window_.setFramerateLimit(30);
  // Generate the stars and bodies

  setUpTextAndDialog();
  fetchStar();
  bodyList_ = planetList;

  // transform the bodies
  transformBodies();
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

    // Update and draw the dialog
    checkClickOnSprite();
    updateDialog(selectedPlanet_);
    window_.draw(dialogBox_);
    window_.draw(dialogText_);
    window_.draw(textTime_);

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
  for (iter = bodyList_.begin(); iter != bodyList_.end(); ++iter) {
    window_.draw(*(*iter));
  }
}

/* **********************************
@ Implemented by Hung Q. Nguyen
@ Note:
  + 5/2: First time Implemented
* ***********************************/
void Universe::Universe::transformBodies() {
  // Get the actual percentage
  double per_pixel = (uni_rad * 2) / winSize_;

  // Get the original center coordinate (0,0) at the middle
  double x_org = winSize_ / 2;
  double y_org = winSize_ / 2;

  std::vector<Body*>::iterator iter;
  for (iter = bodyList_.begin(); iter != bodyList_.end(); ++iter) {
    sf::Vector2f initial = (*iter)->getInitScale();

    // Scale down
    double x_pos = initial.x / per_pixel;
    double y_pos = initial.y / per_pixel;

    // Appli old coordinate
    x_pos += x_org;
    y_pos += y_org;

    // Now set back the scale to the body
    (*iter)->setInitPosition(sf::Vector2f(x_pos, y_pos));
  }
}

/* **********************************
@ Implemented by Daniel Santos
@ Note:
* ***********************************/
void Universe::Universe::checkClickOnSprite() {
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
    std::vector<Body*>::iterator itr;
    sf::Sprite sprite;
    sf::Vector2i click_coordinates = sf::Mouse::getPosition(window_);

    for (itr = bodyList_.begin(); itr != bodyList_.end(); ++itr) {
      sprite = (*itr)->getSprite();
      if (sprite.getGlobalBounds().contains(sf::Vector2f(click_coordinates.x, click_coordinates.y))) {
        selectedPlanet_ = *itr;
      }
    }
  }
}

void Universe::Universe::setUpTextAndDialog() {
  sf::Vector2f dialog_size(400, 150);
  sf::Vector2f dialog_pos(window_.getSize().x-dialog_size.x,
                         window_.getSize().y-dialog_size.y);
  dialogBox_.setSize(dialog_size);
  dialogBox_.setPosition(dialog_pos);
  dialogBox_.setFillColor(sf::Color(255, 255, 255, 200));

  fontTime_.loadFromFile("nbody/fonts.otf");
  textTime_.setFont(fontTime_);
  textTime_.setString("0");
  dialogText_.setFont(fontTime_);
  dialogText_.setString("Click on a body");
  dialogText_.setColor(sf::Color::Black);
  // The number 10 is a litte padding for the text in the dialog
  dialogText_.setPosition(dialog_pos.x+10, dialog_pos.y);
}

void Universe::Universe::updateDialog(Body *planet) {
  if (planet != NULL) {
    sf::Vector2f position = planet->getLocation();
    sf::Vector2u velocity = planet->getVelocity();
    sf::Vector2u acce = planet->getAcceleration();
    std::stringstream ss;
    ss << std::setw(18)  << "Planet: " << planet->getPlanetName() << std::endl
        << std::setw(18) << "Position: (" << position.x << ", " << position.y << ")" << std::endl
        << std::setw(17) << "Velocity: (" << velocity.x << ", " << velocity.y << ")" << std::endl
        << "Acceleration: (" << acce.x << ", " << acce.y << ")" << std::endl;
    dialogText_.setString(ss.str());
  }
}
