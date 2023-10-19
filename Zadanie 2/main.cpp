#include <iostream>
#include <vector>

int main() {

	int tab[10]{};
	std::vector<int> ujemne{};

	std::cout << "Wprowadz liczby: " << std::endl;
	for (int i{ 0 }; i < 10; i++) {
		std::cin >> tab[i];
	}
	for (int i{ 0 }; i < 10; i++) {
		if (tab[i] < 0) 
			ujemne.push_back(tab[i]);
	}

	std::cout << std::endl;

	std::cout << "Liczy ujemne: " << std::endl;
	for (auto element : ujemne) {
		std::cout << element << ", ";
	}

	std::cout << std::endl;

	std::cout << "Ilosc liczb ujemnych: " << ujemne.size() << std::endl;
	std::cout << "Ilosc ominietych elementow: " << 10 - ujemne.size() << std::endl;

	return 0;
}