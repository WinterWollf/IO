#pragma once

#include "ZarowkaBuilder.h"

class Dyrektor {
private:
    ZarowkaBuilder* builder;
public:
    void setBuilder(ZarowkaBuilder* newBuilder);
    Zarowka* getZarowka() const;
    void constructZarowka();
};