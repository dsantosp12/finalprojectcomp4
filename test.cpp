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
  BOOST_REQUIRE_NO_THROW(uni.run());

  // Universe::Universe temp1(1e12, -500, temp);

  // // Throw exception if peek an empty buffer
  // BOOST_REQUIRE_THROW(temp1, std::invalid_argument);
}