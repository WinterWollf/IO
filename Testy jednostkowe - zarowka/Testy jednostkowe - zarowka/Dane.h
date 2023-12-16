#pragma once

class Dane {
protected:
	int godzina_zapalenia;
	int minuta_zapalenia;
	int godzina_zgaszenia;
	int minuta_zgaszenia;
	int natezenie;
	int temperatura_barwy;
public:
	Dane(int h = 0, int min = 0, int i = 0, int t_b = 0);
	~Dane() = default;
	void odbierz_dane();
	int get_godzina_zapalenia();
	int get_minuta_zapalenia();
	int get_godzina_zgaszenia();
	int get_minuta_zgaszenia();
	int get_natezenie();
	int get_temperatura_barwy();
};