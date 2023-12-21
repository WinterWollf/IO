#include "Dane.h"
#include "Zarowka.h"
#include "Dyrektor.h"
#include "StandardZarowkaBuilder.h"

int main() {
    Dyrektor dyrektor;
    StandardZarowkaBuilder standardBuilder;

    dyrektor.setBuilder(&standardBuilder);
    dyrektor.constructZarowka();

    Zarowka* zarowka = dyrektor.getZarowka();

    delete zarowka; 

    return 0;
}