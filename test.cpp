/**
 *  Copyright 2016 Hung Q. Nguyen && Daniel Santos
 *  @file    ring_buffer_test.cpp
 *  @author  Hung Q. Nguyen && Daniel Santos
 *  @date    5/3/2016
 *  @version Doxygen 1.8.11
 *  
 *  @brief Test cases to check if the universe works
 *    correctly or not.
 */

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

#include <stdint.h>
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>
#include "Universe.hpp"
#include "SpaceObject.hpp"
#include "body.hpp"

  BOOST_AUTO_TEST_CASE(UniObject) {
  // Temp list for making the universe purpose
  std::vector<Universe::Body*> temp;
  for (int i = 0; i < 5; i++) {
    Universe::Body* planet = new Universe::Body(500);
    temp.push_back(planet);
  }

  Universe::Universe uni(500000, 500, temp);

  // Check valid capacnumber_of_planetsity for the list buffer
  // the run will display universe's properties before it stops
  BOOST_REQUIRE_NO_THROW(uni.run());

  // Throw exception if peek an empty buffer
  BOOST_REQUIRE_THROW(Universe::Universe(1e12,
                          -500, temp), std::invalid_argument);
}

  BOOST_AUTO_TEST_CASE(TotalTime) {
  // Temp list for making the universe purpose
  std::vector<Universe::Body*> temp;
  for (int i = 0; i < 5; i++) {
  Universe::Body* planet = new Universe::Body(500);
    temp.push_back(planet);
  }

  // create a universe
  Universe::Universe uni1(500000, 500, temp);

  // Check function set Totaltime running of the universe
  BOOST_REQUIRE_NO_THROW(uni1.setTotalTime(50000));

  // Check if the variable got the right value
  BOOST_REQUIRE_EQUAL(uni1.getTotalTime(), 50000);

  // it should throw is we passed in something invalid
  BOOST_REQUIRE_THROW(uni1.setTotalTime(-1), std::runtime_error);
}

  BOOST_AUTO_TEST_CASE(StepTime) {
  // Temp list for making the universe purpose
  std::vector<Universe::Body*> temp;
  for (int i = 0; i < 5; i++) {
    Universe::Body* planet = new Universe::Body(500);
    temp.push_back(planet);
  }

  // create a universe
  Universe::Universe uni2(500000, 500, temp);

  // Check function set Totaltime running of the universe
  BOOST_REQUIRE_NO_THROW(uni2.setTotalTime(150000));
  BOOST_REQUIRE_NO_THROW(uni2.setStepTime(50000));

  // Check if the variable got the right value
  BOOST_REQUIRE_EQUAL(uni2.getStepTime(), 50000);

  // it should throw is we passed in something invalid, such as
  // step time is negative
  BOOST_REQUIRE_THROW(uni2.setStepTime(-1), std::runtime_error);
  // or steptime is greater than totaltime
  BOOST_REQUIRE_THROW(uni2.setStepTime(150001), std::runtime_error);
}

  BOOST_AUTO_TEST_CASE(StepFunction) {
  // Temp list for making the universe purpose
  std::vector<Universe::Body*> temp;
  for (int i = 0; i < 5; i++) {
    Universe::Body* planet = new Universe::Body(500);
    temp.push_back(planet);
  }

  // create a universe
  Universe::Universe uni3(500000, 500, temp);

  // Setting up the universe
  uni3.setTotalTime(1000000);
  uni3.setStepTime(1000);

  // Getting the first body
  std::vector<Universe::Body*>::iterator firstBody = temp.begin();
  // Set initial position
  (*firstBody)->set_xPos(0);
  (*firstBody)->set_yPos(0);

  // SetAcceleration
  (*firstBody)->setAcceleration(1, 1);

  // Set velocity
  (*firstBody)->set_xVel(500.0);
  (*firstBody)->set_yVel(500.0);

  // Now call the step
  (*firstBody)->step(1000.0);

  // Now check the results after step
  // Check if the variable got the right value
  // x_pos +=  (x_vel * times per step)
  // y_pos -=  (y_vel * times per step)
  BOOST_REQUIRE_EQUAL((*firstBody)->get_xPos(), 500000);
  BOOST_REQUIRE_EQUAL((*firstBody)->get_yPos(), -500000);
}

  BOOST_AUTO_TEST_CASE(Velocity) {
  // Temp list for making the universe purpose
  std::vector<Universe::Body*> temp;
  for (int i = 0; i < 5; i++) {
    Universe::Body* planet = new Universe::Body(500);
    temp.push_back(planet);
  }

  // create a universe
  Universe::Universe uni4(500000, 500, temp);

  // Setting up the universe
  uni4.setTotalTime(1000000);
  uni4.setStepTime(1000);

  // Getting the first body
  std::vector<Universe::Body*>::iterator firstB = temp.begin();
  // Set initial position
  (*firstB)->set_xPos(0);
  (*firstB)->set_yPos(0);

  // SetAcceleration
  (*firstB)->setAcceleration(1, 1);

  // Set velocity
  (*firstB)->set_xVel(500.0);
  (*firstB)->set_yVel(500.0);

  // Now call the step
  (*firstB)->updateVelocity(1000);

  BOOST_REQUIRE_EQUAL((*firstB)->get_xVel(), 1500);
  BOOST_REQUIRE_EQUAL((*firstB)->get_yVel(), -500);
}

  BOOST_AUTO_TEST_CASE(Translation) {
  // Temp list for making the universe purpose
  std::vector<Universe::Body*> temp;
  for (int i = 0; i < 5; i++) {
    Universe::Body* planet = new Universe::Body(500);
    temp.push_back(planet);
  }

  // create a universe
  Universe::Universe uni5(500000, 500, temp);

  // Setting up the universe
  uni5.setTotalTime(1000000);
  uni5.setStepTime(1000);

  // Getting the first body
  std::vector<Universe::Body*>::iterator first = temp.begin();
  // Set initial position
  (*first)->set_xPos(0);
  (*first)->set_yPos(0);

  // SetAcceleration
  (*first)->setAcceleration(1, 1);

  // Set velocity
  (*first)->set_xVel(500.0);
  (*first)->set_yVel(500.0);

  // Now transform body to get the SFML coordinate
  uni5.transformBodies(*(*first));
  sf::Vector2f newCoor = (*first)->getPosition();

  // Currently -- the universe radius is 500000 and window size is 500
  // So 1000 miles od radius is equal to 1 pixel of sfml coordinate
  // so in SFML, the (0,0) coordinate in univers equivalence to
  // (0+250,0+250) in sfml (500/2 = 250)
  BOOST_REQUIRE_EQUAL(newCoor.x, 250);
  BOOST_REQUIRE_EQUAL(newCoor.y, 250);
}
