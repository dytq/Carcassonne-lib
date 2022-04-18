// LIBRAIRIES
#include "Tuile.hpp"

// FONCTIONS
Tuile::Tuile(std::array<Bordure *, 4> bordure, std::list<Element *> element)
{
    this->bordure = bordure;
    this->element = element;
}

Tuile::~Tuile()
{}

void Tuile::rotationHoraire()
{
    std::array<Bordure *, 4> tmp = this->bordure;

    for(int i = 0; i < NBR_ORIENTATIONS_TUILES; i++)
    {
        this->bordure.at(i) = tmp.at((i - 1) % NBR_ORIENTATIONS_TUILES);
    }
}

bool Tuile::borduresCompatibles(Tuile *tuileCompare, int cote)
{
    if((tuileCompare == nullptr) || (this->bordure[cote] == tuileCompare->bordure[(cote + 2) % NBR_ORIENTATIONS_TUILES]))
    {
        return true;
    }

    return false;
}