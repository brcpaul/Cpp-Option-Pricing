#include "DigitalPutOption.h"
/// <summary>
/// Returns the type of the digital option : here returns Put
/// </summary>
enum OptionType DigitalPutOption::GetOptionType() const
{
    return OptionType::Put;
}
/// <summary>
/// Digital Put Option's method which caclulates the payoff of the option
/// </summary>
/// <param name="price">The current price of the underlying asset</param>
/// <returns>The payoff of the digital put option</returns>
double DigitalPutOption::payoff(double price) const
{
    /*if (strk <= price)
        return 1.0;*/
    return 0.0;
}