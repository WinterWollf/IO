#include <iostream>
#include <vector>

#include "funkcje.h"

int main() {
	std::vector<double> liczby {10, 18, 26, 64, 28, 8, 10, 7, 14};

	std::cout << "ln(100): " << ln(100) << std::endl;
	std::cout << "Odchylenie standardowe: " << standard_deviation(liczby) << std::endl;
	std::cout << "exp(100): " << exponent(100) << std::endl;


	return 0;
}