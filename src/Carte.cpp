// LIBRAIRIES
#include "Carte.hpp"

// FONCTIONS
Carte::Carte(std::array<Carte *, 4> carteVoisines, std::array<Bordure *,4> bordure, std::list<Element *> element)
{
    this->carteVoisines = carteVoisines;
    this->bordure = bordure;
    this->element = element;
}

Carte::~Carte()
{}
