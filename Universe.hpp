/** Copyright 2015 Daniel Santos & Hung Nguyen
*  @file     body.hpp
*  @author   Daniel Santos & Hung Nguyen
*  @date     04/22/2016
*  @version  1.0
*
*  @brief    This file contains the namespace
*  Universe which contains the classes definition
*  for Universe class -- the completed Universe
* */
#ifndef PS4_UNIVERSE_HPP
#define PS4_UNIVERSE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <string>
#include "SpaceObject.hpp"
#include "Star.hpp"

/**
 *  @author Daniel Santos & Hung Nguyen
 *
 *  @brief  This is the namespace for the classes
 *  definition.
 * */
namespace Universe {
class Universe {
 public:
  /*  @author: Daniel Santos & Hung Q Nguyen
   *  @brief: The complete univer object
   *  Which is included the stars and planets
   *  @params: none
   *  @return: none

   *  @test: Hung Q Nguyen
   *  Unit Testing: There are multiple ways for testing this
   *  object by using this object to call the existed functions
   *  There are no unique properties for the default constructor
   *  to test.
   */
  Universe();

  /*  @author: Daniel Santos & Hung Q Nguyen
   *  @brief: The destructor of the universe object
   *  @params: none
   *  @return: none
   */
  ~Universe();

  /*  @author: Daniel Santos & Hung Q Nguyen
   *  @brief: This function will draw every planet
   *  and star to the screen at the updated moment.
   *  It will be called multiple times as long as
   *  the window opens and it will update the properties
   *  of Space Object every time it get called.
   *  @params: none
   *  @return: none
   */
  void run();

  /*  @author: Daniel Santos & Hung Q Nguyen
   *  @brief: Getting the values from space and
   *  translate it to the vector2f from sfml
   *  @params: float x -- x position and float y -- y position
   *  @return: sf::Vector2f -- coordinate vector

    *  @test: Hung Q Nguyen
   *  Unit Testing: to test this function, we will pass in two
   *  floats to the function and check if it returns the exact vector
   *  or not
   *  BOOST_REQUIRE_EQUAL(sf::Vector2f(0.5,0.5), translateCoordinates(0.5,0.5))
   */
  sf::Vector2f translateCoordinates(float x, float y);

  /*  @author: Daniel Santos & Hung Q Nguyen
   *  @brief: Print the current state of the universe
   *  @params: none
   *  @return: none
   */
  void printState();

  /*  @author: Daniel Santos & Hung Q Nguyen
   *  @brief: Getting the ref of the elapsed time string.
   *  @params: none
   *  @return: sf::Text& -- Ref to the current text (String of elapsed time)
   */
  sf::Text& getTextTime() const;

  /*  @author: Daniel Santos & Hung Q Nguyen
   *  @brief: setting the text from value of elapsed time.
   *  @params: int -- value of elapse time
   *  @return: none
   */
  void setTextTime(int elapsed_time);

  /*  @author: Daniel Santos & Hung Q Nguyen
   *  @brief: get the value of elapsed time
   *  @params: none
   *  @return: int -- value of Elapsed time
   */
  int getElapsedTime() const;

 private:
  /*  @author: Daniel Santos & Hung Q Nguyen
   *  @brief: Generate the vector of Bodies
   *  by reading the information from the file (given)
   *  @params: none
   *  @return: none
   */
  void fetchBody();

  /*  @author: Daniel Santos & Hung Q Nguyen
   *  @brief: Generate the vector of Stars
   *  @params: none
   *  @return: none
   */
  void fetchStar();
  /**
   *  @author:  Daniel Santos
   *  @brief:   This method will draw the stars
   *  using the window object.
   *  @param:   none
   *  @return:  none
   * */
  void drawStars();
  /*  @author: Daniel Santos & Hung Q Nguyen
   *  @brief: Update the elapsed time as long as
   *  the program is running.
   *  @params: none
   *  @return: none
   */
  void updateTime();

  /*  @author: Daniel Santos & Hung Q Nguyen
   *  @brief: Update the coordinates of the planets
   *  and the properties of each planet.
   *  @params: none
   *  @return: none
   */
  void updateUniverse();

  unsigned int winWidth_;
  unsigned int winHeight_;
  sf::RenderWindow window_;
//  std::vector<Body*> bodyList_;  ///< List of Bodies
  std::vector<Star> starList_;  ///< List of Stars
  int elapsedTime_;   ///< Elapsed Time
  sf::Font fontTime_;  ///< Font of Text displaying in the screen
  sf::Text textTime_;  ///< Text of the Planet.
};

}
#endif  // PS4_SPACEOBJECT_HPP
