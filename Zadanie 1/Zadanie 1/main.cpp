#include <iostream>

int main() {

	for (int i{ 300 }; i <= 1200; i++) {
		if (i % 100 == 0) {
			std::cout << i << " *** ";
			if (i % 400 == 0)
				std::cout << std::endl;
		}
		else
			std::cout << i << " ";

	}

	return 0;
}