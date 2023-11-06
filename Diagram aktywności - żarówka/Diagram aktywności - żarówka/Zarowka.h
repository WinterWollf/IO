#pragma once

#include "Dane.h"

class Zarowka : protected Dane {
	bool stan_zapalenia;
public:
	Zarowka(bool status = false);
	~Zarowka() = default;
	void porcedura();
	bool czy_zapalona() const;
	int aktualna_godzina() const;
	int aktualna_minuta() const;
};