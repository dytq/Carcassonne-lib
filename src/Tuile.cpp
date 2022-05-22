// LIBRAIRIES
#include "Tuile.hpp"

// FONCTIONS
/**
 * @title: Constructeur de la Tuile
 *
 * @param: id est l'identifiant de la tuile depuis la base de données
 * @param: bordure est la bordure de la tuile 
 * @param: element est l'ensemble des éléments que compose la tuile
 * */
Tuile::Tuile(int id, int id_groupe, std::array<Bordure *, 4> bordure, std::vector<Element *> element)
{
    this->id = id;
    this->id_groupe = id_groupe;
    this->bordure = bordure;
    this->element = element;
}

Tuile::Tuile(const Tuile & tuile)
{
    Logging::log(Logging::DEBUG, "clonnage de la tuile");
    this->id = tuile.id; 
    this->id_groupe = tuile.id_groupe;
    this->bordure = tuile.bordure;
    this->element = tuile.element;
}

Tuile::~Tuile()
{
    
}

/**
 * @title: Récupère l'id de la tuile
 * */
int Tuile::get_id()
{
    return this->id;
}

/**
 * @title: Récupère l'id_groupe de la tuile
 * */
int Tuile::get_id_groupe()
{
    return this->id_groupe;
}

/**
 * @title: Fait une rotation logique horaire de la tuile
 * */
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

/**
 * @title: Récupère la bordure fils
 * 
 * @return: bordure fils
 * */
Bordure * Tuile::getBordure(int cote) 
{
    return this->bordure[cote];
}

/**
 * @title: Récupère les éléments de la tuile
 * 
 * @return: les éléments
 * */
const std::vector<Element *> Tuile::getElements() {
    return this->element;
}