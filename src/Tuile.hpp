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
        int id_groupe;  // id du groupe de la tuile
        std::array<Bordure *, 4> bordure;
        std::vector<Element *> element;
        
    public:
        // CONSTRUCTEURS
        Tuile(int id, int id_groupe, std::array<Bordure *, 4> bordure, std::vector<Element *> element);
        Tuile(const Tuile & tuile); // clone une tuile

        // DESTRUCTEUR
        ~Tuile();

        // METHODES
        int get_id();
        int get_id_groupe();
        void rotationHoraire();
        Bordure * getBordure(int cote);
        const std::vector<Element *> getElements();
        static std::array<Bordure *, 4> clone_bordure(std::array<Bordure *, 4> bordure);
};

#endif
