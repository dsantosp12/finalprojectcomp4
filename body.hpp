/** Copyright 2015 Daniel Santos & Hung Nguyen
*  @file     body.hpp
*  @author   Daniel Santos & Hung Nguyen
*  @date     04/20/2016
*  @version  1.0
*
*  @brief    This file contains the namespace
*  Universe which contains the classes definition
*  for Body
* */

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Windows.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "Universe.hpp"

namespace Universe {
class Body : public SpaceObject, virtual private NonCopyClass {
public:
	/*  @author: Hung Q Nguyen
	 *	@brief: A default constructor of the Planet itself.
	 *	A Planet will be inheritanced from the SpaceObject so
	 *	It will have the drawable feature by itself.
	 *	The job of this function will provide the unique information
	 *	of each planet
	 *	
	 *	@params: sf::Vector2f -- The Initial position of the planet
	 *			 sf::Vector2u -- Velocity of the planet
	 *		 	 double  -- the mass of the planet
	 */
	Body (sf::Vector2f initial_pos, sf::Vector2u velocity, 
	  sf::Texture texture, double mass) 
	  : SpaceObject (initial_pos, velocity, mass), planet_texture(textures);

	/*
	 *   @brief: Destructor of the Body object
	 *   @params: none
	 *   @return: none
	 */
	~Body();

	/** @author: Hung Q Nguyen
	 *   @brief  Step Function to get the XOR value of the seed with space position
	 *	The step() function will look for the space position on the initial seed.
	 *	After that, it will generate another integer by getting the result of XOR
	 *	operation of two integers, one is the value at tab position, one is the value
	 *	at the end of the current seed.
	 *
	 *	After that, it will shift the current seed one to the left and then put the
	 *	current generated value to the last position of the seed.
	 *   @param  nothing
	 *   @return Integer (value of the current generated integer)
	 */
	int step(double times);

	/** @author: Hung Q Nguyen
	*   @brief updateSeed funtion will update the seed
	*	Since the step() function is called, the new number generated and the
	* 	vector positions changes, updateSeed() function will automatically
	*	called in the step() function and create a string based on the elements
	*	of the vector of vector2f's position
	*	
	*   @param  nothing
	*   @return nothing
	*/

	void updatePosition();  // update seed everytime the function is called

	/** @author: Hung Q Nguyen
	*   @brief toString() method of SpaceObject class
	*	Overloading function will make a cast to SpaceObject class and treat
	*	LFSR object (constructor) as a string.
	*	Using to display the coordiates at the bottom of window
	*
	*   @param  nothing
	*   @return nothing
	*/
	friend std::istream& operator <<(std::istream& input, const SpaceObject&);

	/*  @author: Hung Q Nguyen
	*	@brief: Calculating the netforce between the planet to the sun
	*	at the current times
	*
	*	@param: double times -- the current time calculating
	*	@return: sf::Vector2f -- Basically getting the private variables of the class
	*/
	sf::Vector2f calNetforce(double times);


	/*  @author: Hung Q Nguyen
	*	@brief: Calculating the acceleration of the planet at the curernt time
	*	@param: double times: -- the current time calculating
	*	@return: sf::Vector2u -- Getting the values calculated
	*/
	sf::Vector2u calAcceleration(double times, double massgf);

	/*  @author: Hung Q Nguyen
	*	@brief: Calculating the vector of velocity at the current time
	*	@param: double times: -- the current time calculating
	*	@return: sf::Vector2u -- Getting the values calculated
	*/
	sf::Vector2u calVelocity(double times);

	/**************************************
	LIST OF GETTERS AND SETTERS
	***************************************/

    /*  @author: Hung Q Nguyen
    *   @brief: Setting value of times
    *   @params: double -- value of times to assign
    *   @return: void
    **/
	void setTimes(double times) {times_ = times;}

    /*  @author: Hung Q Nguyen
    *   @brief: Getting the value of times
    *   @params: None
    *   @return: double -- Value of times
    */
	double getTimes() {return times_;}
	
	/*  @author: Hung Q Nguyen
    *   @brief: Setting the texture
    *   @params: texture to set
    *   @return: none
    */
	void setBodyTexture(sf::Texture texture) {pTexture_ = texture;}

	/*  @author: Hung Q Nguyen
    *   @brief: Getting the Texture of Body
    *   @params: None
    *   @return: Texture
    */
	sf::Texture getBodyTexture() {return pTexture_;}

	/*  @author: Hung Q Nguyen
    *   @brief: Getting the value of netforce
    *   @params: None
    *   @return: sf::Vector2f -- Value of Netforce
    */
	sf::Vector2f getNetForce() {return netForce_;}

	/*  @author: Hung Q Nguyen
    *   @brief: Getting the value of acceleration
    *   @params: None
    *   @return: sf::Vector2f -- Value of acceleration
    */
	sf::Vector2u getAcceleration() {return acceleration_;}

	/*  @author: Hung Q Nguyen
    *   @brief: Getting the value of Velocity
    *   @params: None
    *   @return: sf::Vector2u -- Value of velocity
    */
	sf::Vector2u getVelocity() {return velocity_;}

	/*  @author: Hung Q Nguyen
    *   @brief: Getting the value of current position
    *   @params: None
    *   @return: sf::Vector2f -- Value of position
    */
	sf::Vector2f getPosition() {return position_;}

 private:
	double mass_;  ///< Mass of the planet's body
	double times_;  ///< Counting the time that the planet has moved

	sf::Texture pTexture_;  ///< Texture of the planet
	sf::Vector2f netForce_;  ///< net force between planet and the Sun
	sf::Vector2u acceleration_;  ///< the acceleration of 
								 ///< the planet the the currentime
	sf::Vector2u velocity_;  ///< Velocity at the current time
	sf::Vector2f position_;  ///< Position at the current time
};
}
