// DIRECTIVES
#ifndef BORDURE_HPP
#define BORDURE_HPP

// LIBRAIRIES
#include <array>

#include "Noeud.hpp"

// CLASSE
class Bordure : Noeud
{
    private:
        // VARIABLES
        Noeud::type_element type_noeud;
        std::array<Bordure *,3> bordureFils;

    public:
        // CONSTRUCTEURS
        Bordure(Noeud::type_element type_noeud);

        // DESTRUCTEUR
        ~Bordure();

        // METHODES
        std::array<Bordure *,3> get_bordure_fils();
        void set_bordure_fils(std::array<Bordure*,3> bordureFils);
};

#endif