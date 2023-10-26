#include "Dane.h"

#include <fstream>
#include <string>
#include <sstream>

Dane::Dane(int h, int min, int i, int t_b) : godzina_zapalenia(h), godzina_zgaszenia(h), minuta_zapalenia(min), minuta_zgaszenia(min), natezenie(i), temperatura_barwy(t_b) {
	odbierz_dane();
}

void Dane::odbierz_dane() {
	std::ifstream in_file;
	in_file.open("dane.txt");

	std::string myline{};
	std::stringstream sstream{};
	int value{};
	int i{1};

	if (!in_file) 
		//TODO: throw exception

	while (in_file) {
		std::getline(in_file, myline);
		sstream.clear();
		sstream.str("");
		sstream << myline;
		if (sstream >> value) {
			switch (i) {
			case 1:
				godzina_zapalenia = value;
				break;
			case 2:
				minuta_zapalenia = value;
				break;
			case 3:
				natezenie = value;
				break;
			case 4:
				temperatura_barwy = value;
				break;
			case 5:
				godzina_zgaszenia = value;
				break;
			case 6:
				minuta_zgaszenia = value;
				break;
			default:
				//TODO: throw exception
				break;
			}
			i++;
		}
		else {
			//TODO: throw exception
		}
	}
		
	in_file.close();
}