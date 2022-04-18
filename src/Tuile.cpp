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
    Bordure *tmp = this->bordure[0];

    for(int i = 0; i < (NBR_ORIENTATIONS_TUILES - 1); i++)
    {
        this->bordure[i] = this->bordure[i + 1];
    }

    this->bordure[NBR_ORIENTATIONS_TUILES - 1] = tmp;
}

bool Tuile::borduresCompatibles(Tuile *tuileCompare, int cote)
{
    if((tuileCompare == nullptr) || (this->bordure[cote] == tuileCompare->bordure[(cote + 2) % NBR_ORIENTATIONS_TUILES]))
    {
        return true;
    }

    return false;
}
