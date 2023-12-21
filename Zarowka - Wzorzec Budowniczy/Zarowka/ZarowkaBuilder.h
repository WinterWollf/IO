#pragma once

#include "Zarowka.h"

class ZarowkaBuilder {
protected:
    Zarowka* zarowka;
public:
    virtual ~ZarowkaBuilder() = default;
    virtual void buildStatus() = 0;
    virtual void buildProcedure() = 0;
    virtual void buildDrawing() = 0;
    virtual Zarowka* getResult() const = 0;
};