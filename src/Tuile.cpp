// LIBRAIRIES
#include "Tuile.hpp"

// FONCTIONS
Tuile::Tuile(int idTuile, std::array<Bordure *, 4> bordure, std::list<Element *> element)
{
    this->idTuile = idTuile;
    this->bordure = bordure;
    this->element = element;
}

Tuile::~Tuile()
{}

int Tuile::getId()
{
    return this->idTuile;
}

void Tuile::rotationHoraire()
{
    Bordure *tmp = this->bordure[0];
    
    int k = 3;
    
    for(int i = 0; i < (NBR_ORIENTATIONS_TUILES - 1); i++)
    {
        this->bordure[(k + 1) % 4] = this->bordure[(k) % 4];
        k--;
    }

    this->bordure[1] = tmp;
}

bool Tuile::borduresCompatibles(Tuile *tuileCompare, int cote)
{
    if((tuileCompare == nullptr) || (this->bordure[cote] == tuileCompare->bordure[(cote + 2) % NBR_ORIENTATIONS_TUILES]))
    {
        return true;
    }

    return false;
}

Bordure * Tuile::getBordure(int cote) {
    return this->bordure[cote];
}

std::list<Element *> Tuile::getElements() {
    return this->element;
}



