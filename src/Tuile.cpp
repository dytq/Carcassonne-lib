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
    // Faire pivoter les bordures de this d'un quart de tour dans le sens horaire
}

bool Tuile::borduresCompatibles(Tuile *tuileCompare, int cote)
{
    /*
    Vérifier que les bordures entre tuileCompare et this soient compatibles selon le côté où se situe tuileCompare
    par rapport à this (en haut = 0, à droite = 1, en bas = 2, à gauche = 3)
    */

    if(tuileCompare == nullptr)
    {
        return true;
    }

    return true;
}
