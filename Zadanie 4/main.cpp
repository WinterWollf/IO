#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Produkt {
	std::string nazwa;
	double cena;
public:
	Produkt(std::string naz_val = "", double cen_val = 0.0) : nazwa(naz_val), cena(cen_val) {}
	std::string get_nazwa() const {
		return nazwa;
	}
	double get_cena() const {
		return cena;
	}
	bool operator<(const Produkt& other) const {
		return cena < other.cena;
	}
};


int main() {
	std::vector<Produkt> produkty;
	std::string nazwa{};
	double cena;

	for (int i{}; i < 10; i++) {
		std::cout << "Wprowadz nazwe produktu: ";
		std::cin >> nazwa;
		std::cout << "Wprowadz cene produktu: ";
		std::cin >> cena;

		produkty.emplace_back(nazwa, cena);
	}

	std::sort(produkty.begin(), produkty.end(), 
		[](const Produkt& a, const Produkt& b) {return a.get_cena() > b.get_cena(); });

	std::cout << std::endl;

	std::cout << "Produkty posortowane po cenie malejaco: " << std::endl;

	for (auto element : produkty)
		std::cout << element.get_nazwa() << ", ";
	std::cout << std::endl;

	return 0;
}