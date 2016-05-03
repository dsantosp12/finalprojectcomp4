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

#define MOVE_FACT 15

class SpaceShip : public Universe::SpaceObject {
 public:
  SpaceShip(sf::Vector2u winSize);
  void move(sf::Keyboard::Key direction);
 private:
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  sf::Sprite sprite_;
  sf::Texture texture_;
};


#endif //PS4_SPACESHIP_HPP
