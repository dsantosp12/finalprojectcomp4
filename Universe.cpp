#include "Universe.hpp"

/* **********************************
@ Implemented by Hung Q. Nguyen
@ Note:
	+ 4/30: First time Implemented
* ***********************************/
void Universe::Universe::fetchStar() {
	starList_ = new std::Vector<Star*>;
	
	// create stars
	for (int i = 0; i < numStars; i++) {
		// create a default star with none parameters set
		Universe::Star tempStar = new Universe::Star();
		// temp mass of star .. Still wondering why we need mass here for star
		double mass = 0.0;
		starList_.push_back(new Star(tempStar.positionGenerator(),
									 mass, tempStar.radiusGenerator()));
	}
}


/* **********************************
@ Implemented by Hung Q. Nguyen
@ Note:
	+ 4/30: First time Implemented
* ***********************************/
void Universe::Universe::fetchBody() {
	
}
