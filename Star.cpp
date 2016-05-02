#include "Star.hpp"
#define NUM_COLORS 5
#define TRANSPARENCY 200
const static sf::Color STAR_COLORS[NUM_COLORS] = {
    sf::Color(244, 202, 160, TRANSPARENCY),
    sf::Color(141, 160, 229, TRANSPARENCY),
    sf::Color(251, 241, 233, TRANSPARENCY),
    sf::Color(225, 180, 109, TRANSPARENCY),
    sf::Color(218, 217, 223, TRANSPARENCY)
};

Universe::Star::Star(sf::Vector2u winDimesion) : SpaceObject() {
  shape_.setRadius(this->radiusGenerator());
  shape_.setPosition(this->positionGenerator(winDimesion));
  shape_.setFillColor(STAR_COLORS[std::rand()%NUM_COLORS]);
}

Universe::Star::Star(sf::Vector2f location, double mass) :
    SpaceObject(location, sf::Vector2u(0, 0), mass) {
  shape_.setRadius(this->radiusGenerator());
  shape_.setPosition(location);
  shape_.setFillColor(STAR_COLORS[std::rand()%NUM_COLORS]);
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
