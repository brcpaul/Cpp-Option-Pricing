#pragma once
#include "Option.h"
#include "OptionType.h"

class AmericanOption: public Option
{
public:
    AmericanOption(double expiry, double strike) : Option(expiry) {
    } 

    bool isAmericanOption() override;

};