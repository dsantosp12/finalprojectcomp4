#include <iostream>
#include <string>
#include <stdexcept>
#include "Universe.hpp"
#include "body.hpp"

#define WIN_SIZE 800

int main(int argc, char* argv[]) {
	// Check if the parameters input are not enough
	 if (argc <= 1) {
	 	std::cout << "To Execute: ./orbit [Total Times] [Time per Step]" << std::endl;
	 	return 0;
	 }

	int number_of_planets;
	std::cin >> number_of_planets;
	double universe_radius;
	std::cin >> universe_radius;
	std::vector<Universe::Body*> planetList;

	for (int i = 0; i < number_of_planets; i++) {
		Universe::Body planet(WIN_SIZE);
		std::cin >> planet;
		std::cout << planet << std::endl;
		planetList.push_back(&planet);
	}

	// Getting the value from command line.
	 double total_times = (double) std::atoi(argv[1]);
	 double time_per_step = (double) std::atoi(argv[2]);

	Universe::Universe universe(WIN_SIZE, planetList);
	universe.run();

	return 0;
}
