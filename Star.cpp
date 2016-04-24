#include "Star.hpp"

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
