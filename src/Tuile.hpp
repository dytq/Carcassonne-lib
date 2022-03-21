// DIRECTIVES
#ifndef TUILE_HPP
#define TUILE_HPP

// LIBRAIRIES
#include <array>
#include <list>
#include <vector>

#include "Bordure.hpp"
#include "Element.hpp"

// CLASSE
class Tuile
{
    private:
        // VARIABLES
        std::array<Bordure *,4> bordure;
        std::list<Element *> element;

    public:
        // CONSTRUCTEURS
        Tuile(std::array<Bordure *,4> bordure, std::list<Element *> element);

        // DESTRUCTEUR
        ~Tuile();

        // METHODES
        std::vector<Element *> get_element(Tuile * tuile);
        bool est_vide();
};

#endif
