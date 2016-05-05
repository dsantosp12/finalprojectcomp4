/** Copyright 2015 Daniel Santos & Hung Nguyen
*  @file     Universe.cpp
*  @author   Daniel Santos & Hung Nguyen
*  @date     05/3/2016
*  @version  1.0
*
*  @brief    This file contains the implementation
 * of the Universe object.
* */

#include <vector>
#include "Universe.hpp"

const unsigned int numStars = 200;  ///< Number of stars
const unsigned int numBodies = 6;

Universe::Universe::Universe(double rad, int size,
                             std::vector<Body*>& planetList)
  :winSize_(size), uni_rad(rad) {
  if (rad <= 0 || size <= 0) {
    throw std::invalid_argument("Invalid Parameter(s)");
    return;
  }
  // Seed for the random generators
  std::srand(time(0));

  // Create the window
  window_.create(sf::VideoMode(winSize_, winSize_), "SOLAR SYSTEM (Hung Nguyen & Daniel Santos)");
  window_.setFramerateLimit(30);
  ship_ = new SpaceShip(window_.getSize());
  setUpTextAndDialog();
  elapsedTime_ = 0;

  music_.openFromFile("res/background_music.wav");
  music_.play();

  // Generate the stars
  fetchStar();
  bodyList_ = planetList;
}

Universe::Universe::~Universe() {
}

/* **********************************
@ Implemented by Daniel Santos & Hung Q Nguyen
@ Note:
* ***********************************/
void Universe::Universe::run() {
  while (window_.isOpen() && elapsedTime_ < uni_total_times) {
    sf::Event event;
    while (window_.pollEvent(event)) {
      switch (event.type) {
        case sf::Event::Closed:
          window_.close();
          break;
        case sf::Event::KeyPressed:
          shipMove(event.key);
          break;
        default:
          break;
      }
    }
    window_.clear();
    // Update and draw
    checkClickOnSprite();
    updateDialog(selectedPlanet_);
    updateUniverse();
    window_.draw(dialogBox_);
    window_.draw(dialogText_);
    window_.draw(textTime_);
    drawStars();
    window_.draw(*ship_);
    window_.display();

    // Update current
    updateTime(step_time);
  }
  printState();
}

void Universe::Universe::updateUniverse() {
  // Get the current body
  std::vector<Body*>::iterator first_it;
  for (first_it = bodyList_.begin(); first_it != bodyList_.end(); ++first_it) {
    // get the default properties
    double m1 = (*first_it)->getMass();

    // Inital at rest, force = 0
    double x_force = 0, y_force = 0;
    double x_accel, y_accel;

    // contact this planet to other planets
    std::vector<Body*>::iterator second_it;
    for (second_it = bodyList_.begin(); second_it != bodyList_.end();
         ++second_it) {
      if (*first_it != *second_it) {
        // Get current position of the two planets
        sf::Vector2f first_pos = (*first_it)->getInitScale();
        sf::Vector2f second_pos = (*second_it)->getInitScale();

        // Get mass of the second planet
        double m2 = (*second_it)->getMass();

        // get different between those position
        double x_dif = second_pos.x - first_pos.x;
        double y_dif = second_pos.y - first_pos.y;
        // r =  squrt(x^2 + y^2)
        double distance = sqrt((x_dif * x_dif) + (y_dif * y_dif));

        // now get the netForce
        double netforce = (*first_it)->calNetforce(distance, m1, m2);

        // Update the acceleration to the current body
        x_force += netforce * (x_dif / distance);
        y_force += netforce * (y_dif / distance);

        // update the acceleration
        x_accel = x_force / m1;
        y_accel = y_force / m1;
      }
    }

    // After comparing and calculating with other planets
    // Update value to the current body
    (*first_it)->setAcceleration(x_accel, y_accel);
    // update Velocity
    (*first_it)->updateVelocity(step_time);
    // now update position
    (*first_it)->step(step_time);

    transformBodies(*(*first_it));
    window_.draw(*(*first_it));
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
  + 5/3: First time Implemented
* ***********************************/
void Universe::Universe::setStepTime(double time_) {
  if (time_ > uni_total_times || time_ <= 0) {
    throw std::runtime_error("Invlaid Time per Step!");
    return;
  }
  step_time = time_;
}

/* **********************************
@ Implemented by Hung Q. Nguyen
@ Note:
  + 5/3: First time Implemented
* ***********************************/
void Universe::Universe::setTotalTime(int time_) {
  if (time_ < step_time) {
    throw std::runtime_error("Invalid Total Time! Should be bigger then time per step");
    return;
  }
  uni_total_times = time_;
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
void Universe::Universe::transformBodies(Body& body) {
  // Get the actual percentage
  double per_pixel = (uni_rad * 2) / winSize_;

  // Get the original center coordinate (0,0) at the middle
  double x_org = winSize_ / 2;
  double y_org = winSize_ / 2;

  sf::Vector2f initial = body.getInitScale();

  // Scale down
  double x_pos = initial.x / per_pixel;
  double y_pos = initial.y / per_pixel;

  // Appli old coordinate
  x_pos += x_org;
  y_pos += y_org;

  // Now set back the scale to the body
  body.setSpritePosition(x_pos, y_pos);
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
      if (sprite.getGlobalBounds()
          .contains(sf::Vector2f(click_coordinates.x, click_coordinates.y))) {
        selectedPlanet_ = *itr;
      }
    }
  }
}

void Universe::Universe::setUpTextAndDialog() {
  sf::Vector2f dialog_size(600, 150);
  sf::Vector2f dialog_pos(window_.getSize().x-dialog_size.x,
                          window_.getSize().y-dialog_size.y);
  dialogBox_.setSize(dialog_size);
  dialogBox_.setPosition(dialog_pos);
  dialogBox_.setFillColor(sf::Color(255, 255, 255, 150));

  fontTime_.loadFromFile("res/fonts.otf");
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
    sf::Vector2f acce = planet->getAcceleration();
    std::stringstream ss;
    std::string name;
    name = planet->getPlanetName();
    ss << std::setw(18) << "Planet: " << name << std::endl;
    ss << std::setw(18) << "Position: (" << planet->getPosition().x;
    ss << ", " << planet->getPosition().y << ")" << std::endl;
    ss << std::setw(17) << "Velocity: (" << planet->get_xVel();
    ss << ", " << planet->get_yVel() << ")" << std::endl;
    ss << "Acceleration: (" << acce.x << ", " << acce.y << ")" << std::endl;
    std::string message = ss.str();
    dialogText_.setString(message);
  }
}

void Universe::Universe::shipMove(sf::Event::KeyEvent key) {
  ship_->move(key.code);
}

void Universe::Universe::updateTime(int time) {
  elapsedTime_ += time;
  this->setTextTime();
}

void Universe::Universe::setTextTime() {
  std::stringstream ss;
  ss << getElapsedTime();
  textTime_.setString(ss.str());
}

int Universe::Universe::getElapsedTime() const {
  return elapsedTime_;
}

void Universe::Universe::printState() {
  std::vector<Body*>::iterator itr;
  std::cout << "++++++++++++++ Universe State ++++++++++++++" << std::endl;
  for (itr = bodyList_.begin(); itr != bodyList_.end(); ++itr) {
    std::cout << "Planet: " << (*itr)->getPlanetName() << std::endl;
    std::cout << *(*itr) << std::endl;
  }
}
