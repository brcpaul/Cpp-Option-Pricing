#pragma once
#include "Option.h"
#include "OptionType.h"

class AmericanOption: public Option
{
private: 
    double _strike;
public:
    friend class AmericanCallOption;
    friend class AmericanPutOption;

    AmericanOption(double expiry, double strike) : Option(expiry), _strike(strike) {} 

    bool isAmericanOption() override;

};