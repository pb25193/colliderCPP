#include <iostream>
#include "geometry.h"
#include <sstream>

void log(const char* message) {
	std::cout << message << std::endl;
}

void logFloat(const float message) {
	std::cout << message << std::endl;
}

int main() {
	while (true) {
		log("Hello World!");
		Point P = Point(2, 3);
		Point Q = Point(7, 5);
		float distance = l2norm(P, Q);
		float arbit = l2norm(Point(2, 3), 2);
		logFloat(arbit);
		std::cin.get();
	}
}