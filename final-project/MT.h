#pragma once
#include <random>
class MT {
private:
    std::mt19937 rng; // Instance unique de std::mt19937 // Générateur de nombres aléatoires Mersenne Twister

    // Constructeur privé pour empêcher l'instanciation directe
    MT();

public:
    // Fonction pour obtenir l'instance unique de la classe
    static MT & getInstance()
    {
        static MT instance; // Constructed only once
        return instance;
    }

    // Méthodes statiques pour générer des nombres aléatoires
    static double rand_unif()
    {
        std::uniform_real_distribution<double> dist(0.0, 1.0);
        return dist(getInstance().rng);
    }

    static double rand_norm()
    {
        std::normal_distribution<double> dist(0.0, 1.0);
        return dist(getInstance().rng);
    }
};
