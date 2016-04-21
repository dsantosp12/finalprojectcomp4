#include "Universe.hpp"

Universe::SpaceObject::SpaceObject() : sf::Drawable() {

}

Universe::SpaceObject::SpaceObject(sf::Vector2f location,
                                   sf::Vector2u velocity,
                                   double mass) : sf::Drawable() {

}

Universe::SpaceObject::~SpaceObject() {

}

const sf::Vector2f& Universe::SpaceObject::getLocation() const {
  return location_;
}

void Universe::SpaceObject::setLocation(const sf::Vector2f &location) {
  location_ = location;
}

double Universe::SpaceObject::getMass() const {
  return mass_;
}

void Universe::SpaceObject::setMass(double mass) {
  if (mass <= 0) throw std::invalid_argument("Mass must greater than 0");
  mass_ = mass;
}

const sf::Vector2u& Universe::SpaceObject::getVelocity() const {
  return velocity_;
}

void Universe::SpaceObject::setVelocity(const sf::Vector2u &velocity) {
  velocity_ = velocity;
}

Universe::Star::Star() : SpaceObject() {

}

Universe::Star::Star(sf::Vector2f location, double mass, double radius) :
                     SpaceObject(location, sf::Vector2u(0, 0), mass) {

}

Universe::Star::~Star() {

}

void Universe::Star::draw(sf::RenderTarget &target,
                           sf::RenderStates states) const {

}

sf::Vector2f Universe::Star::positionGenerator() {
  return sf::Vector2f();
}

float Universe::Star::radiusGenerator() {
  return 0.0;
}
