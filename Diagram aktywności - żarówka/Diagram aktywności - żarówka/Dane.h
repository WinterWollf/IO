#pragma once

class Dane {
protected:
	int godzina_zapalenia;
	int minuta_zapalenia;
	int godzina_zgaszenia;
	int minuta_zgaszenia;
	int natezenie;
	int temperatura_barwy;
	Dane(int h = 0, int min = 0, int i = 0, int t_b = 0);
	~Dane() = default;
	void odbierz_dane();
};