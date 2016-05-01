#include "Star.hpp"

Universe::Star::Star(sf::Vector2u winDimesion) : SpaceObject() {
  shape_.setRadius(this->radiusGenerator());
  shape_.setPosition(this->positionGenerator(winDimesion));
  shape_.setFillColor(sf::Color(235, 252, 253, 150));
}

Universe::Star::Star(sf::Vector2f location, double mass) :
    SpaceObject(location, sf::Vector2u(0, 0), mass) {
  shape_.setRadius(this->radiusGenerator());
  shape_.setPosition(location);
  shape_.setFillColor(sf::Color(235, 252, 253, 150));
}

Universe::Star::~Star() {

}

void Universe::Star::draw(sf::RenderTarget &target,
                          sf::RenderStates states) const {
  target.draw(shape_, states);
}

sf::Vector2f Universe::Star::positionGenerator(sf::Vector2u range) {
  return sf::Vector2f(std::rand()%range.x, std::rand()%range.y);
}

float Universe::Star::radiusGenerator() {
  this->radius_ = std::rand()%10;
  return this->radius_;
}
