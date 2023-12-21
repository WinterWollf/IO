#include "StandardZarowkaBuilder.h"

StandardZarowkaBuilder::StandardZarowkaBuilder() {
    zarowka = new Zarowka();
}

void StandardZarowkaBuilder::buildStatus() {
   // zarowka->aktualizacja_stanu();
}

void StandardZarowkaBuilder::buildProcedure() {
    zarowka->porcedura();
}

void StandardZarowkaBuilder::buildDrawing() {
    zarowka->rysuj();
}

Zarowka* StandardZarowkaBuilder::getResult() const {
    return zarowka;
}