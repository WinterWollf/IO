#pragma once

#include "ZarowkaBuilder.h"

class StandardZarowkaBuilder : public ZarowkaBuilder {
public:
    StandardZarowkaBuilder();
    ~StandardZarowkaBuilder() = default;
    void buildStatus() override;
    void buildProcedure() override;
    void buildDrawing() override;
    Zarowka* getResult() const override;
};