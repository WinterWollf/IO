#include "Dyrektor.h"

void Dyrektor::setBuilder(ZarowkaBuilder* newBuilder) {
    builder = newBuilder;
}

Zarowka* Dyrektor::getZarowka() const {
    return builder->getResult();
}

void Dyrektor::constructZarowka() {
    builder->buildStatus();
    builder->buildProcedure();
    builder->buildDrawing();
}