#pragma once
#include "DigitalOption.h"
#include "OptionType.h"

class DigitalCallOption : public DigitalOption {
public:
	DigitalCallOption(double exp, double strk) : DigitalOption(exp, strk){}
	enum optionType GetOptionType() const override;
	double payoff(double);
};