// LIBRAIRIES
#include "Tuile.hpp"

// FONCTIONS
Tuile::Tuile(std::array<Bordure *,4> bordure, std::list<Element *> element)
{
    this->tuilesVoisines = tuilesVoisines;
    this->bordure = bordure;
    this->element = element;
}

Tuile::~Tuile()
{}
