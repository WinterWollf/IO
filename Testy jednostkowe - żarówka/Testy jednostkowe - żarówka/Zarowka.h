#pragma once

#include "Dane.h"

class Zarowka : protected Dane {
	bool stan_zapalenia;
public:
	Zarowka(bool status = false);
	~Zarowka() = default;
	void porcedura();
	bool czy_zapalona();
	int aktualna_godzina();
	int aktualna_minuta();
	void aktualizacja_stanu();
	int get_godzina_zapalenia();
	int get_minuta_zapalenia();
	int get_godzina_zgaszenia();
	int get_minuta_zgaszenia();
	int get_natezenie();
	int get_temperatura_barwy();
	void rysuj() const;
};