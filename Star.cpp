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

Universe::Star::Star(sf::Vector2u winDimesion, std::vector<Star>& starList) : SpaceObject() {
  shape_.setRadius(this->radiusGenerator());
  shape_.setPosition(this->positionGenerator(winDimesion, starList));
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

sf::Vector2f Universe::Star::positionGenerator(sf::Vector2u range, std::vector<Star>& starList) {
//  std::vector<Star>::iterator itr = starList.begin();
  sf::Vector2f new_vector(std::rand()%range.x, std::rand()%range.y);
//  while (true) {
//    if ((*itr).getLocation() == new_vector) {
//      new_vector = sf::Vector2f(std::rand()%range.x, std::rand()%range.y);
//      if (itr != starList.end())
//        ++itr;
//      else
//        itr = starList.begin();
//    }
//    else {
//      break;
//    }
//  }
  return new_vector;
}

float Universe::Star::radiusGenerator() {
  this->radius_ = std::rand()%3;
  return this->radius_;
}
