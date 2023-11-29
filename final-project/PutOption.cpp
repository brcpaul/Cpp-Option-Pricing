#include "PutOption.h";


/// <summary>
/// OptionType PutOption to associate the type Put at the Option
/// </summary>
enum OptionType PutOption::GetOptionType() const
{
    return OptionType::Put;
}


/// <summary>
/// PutOption function in order to calculate the payoff fo a put option
/// </summary>
/// <param name="price"> a double : price of the option, (price = z in the statement) </param>
/// <returns> the payoff of the function </returns>
double PutOption::payoff(double price) const
{
    if (valeurStrike >= price)
        return valeurStrike - price;
    else return 0.0;
}