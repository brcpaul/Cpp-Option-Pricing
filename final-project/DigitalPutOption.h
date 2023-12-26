#pragma once
#include "DigitalOption.h"
#include "OptionType.h"

class DigitalPutOption : public DigitalOption {
public:
	DigitalPutOption(double exp, double strk) : DigitalOption(exp, strk){}
	enum optionType GetOptionType() const override;
	double payoff(double);
};