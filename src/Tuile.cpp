// LIBRAIRIES
#include "Tuile.hpp"

// FONCTIONS
Tuile::Tuile(std::array<Tuile *, 4> tuilesVoisines, std::array<Bordure *,4> bordure, std::list<Element *> element)
{
    this->tuilesVoisines = tuilesVoisines;
    this->bordure = bordure;
    this->element = element;
}

Tuile::Tuile(std::array<Bordure *,4> bordure, std::list<Element *> element)
{
    std::array<Tuile *, 4> tmp;

    for(int i = 0; i < 4; i++)
    {
        tmp[i] = NULL;
    }

    this->tuilesVoisines = tmp;
    this->bordure = bordure;
    this->element = element;
}

Tuile::~Tuile()
{}