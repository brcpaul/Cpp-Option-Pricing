#pragma once
#include <random>
class MT {
private:
    std::mt19937 rng; // Instance unique de std::mt19937 // Générateur de nombres aléatoires Mersenne 

public:
    // Fonction pour obtenir l'instance unique de la classe
    static MT & getInstance()
    {
        static MT instance; // Constructed only once
        return instance;
    }

    // Méthodes statiques pour générer des nombres aléatoires
    static double rand_unif();

    static double rand_norm();
};
