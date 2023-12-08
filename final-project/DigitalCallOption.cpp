#include "DigitalCallOption.h"
/// <summary>
/// Returns the type of the digital option : here returns Call
/// </summary>
enum optionType DigitalCallOption::GetOptionType() const
{
    return optionType::Call;
}
/// <summary>
/// Digital Call Option's method which caclulates the payoff of the option
/// </summary>
/// <param name="price">The current price of the underlying asset</param>
/// <returns>The payoff of the digital call option</returns>
double DigitalCallOption::payoff(double price) const
{
    if (price >= _strike)
        return 1.0;
    return 0.0;
}