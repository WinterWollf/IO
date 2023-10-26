#include <iostream>
#include <fstream>

class Dane {
	int godziny;
	int minuty;
	int natezenie;
	int temperatura_barwy;
public:
	Dane(int h = 0, int min = 0, int i = 0, int t_b = 0) : godziny(h), minuty(min), natezenie(i), temperatura_barwy(t_b) {}
	void odbierz_dane() {
		//Z pliku .txt
		//godizna = file.godzina;
		//minuta = file.minuta;
	}
};

class Zarowka : public Dane {
public:
	void procedura() {

	}
	int aktualna_godzina(){
	
	}
};


int main() {
	Zarowka sypialnia;

	while (true) {
		sypialnia.procedura();
	}

	return 0;
}