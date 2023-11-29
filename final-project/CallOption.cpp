#include "CallOption.h"

/// <summary>
/// OptionType CallOption to associate the type Call at the Option
/// </summary>
enum OptionType CallOption::GetOptionType() const {
    return OptionType::Call;
}


/// <summary>
/// CallOption function in order to calculate the payoff for a call option
/// </summary>
/// <param name="price"> a double : price of the option, (price = z in the statement) </param>
/// <returns> the payoff of the function </returns>
double CallOption::payoff(double price) const
{
    if (price >= _strike) 
        return price - _strike;
    else
        return 0.0;
}