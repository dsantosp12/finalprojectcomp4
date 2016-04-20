#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Windows.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

namespace universe {
	class Body : public SpaceObject, virtual private NonCopyClass {
		public:
			/*
			*	@brief: A default constructor of the Planet itself.
			*	A Planet will be inheritanced from the SpaceObject so
			*	It will have the drawable feature by itself.
			*	The job of this function will provide the unique information
			*	of each planet
			*	
			*	@oarams: sf::Vector2f -- The Initial position of the planet
			*			 sf::Vector2u -- Velocity of the planet
			*		 	 double  -- the mass of the planet
			*/
			Body (sf::Vector2f initial_pos, sf::Vector2u velocity, 
					sf::Texture texture, double mass) 
				: SpaceObject (initial_pos, velocity, mass), planet_texture(textures);

			/**
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

			/**
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

			/**
			*   @brief toString() method of SpaceObject class
			*	Overloading function will make a cast to SpaceObject class and treat
			*	LFSR object (constructor) as a string.
			*	Using to display the coordiates at the bottom of window
			*
			*   @param  nothing
			*   @return nothing
			*/
			friend std::istream& operator <<(std::istream&, const SpaceObject&);

			/*
			*	@brief: Calculating the netforce between the planet to the sun
			*	at the current times
			*
			*	@param: double times -- the current time calculating
			*	@return: sf::Vector2f -- Basically getting the private variables of the class
			*/
			sf::Vector2f calNetforce(double times);


			/*
			*	@brief: Calculating the acceleration of the planet at the curernt time
			*	@param: double times: -- the current time calculating
			*	@return: sf::Vector2u -- Getting the values calculated
			*/
			sf::Vector2u calAcceleration(double times, double massgf);

			/*
			*	@brief: Calculating the vector of velocity at the current time
			*	@param: double times: -- the current time calculating
			*	@return: sf::Vector2u -- Getting the values calculated
			*/
			sf::Vector2u calVelocity(double times);

			/**************************************
			LIST OF GETTERS AND SETTERS
			***************************************/

			void setMass(double mass) {mass_ = mass;}
			double getMass() {return mass_;}

			void setTimes(double times) {times_ = times;}
			double getTimes() {return times_;}

			void setBodyTexture(sf::Texture texture) {pTexture_ = texture;}
			sf::Texture getBodyTexture() {return pTexture_;}

			sf::Vector2f getNetForce() {return netForce_;}

			sf::Vector2u getAcceleration() {return acceleration_;}

			sf::Vector2u getVelocity() {return velocity_;}

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