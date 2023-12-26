#include "PutOption.h";


/// <summary>
/// optionType PutOption to associate the type Put at the Option
/// </summary>
enum optionType PutOption::GetOptionType() const
{
    return optionType::Put;
}


/// <summary>
/// PutOption function in order to calculate the payoff fo a put option
/// </summary>
/// <param name="price"> a double : price of the option, (price = z in the statement) </param>
/// <returns> the payoff of the function </returns>
double PutOption::payoff(double price)
{
    if (_strike >= price)
        return _strike - price;
    else return 0.0;
}