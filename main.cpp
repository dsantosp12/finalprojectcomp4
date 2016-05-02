#include <iostream>
#include <string>
#include <stdexcept>
#include "Universe.hpp"

int main(int argc, char* argv[]) {
	// Check if the parameters input are not enough
	// if (argc <= 1) {
	// 	std::cout << "To Execute: ./orbit [Total Times] [Time per Step]" << std::endl;
	// 	return 0;
	// }

	// // Getting the value from command line.
	// double total_times = (double) std::atoi(argv[1]);
	// double time_per_step = (double) std::atoi(argv[2]);
	int winsize;
	std::cout << "Enter Window Size" << std::endl;
	std::cin >> winsize;

	if (winsize < 100) {
		throw std::invalid_argument("Too Small");
		return 0;
	}

	Universe::Universe universe(winsize);
	universe.run();

	return 0;
}
