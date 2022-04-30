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
        int idTuile;    // id du groupe
        int id;         // id de la tuile
        std::array<Bordure *, 4> bordure;
        std::vector<Element *> element;
        
    public:
        // CONSTRUCTEURS
        Tuile(int id, int idTuile, std::array<Bordure *, 4> bordure, std::vector<Element *> element);

        // DESTRUCTEUR
        ~Tuile();

        // METHODES
        int get_id();
        int get_id_groupe();
        void rotationHoraire();
        bool borduresCompatibles(Tuile *tuileCompare, int cote);
        Bordure * getBordure(int cote);
        std::vector<Element *> getElements();
};

#endif