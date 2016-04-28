#include "Star.hpp"

Universe::Star::Star() : SpaceObject() {
}


Universe::Star::Star(sf::Vector2f location, double mass) :
    SpaceObject(location, sf::Vector2u(0, 0), mass) {
  shape_.setRadius(this->radiusGenerator());
  shape_.setPosition(this->positionGenerator());
  shape_.setFillColor(sf::Color(235, 252, 253, 150));
}

Universe::Star::~Star() {

}

void Universe::Star::draw(sf::RenderTarget &target,
                          sf::RenderStates states) const {
  target.draw(shape_, states);
}

sf::Vector2f Universe::Star::positionGenerator() {
  return sf::Vector2f(std::rand()%800, std::rand()%600);
}

float Universe::Star::radiusGenerator() {
  this->radius_ = std::rand()%10;
  return this->radius_;
}
