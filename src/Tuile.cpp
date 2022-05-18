// LIBRAIRIES
#include "Tuile.hpp"
#include <array>

// FONCTIONS
/**
 * @title: Constructeur de la Tuile
 *
 * @param: id est l'identifiant de la tuile depuis la base de données
 * @param: bordure est la bordure de la tuile 
 * @param: element est l'ensemble des éléments que compose la tuile
 * */
Tuile::Tuile(int id, std::array<Bordure *, 4> bordure, std::vector<Element *> element)
{
    this->id = id;
    this->bordure = bordure;
    this->element = element;
}


Tuile::Tuile(const Tuile & tuile)
{
    this->id = tuile.id; 
    
    std::array<Bordure *, 4> bordure_tmp;
    bordure_tmp = Tuile::clone_bordure(tuile.bordure);
    
    this->bordure = bordure_tmp;
    
    // TODO clone element
    this->element = tuile.element;
}

std::array<Bordure *, 4> Tuile::clone_bordure(std::array<Bordure *, 4> bordure)
{
    std::array<Bordure *, 4> bordure_tmp;

    for(int k = 0; k < 4; k++)
    {
        Bordure * bordure_tuile_tmp =  bordure[k];
        if(bordure_tuile_tmp != nullptr)
        {
            bordure_tmp[k] = new Bordure(bordure_tuile_tmp);  
        }
    }

    return bordure_tmp;
}

Tuile::~Tuile()
{
    for(Element * element : this->element)
    {
        delete element;
    }
    for(int i = 0; i < 4; i++) 
    {
        if(this->bordure[i] != nullptr)
        {
            // Logging::log(Logging::TRACE, "delete bordure %d", bordure[i]);
            delete this->bordure[i];
        }
    }
}

/**
 * @title: Récupère l'id de la tuile
 * */
int Tuile::get_id()
{
    return this->id;
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