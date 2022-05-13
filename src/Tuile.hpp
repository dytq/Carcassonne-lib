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
        int id;         // id de la tuile
        std::array<Bordure *, 4> bordure;
        std::vector<Element *> element;
        
    public:
        // CONSTRUCTEURS
        Tuile(int id, std::array<Bordure *, 4> bordure, std::vector<Element *> element);
        Tuile(const Tuile & tuile); // clone une tuile

        // DESTRUCTEUR
        ~Tuile();

        // METHODES
        int get_id();
        void rotationHoraire();
        Bordure * getBordure(int cote);
        const std::vector<Element *> getElements();
};

#endif
