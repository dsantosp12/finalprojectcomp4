#include <iostream>
#include <SFML/Audio>
#include <SFML/Graphics>
#include <SFML/Windows>
#include <SFML/System>
#include "body.hpp"

#define G 6.67e-11

Universe::Body (sf::Vector2f initial_pos, sf::Vector2u velocity, 
	  sf::Texture texture, double mass)
	: SpaceObject (initial_pos, velocity, mass), planet_texture(textures) {

	  }

Universe::~Body () {

}

sf::Vector2f Universe::calNetforce(double times) {

}

void Universe::createBodyTexture() {
	sf::Texture newTexture;
	// temporary created a texture with size 400x400
	if (!newTexture.create(400,400)) {
		return -1;
	}

	// temporary loaded the texture with given filename
	newTexture.loadFromFile(file_name, sf::IntRect(10, 10, 32,32));

	// set Smooth for the textire
	newTexture.setSmooth(true);

	// don't set repeated
	newTexture.setRepeated(false);

	// Set the texture to local variable
	setBodyTexture(newTexture);
}

void Universe::createBodyTexture() {
	sf::Sprite newSprite;
	sf::Texture current = getBodyTexture();

	// Set texture to the new Sprite
	newSprite.setTexture(current);

	// Set Color
	newSprite.setColor(sf::Color::White);

	// Set initial Position
	newSprite.Position(sf::Vector2f(x_pos, y_pos));

	// Update the texture to local variable
	setBodySprite(newSprite);
}

void Universe::calDistanceToSun() {
	// calculate the distance to sun -- xpos only
	double distane = x_pos / (1e+9);
	// Set the value to local variable
	setDistanceToSun(distane);
}

void Universe::calCenterLocation(double window_width, double window_height) {
	x_center = window_width / 2;
	y_center = window_height / 2;
}

void Universe::updatePosition() {
	// If the planet is moving at IV quad
	if (x_pos >= x_center && y_pos <= y_center) {
		x_pos -= x_vel;
		y_pos -= y_vel;
	}

	// IF the planet is moving at I quad
	if (x_pos <= x_center && y_pos <= y_center) {
		x_pos -= x_vel;
		y_pos += y_vel;
	}

	// If the planet is moving at II quad
	if (x_pos <= x_center && y_pos >= y_center) {
		x_pos += x_vel;
		y_pos += y_vel;
	}

	// If the planet is moving at III quad
	if (x_pos <= x_center && y_pos >= y_center) {
		x_pos += x_vel;
		y_pos -= y_vel;
	}
}

double Universe::calNetforce(double radius, double planet1_mass, double planet2_mass) {
	double netForce = 0.0;

	if (radius < 1)
		return -1;
	// F = Gm1m2 / r^2
	netForce = (F * planet1_mass * planet2_mass) / (radius ^ 2);

	return netForce;
}

