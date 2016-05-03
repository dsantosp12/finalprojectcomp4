/** Copyright 2015 Daniel Santos & Hung Nguyen
*  @file     SpaceShip.hpp
*  @author   Daniel Santos
*  @date     05/3/2016
*  @version  1.0
*
*  @brief    This file contains the definition
 * of the SpaceShip object.
* */
#ifndef PS4_SPACESHIP_HPP
#define PS4_SPACESHIP_HPP

#include "SpaceObject.hpp"

static const enum MOVE {
  UP, DOWN, LEFT, RIGTH
};

class SpaceShip : public Universe::SpaceObject {
 public:
  SpaceShip();
  void move(MOVE direction);
 private:
  void SpaceShip::draw(sf::RenderTarget &target, sf::RenderStates states) const;
  sf::Sprite sprite_;
  sf::Texture texture_;
};


#endif //PS4_SPACESHIP_HPP
