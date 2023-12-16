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
	Dane(int h = 10, int h_zgasz = 22, int min = 20, int min_zgasz = 25, int i = 65, int t_b = 3300);
	~Dane() = default;
	void odbierz_dane();
};