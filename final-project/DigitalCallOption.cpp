#include "DigitalCallOption.h"

enum OptionType DigitalCallOption::GetOptionType() const
{
    return OptionType::Call;
}

double DigitalCallOption::payoff(double price) const
{
    /*if (strk >= price)
        return 1.0;*/
    return 0.0;
}