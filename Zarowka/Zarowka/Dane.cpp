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
	in_file.open("dane.txt");

	std::string myline{};
	std::stringstream sstream{};
	int wartosc{};
	int i{ 1 };

	try {
		if (!in_file) {
			throw KomunikacjaNieudana();
		}
	}

	catch (const KomunikacjaNieudana &ex) {
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
					break;
				case 2:
					minuta_zapalenia = wartosc;
					break;
				case 3:
					natezenie = wartosc;
					break;
				case 4:
					temperatura_barwy = wartosc;
					break;
				case 5:
					godzina_zgaszenia = wartosc;
					break;
				case 6:
					minuta_zgaszenia = wartosc;
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