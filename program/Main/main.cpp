#include <Arguments.hpp>
#include <iostream>

int main(int argc, char *argv[]) {
	// std::cout << argv[0] << '\n';
	// std::cout << argv[1] << '\n';
	// std::cout << argv[2] << '\n';
	// std::cout << argv[3] << '\n';
	// std::cout << argv[4] << '\n';
	// std::cout << argv[5] << '\n';
	Arguments a{argc, argv};
	auto algorightm = a.getAlgorithm();
	auto sol = algorightm->performSearch();
	a.writeSolutionToFiles(sol);
	return 0;
}
