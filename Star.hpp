/** Copyright 2015 Daniel Santos & Hung Nguyen
 *  @file     Universe.hpp
 *  @author   Daniel Santos & Hung Nguyen
 *  @date     04/20/2016
 *  @version  1.0
 *
 *  @brief    This file contains the namespace
 *  Universe which contains the classes definition
 *  for Star.
 * */

#ifndef PS4_STAR_HPP
#define PS4_STAR_HPP

#include <SFML/Graphics.hpp>
#include "SpaceObject.hpp"

namespace Universe {
/**
 *  @brief  This is a Star object that inherits from
 *  SpaceObject which is a sf:Drawabl. This class will
 *  model
 * */
class Star : public SpaceObject {
 public:
  /**
   *  @brief  This is the empty construct of the Star
   *  object. This constructor will generate a random
   *  position and radius for the object which will be
   *  used for the sf::CircleShape.
   * */
  Star();
  /**
   *  @brief  This a constructor that will allow the
   *  make a Start object with properties that it wants.
   *  This constuctor will not generate the location or
   *  radius of the object, it will use the given
   *  parameters. The velocity of this object is default
   *  to zero becuase this is a static/non-moving object.
   *
   *  @param  sf::Vector2f location, double mass, double radius
   * */
  Star(sf::Vector2f location, double mass, double radius);
  /**
   *  @brief  Destructor of the Star object.
   * */
  ~Star();

 private:
  /**
   *  @brief  This is a virtual method inherited from
   *  the SpaceObject abstract class. This class implement
   *  this method, and it will draw the shapes inside it.
   *
   *  @param  sf::RenderTarget &target, sf::RenderStates states
   * */
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  /**
   *  @brief  This method will be used for the std::generate()
   *  algorithm to generate a random position. This uses the
   *  std::rand() function to generate the x and y points.
   *
   *  @return sf::Vector2f
   * */
  sf::Vector2f positionGenerator();
  /**
   *  @brief  This method will be used for the std::generate()
   *  algorithm to generate a random position. This uses the
   *  std::rand() function to generate the radius.
   *
   *  @return sf::Vector2f
   * */
  float radiusGenerator();
  sf::CircleShape shape_;   // < This is the a circle shape of the object
  double          radius_;  // < This holds the radius of the circle
};

}

#endif //PS4_STAR_HPP
