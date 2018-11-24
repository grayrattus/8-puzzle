#include <Arguments.hpp>
#include <iostream>

int main(int argc, char *argv[]) {
	Arguments a(argc, argv);
	auto algorightm = a.getAlgorithm();
	auto sol = algorightm->performSearch();
	a.writeSolutionToFiles(sol);
	return 0;
}
