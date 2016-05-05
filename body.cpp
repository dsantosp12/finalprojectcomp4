/** Copyright 2015 Daniel Santos & Hung Nguyen
*  @file     body.cpp
*  @author   Daniel Santos & Hung Nguyen
*  @date     04/22/2016
*  @version  1.0
*
*  @brief    This file contains the namespace
*  Universe which contains the classes definition
*  for Universe class -- the completed Body
* */

#include <string>
#include "body.hpp"
#include "Universe.hpp"

const double G = 6.67e-11;
const double E = 1e+9;

Universe::Body::Body(int window_size)
  : wSize_(window_size) {
}

Universe::Body::~Body() {}

void Universe::Body::createBodyTexture() {
  pTexture_.loadFromFile(file_name);
}

void Universe::Body::createBodySprite() {
  pSprite_.setTexture(pTexture_);
}

double Universe::Body::calNetforce(double distance, double m1, double m2) {
  double netForce = 0;

  // F = Gm1m2 / r^2
  // calculate the value of netforce with pure calculation
  netForce = (G * m1 * m2) / (distance * distance);
  return netForce;
}

void Universe::Body::updateVelocity(double times) {
  x_vel = x_vel + (x_accel_ * times);
  y_vel = y_vel - (y_accel_ * times);
}

void Universe::Body::step(double times) {
  // Update position from step
  x_pos = x_pos + (x_vel * times);
  y_pos = y_pos - (y_vel * times);
}

void Universe::Body::draw(sf::RenderTarget &target,
                          sf::RenderStates states) const {
  target.draw(pSprite_, states);
}

std::string Universe::Body::getPlanetName() {
  return planet_name_;
}

void Universe::Body::parsePlanetName() {
  std::string parsed_name = "";
  parsed_name += toupper(planet_name_.at(0));
  for (unsigned int i = 1; i < planet_name_.size()
      && planet_name_.at(i) != '.'; i++) {
    std::cout << parsed_name << std::endl;
    parsed_name += planet_name_.at(i);
  }
  planet_name_ = parsed_name;
}
