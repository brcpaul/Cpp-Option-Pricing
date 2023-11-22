#include "DigitalPutOption.h"


/// <summary>
/// 
/// </summary>
enum OptionType DigitalPutOption::GetOptionType() const
{
    return OptionType::Put;
}
/// <summary>
/// 
/// </summary>
/// <param name="price"></param>
/// <returns></returns>
double DigitalPutOption::payoff(double price) const
{
    /*if (strk <= price)
        return 1.0;*/
    return 0.0;
}