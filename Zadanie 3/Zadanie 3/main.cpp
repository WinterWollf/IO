#include <iostream>

double mile_ladowe(double &km) {
	return km * 0.621371;
}

double mile_morskie(double &km) {
	return km * 0.539956;
}

int main() {
	double km{ 0.0 };

	std::cout << "Prosze podac odleglosc w kilometrach: ";
	std::cin >> km;

	std::cout << km << "km = " << mile_ladowe(km) << " mil ladowych" << std::endl;
	std::cout << km << "km = " << mile_morskie(km) <<  " mil morskich" << std::endl;
	

	return 0;
}