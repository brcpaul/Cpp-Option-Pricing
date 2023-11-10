//#pragma once
//#include <stdexcept>
//#include <iostream>
//#include <cmath>
//
//class Option {
//
//private:
//    double expiry;
//
//public:
//    Option(double valeur) :expiry(valeur) {  }   // Constructor.
//    virtual double payoff(double);
//    double getExpiry(){
//        return expiry;
//    }
//    virtual OptionType GetOptionType() const = 0; // Pure virtual method
//};
//
//class VanillaOption : public Option
//{
//
//private:
//    double strike;
//    OptionType optionType;
//
//public:
//    friend class BlackScholesPricer;
//    VanillaOption(double exp, double str) : Option(exp), strike(str)
//    {
//        if (exp < 0 || str < 0) {
//            std::cout <<"Expiry and strike must be nonnegative.";
//        }
//        strike = str;
//    }
//    enum OptionType GetOptionType() const override { //voir redaction enum
//        return optionType;
//    }
//    
//    double GetStrike() {
//        return strike;
//    }
//};
//
//enum class OptionType
//{
//    Call, Put
//};
//
//
//
//class CallOption : public VanillaOption
//{
//public:
//    CallOption(double expiry, double strike) : VanillaOption(expiry, strike){} //meme nom de valeur ou non ?
//
//    enum OptionType GetOptionType() const override{
//        return OptionType::Call;
//    }
//
//    double valeurStrike = GetStrike(); //poser question prof pour accessibilité de strike et expiry
//    double payoff(double price) const
//    {
//        // Implement the payoff calculation for a call option
//        if (price >= valeurStrike) //price = z
//            return price - valeurStrike;
//        else
//            return 0.0;
//    }
//
//};
//
//class PutOption : public VanillaOption
//{
//public:
//    PutOption(double expiry, double strike) : VanillaOption(expiry, strike) {}
//
//    enum OptionType GetOptionType() const
//    {
//        return OptionType::Put;
//    }
//
//    double valeurStrike = GetStrike();
//    double payoff(double price) const
//    {
//        // Implement the payoff calculation for a pull option
//        if (valeurStrike >= price)
//            return valeurStrike - price;
//        else return 0.0;
//    }
//};
//
//
//
//class BlackScholesPricer {
//private:
//    VanillaOption* option;
//    double asset_price;
//    double interest_rate;
//    double volatility;
//
//public:
//    BlackScholesPricer(VanillaOption* option, double asset_price, double interest_rate, double volatility)
//        : option(option), asset_price(asset_price), interest_rate(interest_rate), volatility(volatility) {}
//
//    
//        double valeur = Option::getExpiry();//erreur accessibilité
//        double operator()() {
//        double S = asset_price;
//        double K = option->strike;
//        double T = valeur;
//        double r = interest_rate;
//        double sigma = volatility;
//
//        double d1 = (log(S / K) + (r + (sigma * sigma) / 2.0) * T) / (sigma * sqrt(T));
//        double d2 = d1 - sigma * sqrt(T);
//
//        if (option->GetOptionType() == OptionType::Call) {
//            return S * std::exp(-r * T) * (1 - std::erfc(-d2) / 2);
//        }
//        else {
//            return S * std::exp(-r * T) * (1 + std::erfc(d2) / 2);
//        }
//    }
//
//    double delta() {
//        double S = asset_price;
//        double K = option->strike;
//        double T = option->expiry;//erreur accessibilité
//        double r = interest_rate;
//        double sigma = volatility;
//
//        double d1 = (log(S / K) + (r + (sigma * sigma) / 2.0) * T) / (sigma * sqrt(T));
//
//        if (option->GetOptionType() == OptionType::Call) {
//            return std::exp(-r * T) * std::erfc(-d1) / 2;
//        }
//        else {
//            return std::exp(-r * T) * (std::erfc(d1) / 2 - 1);
//        }
//    }
//};
//
//
//
//
