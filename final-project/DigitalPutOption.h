#pragma once
#include "DigitalOption.h"
#include "OptionType.h"

class DigitalPutOption : public DigitalOption {
private:
	//DigitalOption* dOption;
public:
	DigitalPutOption(double exp, double strk) : DigitalOption(exp, strk){}
	enum optionType GetOptionType() const;
	double payoff(double) const;
};