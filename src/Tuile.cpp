// LIBRAIRIES
#include "Tuile.hpp"

// FONCTIONS
Tuile::Tuile(int id, int idTuile, std::array<Bordure *, 4> bordure, std::vector<Element *> element)
{
    this->id = id;
    this->idTuile = idTuile;
    this->bordure = bordure;
    this->element = element;
}

Tuile::~Tuile()
{}

int Tuile::get_id()
{
    return this->id;
}

int Tuile::get_id_groupe()
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

const std::vector<Element *> Tuile::getElements() {
    return this->element;
}



