Authors: Hung Q Nguyen, Daniel Santos
Date Begins: 4/18/2016
Date Complete: N/A
Project name: Solar System

General Work: (Work has been discussed and decided together)
	+ Making a general object and features for every planet
	+ Making a namespace for project: suggestions -- solarsystem -- universal
	+ Making a class that will be inheritances from other small classes: Planet
	+ Making planet-classes that will inheritance from the Planet class which
	will have all properties of the planet.

	+ List of planets:
		- Sun
		- Mercury
		- Venus
		- Earth
		- Mars
		- Jupiter
		- Saturn
		- Uranus
		- Neptune

	+ General variables for each planet:
		*** For 2D Project
		- double: Radius (size)
		- double: Distance away from Sun
		- double: Orbit Velocity
		- 2DTexture for Plannet
		- Sprite for Plannet
		- Circle around the sun (how the planet moves around the sun)

		*** For 3D Project (Concern as a Extra Credits work)
		- double: Radius (size)
		- double: Eclipse width and Eclipse height
		- double: Orbit Velocity
		- 2DTexture
		- Sprite
		- Eclipse around the sun (how the planet moves around the sun)

	+ General functions:
		- Draw stars on the screen
		- Making the stars randomly moving
		- Draw Solar system on the screen

	+ Functions for each Planet:
		- Getters and Setters for each variables
		- Draw functions (extends from SFML class Drawable)
		- getCircle (object Planet) -- Tells which circle the planet is on.
		- getVelocity (object Planet) -- Gets Velocity
		- getSize(int radius)  -- Gets size of each planet

Initial Splited Works:

Author: Hung Q Nguyen
	+ Making Initial Objects of planets and its features (movements ...)
	+ Working on Body class

Author: Daniel Santos
	+ Working on SpaceObject and Stars

Together:
	+ We work on the Universe class and Unit Testing together.


* Todo List:
	+ Counting stars base on window size
	+ Making Initial Objects of plannets and its features (movements ...)

Work Done by Daniel Santos:
    + 4/20 - Implemented the header file for the SpaceObject & Star classes.
    + 4/21 - Added a new constructor to the Star class.
