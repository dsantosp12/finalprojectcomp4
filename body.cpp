#include "body.hpp"

const double G = 6.67e-11;
const double E = 1e+9;

Universe::Body::Body (int window_size)
	: wSize_(window_size) {

}

Universe::Body::Body (sf::Vector2f initial_pos, sf::Vector2u velocity,
	  sf::Texture texture, double mass)
	: SpaceObject (initial_pos, velocity, mass), pTexture_(texture) {
	// Get texture and Sprite
	createBodyTexture();
	createBodySprite();
}

Universe::Body::~Body () {}

void Universe::Body::createBodyTexture() {
	pTexture_.loadFromFile(file_name);
}

void Universe::Body::createBodySprite() {
	pSprite_.setTexture(pTexture_);
}

void Universe::Body::calDistanceToSun() {
	// calculate the distance to sun -- xpos only
	double distane = x_pos / (1e+9);
	// Set the value to local variable
	setDistanceToSun(distane);
}

void Universe::Body::calCenterLocation (
	double window_width, double window_height) {
	x_center = window_width / 2;
	y_center = window_height / 2;
}

void Universe::Body::updatePosition () {
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

double Universe::Body::calNetforce(
	double radius, double planet1_mass, double planet2_mass) {
	double netForce = 0.0;

	if (radius < 1)
		return -1;
	// F = Gm1m2 / r^2
	// calculate the value of netforce with pure calculation
	netForce = (G * planet1_mass * planet2_mass) / (radius * radius);

	return netForce;
}

void Universe::Body::updateVelocity(double times, double accel) {
	x_vel = x_vel + accel * times;
	y_vel = y_vel - accel * times;
}

// void Universe::Body::updatePosition() {
// 	// Update position
// 	// Update new Position from radius to the sun and the
// 	// coordinate of the sun
// 	x_pos = distanceToSun + x_center;
// 	y_pos = (y_pos / E) + y_center;
// }

void Universe::Body::step(double times) {
	// Update position from step
	x_pos = x_pos + (x_vel * times);
	y_pos = y_pos + (y_vel * times);
}

void Universe::Body::draw(sf::RenderTarget &target,
                          sf::RenderStates states) const {
  target.draw(pSprite_, states);
}

std::string Universe::Body::getPlanetName() {
	std::string name = "";
	std::string::iterator itr = planet_name_.begin();

	name += toupper(*itr);
	++itr;

	while (itr != planet_name_.end()) {
		if (*itr != '.') {
			name += *itr;
		} else {
			break;
		}
		++itr;
	}
	return name;
}