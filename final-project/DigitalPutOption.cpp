#include "DigitalPutOption.h"

enum optionType DigitalPutOption::GetOptionType() const
{
    return optionType::Put;
}

double DigitalPutOption::payoff(double price)
{
    if (price <= _strike)
        return 1.0;
    return 0.0;
}