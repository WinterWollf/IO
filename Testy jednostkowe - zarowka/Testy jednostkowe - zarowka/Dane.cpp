#include "Dane.h"
#include "Wyjatki.h"

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

Dane::Dane(int h, int min, int i, int t_b) : godzina_zapalenia(h), godzina_zgaszenia(h), minuta_zapalenia(min), minuta_zgaszenia(min), natezenie(i), temperatura_barwy(t_b) {
	odbierz_dane();
}

void Dane::odbierz_dane() {
	std::ifstream in_file;
	in_file.open("C:\\Users\\wikto\\Desktop\\IO\\Testy jednostkowe - zarowka\\Testy jednostkowe - zarowka\\dane.txt");

	std::string myline{};
	std::stringstream sstream{};
	int wartosc{};
	int i{ 1 };

	try {
		if (!in_file) {
			throw KomunikacjaNieudana();
		}
	}

	catch (const KomunikacjaNieudana& ex) {
		std::cerr << ex.what() << std::endl;
		exit(100);
	}

	while (in_file) {
		std::getline(in_file, myline);
		sstream.clear();
		sstream.str("");
		sstream << myline;
		try {
			if (sstream >> wartosc) {
				switch (i) {
				case 1:
					godzina_zapalenia = wartosc;
					if (godzina_zapalenia < 0 || godzina_zapalenia > 23)
						throw BledneDane();
					break;
				case 2:
					minuta_zapalenia = wartosc;
					if (minuta_zapalenia < 0 || minuta_zapalenia > 59)
						throw BledneDane();
					break;
				case 3:
					natezenie = wartosc;
					if (natezenie < 1 || natezenie > 100)
						throw BledneDane();
					break;
				case 4:
					temperatura_barwy = wartosc;
					if (temperatura_barwy < 0 || temperatura_barwy > 5500)
						throw BledneDane();
					break;
				case 5:
					godzina_zgaszenia = wartosc;
					if (godzina_zgaszenia < 0 || godzina_zgaszenia > 23)
						throw BledneDane();
					break;
				case 6:
					minuta_zgaszenia = wartosc;
					if (minuta_zgaszenia < 0 || minuta_zgaszenia > 59)
						throw BledneDane();
					break;
				default:
					break;
				}
				i++;
			}
			else {
				throw BledneDane();
			}
		}

		catch (const BledneDane& ex) {
			std::cerr << ex.what() << std::endl;
			in_file.close();
			exit(50);
		}
	}

	in_file.close();
}

int Dane::get_godzina_zapalenia() {
	return godzina_zapalenia;
}

int Dane::get_minuta_zapalenia() {
	return minuta_zapalenia;
}

int Dane::get_godzina_zgaszenia() {
	return godzina_zgaszenia;
}

int Dane::get_minuta_zgaszenia() {
	return minuta_zgaszenia;
}

int Dane::get_natezenie() {
	return natezenie;
}

int Dane::get_temperatura_barwy() {
	return temperatura_barwy;
}
