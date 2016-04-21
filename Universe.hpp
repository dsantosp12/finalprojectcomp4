/** Copyright 2015 Daniel Santos & Hung Nguyen
 *  @file     Universe.hpp
 *  @author   Daniel Santos & Hung Nguyen
 *  @date     04/20/2016
 *  @version  1.0
 *
 *  @brief    This file contains the namespace
 *  Universe which contains the classes definition
 *  for SpaceObject, Body, Star, and Universe.
 * */

#ifndef PS4_UNIVERSE_HPP
#define PS4_UNIVERSE_HPP

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

}  // namespace Universe

#endif  // PS4_UNIVERSE_HPP
