#include "SpaceShip.hpp"

SpaceShip::SpaceShip() : Universe::SpaceObject() {
  texture_.loadFromFile("nbody/spaceship.png");
  sprite_.setTexture(texture_);
}

void SpaceShip::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(sprite_, states);
}