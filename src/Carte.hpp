// DIRECTIVES
#ifndef CARTE_HPP
#define CARTE_HPP

// LIBRAIRIES
#include <array>
#include <list>

#include "Bordure.hpp"
#include "Element.hpp"

// CLASSE
class Carte
{
    private:
        // VARIABLES
        std::array<Carte*,4> carteVoisines;
        std::array<Bordure *,4> bordure;
        std::list<Element *> element;

    public:
        // CONSTRUCTEURS
        Carte(std::array<Carte *, 4> carteVoisines, std::array<Bordure *,4> bordure, std::list<Element *> element);

        // DESTRUCTEUR
        ~Carte();

        // METHODES
        //std::list<Element *> get_element(Carte * carte);
        bool est_vide();
};

#endif
