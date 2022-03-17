// DIRECTIVES
#ifndef TUILE_HPP
#define TUILE_HPP

// LIBRAIRIES
#include <array>
#include <list>

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
        Tuile(std::array<Tuile *, 4> tuileVoisines, std::array<Bordure *,4> bordure, std::list<Element *> element);
        Tuile(std::array<Bordure *,4> bordure, std::list<Element *> element);

        // DESTRUCTEUR
        ~Tuile();

        // METHODES
        //std::list<Element *> get_element(Tuile * tuile);
        bool est_vide();
};

#endif