/** Copyright 2015 Daniel Santos & Hung Nguyen
 *  @file     Universe.hpp
 *  @author   Daniel Santos & Hung Nguyen
 *  @date     04/20/2016
 *  @version  1.0
 *
 *  @brief    This file contains the namespace
 *  Universe which contains the classes definition
 *  for SpaceObject.
 * */

#ifndef PS4_SPACEOBJECT_HPP
#define PS4_SPACEOBJECT_HPP

#include <SFML/Graphics.hpp>

/**
 *  @author Daniel Santos & Hung Nguyen
 *
 *  @brief  This is the namespace for the classes
 *  definition.
 * */
namespace Universe {

/**
 *  @author Daniel Santos
 *
 *  @brief  This is an abstract class that inherits
 *  from the sf::Drawable in other make custom drawable
 *  objects in our project.
 * */
class SpaceObject : public sf::Drawable {
 public:
  /**
   *  @brief  This is the destrucotr for the SpaceObject
   *  class.
   * */
  ~SpaceObject();
  /**
   *  @brief  This is a getter for the location vector
   *  of the SpaceObject.
   *
   *  @return const sf::Vector2f&
   * */
  const sf::Vector2f &getLocation() const;
  /**
   *  @brief  This the setter for the location vector
   *  of the SpaceObject.
   *
   *  @param  const sf::Vector2f&
   * */
  void setLocation(const sf::Vector2f &location);
  /**
   *  @brief  This is a getter for the velocity vector
   *  of the SpaceObject.
   *
   *  @return const sf::Vector2u&
   * */
  const sf::Vector2u &getVelocity() const;
  /**
   *  @brief  This the setter for the velocity vector
   *  of the SpaceObject.
   *
   *  @param  const sf::Vector2u&
   * */
  void setVelocity(const sf::Vector2u &velocity);
  /**
   *  @brief  This is a getter for the mass of the
   *  SpaceObject.
   *
   *  @return double
   * */
  double getMass() const;
  /**
   *  @brief  This the setter for the mass of the
   *  SpaceObject.
   *
   *  @param  double
   * */
  void setMass(double mass);

 protected:
  /**
   *  @brief  This is an empty constructor for the
   *  SpaceObject. This will be used if the client
   *  doesn't have all the property of the object
   *  at the intansiation time.
   * */
  SpaceObject();
  /**
   *  @brief This is a complete constructor for the
   *  SpaceObject.
   *
   *  @param  sf::Vector2f, sf::Vector2u, double
   * */
  SpaceObject(sf::Vector2f location, sf::Vector2u velocity, double mass);

 private:
  /**
   *  @brief  This is a virtual method inherited from
   *  the sf::Drawable abstract class. SpaceObject does
   *  not implement this method, because this will work
   *  as another abstract class for other object in the
   *  project.
   *
   *  @param  sf::RenderTarget &target, sf::RenderStates states
   * */
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states)
      const = 0;
  sf::Vector2f location_;  // < This is a 2D float vector
  sf::Vector2u velocity_;  // < This is a 2D unsigned int
  double       mass_;      // < This is the mass of the object
};

}  // namespace Universe

#endif  // PS4_SPACEOBJECT_HPP
