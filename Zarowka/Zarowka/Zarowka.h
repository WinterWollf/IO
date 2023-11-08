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
};