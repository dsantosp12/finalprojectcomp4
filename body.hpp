///** Copyright 2015 Daniel Santos & Hung Nguyen
//*  @file     body.hpp
//*  @author   Daniel Santos & Hung Nguyen
//*  @date     04/20/2016
//*  @version  1.0
//*
//*  @brief    This file contains the namespace
//*  Universe which contains the classes definition
//*  for Body
//* */
//
//#include <iostream>
//#include <vector>
//#include <math.h>
//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/System.hpp>
//#include <SFML/Audio.hpp>
//#include "Universe.hpp"
//
//namespace Universe {
//class Body : public SpaceObject, virtual private NonCopyClass {
//public:
//	/*  @author: Hung Q Nguyen
//	 *	@brief: A default constructor of the Planet itself.
//	 *	A Planet will be inheritanced from the SpaceObject so
//	 *	It will have the drawable feature by itself.
//	 *	The job of this function will provide the unique information
//	 *	of each planet
//	 *
//	 *	@params: sf::Vector2f -- The Initial position of the planet
//	 *			 sf::Vector2u -- Velocity of the planet
//	 *		 	 double  -- the mass of the planet
//	 */
//	Body (sf::Vector2f initial_pos, sf::Vector2u velocity,
//	  sf::Texture texture, double mass)
//	  : SpaceObject (initial_pos, velocity, mass), planet_texture(textures);
//	/*
//	 *   @brief: Destructor of the Body object
//	 *   @params: none
//	 *   @return: none
//	 */
//	~Body();
//
//	/** @author: Hung Q Nguyen
//	 *   @brief  Step Function to get the XOR value of the seed with space position
//	 *	The step() function will look for the space position on the initial seed.
//	 *	After that, it will generate another integer by getting the result of XOR
//	 *	operation of two integers, one is the value at tab position, one is the value
//	 *	at the end of the current seed.
//	 *
//	 *	After that, it will shift the current seed one to the left and then put the
//	 *	current generated value to the last position of the seed.
//	 *   @param  nothing
//	 *   @return nothing
//	 */
//	void step(double times);
//
//	/** @author: Hung Q Nguyen
//	*   @brief updateSeed funtion will update the seed
//	*	Since the step() function is called, the new number generated and the
//	* 	vector positions changes, updateSeed() function will automatically
//	*	called in the step() function and create a string based on the elements
//	*	of the vector of vector2f's position
//	*
//	*   @param  nothing
//	*   @return nothing
//	*/
//	void updatePosition();  // update seed everytime the function is called
//
//	/** @author: Hung Q Nguyen
//	*   @brief input method of SpaceObject class
//	*	Overloading function will make a cast to SpaceObject class and treat
//	*	object (constructor) as a string.
//	*	Using to display the coordiates at the bottom of window
//	*
//	*   @param  input stream and the current object
//	*   @return istream&
//	*/
//	std::istream& operator <<(std::istream& in_stream, const Body& body) {
//		in_stream >> body.x_pos >> body.y_pos >>
//			body.x_vel >> body.y_vel >> body.mass_ >> body.file_name;
//		return in_stream;
//	}
//
//	/** @author: Hung Q Nguyen
//	*   @brief toString() method of SpaceObject class
//	*	Overloading function will make a cast to SpaceObject class and treat
//	*	object (constructor) as a string.
//	*	Using to display the coordiates at the bottom of window
//	*
//	*   @param  output stream
//	*   @return ostream&
//	*	@note added on 4/30/2016
//	*/
//	std::ostream& operator <<(std::ostream& out_stream, const Body& body)
//	{
//		out_stream << " " << body._xpos << " ";
//		out_stream << " " << body._ypos << " ";
//		out_stream << " " << body._xvel << " ";
//		out_stream << " " << body._yvel << " ";
//		out_stream << " " << body._mass << " ";
//		out_stream << " " << body._filename << " ";
//
//		return out_stream;
//	}
//
//
//	/*  @author: Hung Q Nguyen
//	*	@brief: Calculating the netforce between the planet to the sun
//	*	at the current times
//	*
//	*	@param: radius, mass of planet1, mass of planet2
//	*	@return: double
//	*	Edited: 4/26 -- Hung Q Nguyen
//	*/
//	double calNetforce(double radius, double planet1_mass, double planet2_mass);
//
//	/*  @author: Hung Q Nguyen
//	*	@brief: Calculating the acceleration of the planet at the curernt time
//	*	@param: double times: -- the current time calculating
//	*	@return: sf::Vector2u -- Getting the values calculated
//	*/
//	sf::Vector2u calAcceleration(double times, double massgf);
//
//	/*  @author: Hung Q Nguyen
//	*	@brief: Calculating the vector of velocity at the current time
//	*	After Calculating the velocity, it will set the velocity to
//	* 	the current spaceobject by calling this->setVelocity()
//	*	@param: double times: -- the current time calculating
//	*	@return: void -- Getting the values calculated through setter
//	*/
//	void updateVelocity(double times);
//
//	/**************************************
//	LIST OF GETTERS AND SETTERS
//	***************************************/
//
//    /*  @author: Hung Q Nguyen
//    *   @brief: Setting value of times
//    *   @params: double -- value of times to assign
//    *   @return: void
//    **/
//	void setTimes(double times) {times_ = times;}
//
//    /*  @author: Hung Q Nguyen
//    *   @brief: Getting the value of times
//    *   @params: None
//    *   @return: double -- Value of times
//    */
//	double getTimes() {return times_;}
//
//	/*  @author: Hung Q Nguyen
//    *   @brief: Setting the texture from
//    *	file name loaded from text tile.
//    *   @params: none
//    *   @return: none
//    */
//	void setBodyTexture(sf::Texture texture) {pTexture_ = texture;};
//
//	/*  @author: Hung Q Nguyen
//    *   @brief: Create the sprite from
//    *	the texture;
//    *   @params: none
//    *   @return: none
//    *	Added -- 4/26/2016
//    */
//	void createBodyTexture();
//
//	/*  @author: Hung Q Nguyen
//    *   @brief: Create the texture from
//    *	file name loaded from text tile.
//    *   @params: none
//    *   @return: none
//    *	Added -- 4/26/2016
//    */
//	void createBodySprite();
//
//	/*  @author: Hung Q Nguyen
//    *   @brief: Setting the texture from
//    *	file name loaded from text tile.
//    *   @params: none
//    *   @return: none
//    *	Added -- 4/26/2016
//    */
//	void setBodySprite(sf::Sprite sprite) {pSprite_ = sprite;};
//
//	/*  @author: Hung Q Nguyen
//    *   @brief: Getting the Sprite of Body
//    *   @params: None
//    *   @return: Sprite
//    *	Added: 4/26/2016
//    */
//	sf::Sprite getSprite() {return pSprite_;}
//
//	/*  @author: Hung Q Nguyen
//    *   @brief: Getting the Texture of Body
//    *   @params: None
//    *   @return: Texture
//    */
//	sf::Texture getBodyTexture() {return pTexture_;}
//
//	/*  @author: Hung Q Nguyen
//    *   @brief: Getting the value of netforce
//    *   @params: None
//    *   @return: double -- Value of Netforce
//    */
//	double getNetForce() {return netForce_;}
//
//	/*  @author: Hung Q Nguyen
//    *   @brief: Getting the value of acceleration
//    *   @params: None
//    *   @return: sf::Vector2f -- Value of acceleration
//    */
//	sf::Vector2u getAcceleration() {return acceleration_;}
//
//	/*  @author: Hung Q Nguyen
//    *   @brief: Calculating the distance to the Sun
//    *   @params: none
//    *   @return: none
//    *	Added -- 4/26/2016
//    */
//	void calDistanceToSun();
//
//	/*  @author: Hung Q Nguyen
//    *   @brief: Calculating the distance to the Sun
//    *   @params: none
//    *   @return: none
//    *	Added -- 4/26/2016
//    */
//	void setDistanceToSun(double distance) {distanceToSun = distace;}
//
//	/*  @author: Hung Q Nguyen
//    *   @brief: Calculating the center
//    *   @params: none
//    *   @return: none
//    *	Added -- 4/26/2016
//    */
//	void calCenterLocation(double window_width, double window_height);
//
// private:
//	double times_;  ///< Counting the time that the planet has moved
//
//	sf::Texture pTexture_;  ///< Texture of the planet
//	sf::Vector2f netForce_;  ///< net force between planet and the Sun
//	sf::Vector2u acceleration_;  ///< the acceleration of
//
//	// Added more variables for the need -- 4/26/2016 -- Hung Nguyen
//	float x_pos, y_pos, x_vel, y_vel, mass_;
//	std::string file_name;  ///< Taking the name of the planet: e.g: sun.gif
//	double distanceToSun;  ///< Measure distance from planet to the sun
//	double x_center, y_center;  ///< The center of the Window
//								///< This is also the sun position
//};
//}
