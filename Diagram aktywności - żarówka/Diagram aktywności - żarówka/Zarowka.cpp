#include "Zarowka.h"

Zarowka::Zarowka(bool status) : stan_zapalenia(status) {}

bool Zarowka::czy_zapalona() const {
	if (stan_zapalenia == true)
		return true;
	else
		return false;
}
