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
Tuile::Tuile(int id, std::array<Bordure *, 4> bordure, std::vector<Element *> element)
{
    this->id = id;
    this->bordure = bordure;
    this->element = element;
}


Tuile::Tuile(const Tuile & tuile)
{
    Logging::log(Logging::DEBUG, "clonnage de la tuile");
    // this->id = tuile.id; 

    /*
    std::array<Bordure *,4> tuile_bordures;
    std::array<Bordure *,3> tuile_bordures_fils;
    std::vector<Noeud *> noeuds_voisins;
    */

    /*
    std::array<Bordure *,4> tuile_bordures;

    for(int i = 0; i < 4; i++)
    {
        std::array<Bordure *,3> tuile_bordures_fils;

        if(tuile.bordure[i] != nullptr)
        {
            for(int j = 0; j < 3; j++)
            {
                if(tuile.bordure[i]->get_bordure_fils(j) != nullptr)
                {
                    std::vector<Noeud *> noeuds_voisins;
                    
                    for(int k = 0; k < tuile.bordure[i]->get_bordure_fils(j)->get_nbr_voisins(); k++)
                    {
                        noeuds_voisins.push_back(tuile.bordure[i]->get_bordure_fils(j)->get_voisin(k));
                    }

                    bordure_fils->set_noeud_voisins(noeuds_voisins);

                    tuile_bordures_fils[j] = bordure_fils;
                }
                else
                {
                    tuile_bordures_fils[j] = nullptr;
                }
            }

            tuile_bordures[i]->set_BordureFils(tuile_bordures_fils);
        }
            
    }

    /*
    for(int i = 0; i < 4; i++)
    {
        Bordure * bordure_clone = tuile_clone.bordure[i];

        if(bordure_clone != nullptr)
        {
            std::array<Bordure *,3> tuile_bordure_fils;
            
            for(int j = 0; j < 3; j++)
            {
                Bordure * bordure_fils = tuile.bordure[i]->get_BordureFils()[j];

                tuile_bordure_fils[j] = bordure_fils;
                
                std::vector<Noeud *> noeuds_voisins;
                
                for(int k = 0; k < bordure_fils->get_nbr_voisins(); k++)
                {
                    noeuds_voisins.push_back(bordure_fils->get_voisin(k));
                }

                bordure_clone->get_bordure_fils(j)->set_noeud_voisins(noeuds_voisins);
            }
            bordure_clone->set_BordureFils(tuile_bordure_fils);
        }
        
        tuile_bordure[i] = bordure_clone;
    }
    */

    //this->bordure = tuile_bordures;

    // this->element = tuile.element;
}

Tuile::~Tuile()
{
    /*
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
    */
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