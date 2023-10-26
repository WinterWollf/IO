#pragma once

#include "Dane.h"

class Zarowka : protected Dane {
	bool stan_zapalenia{ false };



public:
	Zarowka(bool status = false);
	~Zarowka() = default;
	bool czy_zapalona() const ;
};