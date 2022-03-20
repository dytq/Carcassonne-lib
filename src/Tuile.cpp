// LIBRAIRIES
#include "Tuile.hpp"

// FONCTIONS
Tuile::Tuile(std::array<Bordure *,4> bordure, std::list<Element *> element)
{
    this->bordure = bordure;
    this->element = element;
}

Tuile::~Tuile()
{}