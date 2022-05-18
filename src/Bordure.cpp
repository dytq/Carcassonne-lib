// LIBRAIRIES
#include "Bordure.hpp"

// FONCTIONS

Bordure::Bordure(Bordure * bordure)
{
    for(int l = 0; l < 3; l++)
    {
        Bordure * bordure_fils_tmp = this->get_bordure_fils(l);
        if(bordure->get_bordure_fils(l)!= nullptr)
        {
            bordure_fils_tmp = new Bordure();
            bordure_fils_tmp->set_type_element(bordure->get_bordure_fils(l)->get_type_element());
            for(int m = 0; m < bordure->get_bordure_fils(l)->get_nbr_voisins(); m++)
            {
                if(bordure->get_bordure_fils(l)->get_voisin(m) == nullptr)
                {
                    bordure_fils_tmp->set_lien(nullptr);
                }
                else 
                {
                    bordure_fils_tmp->set_voisin(bordure->get_bordure_fils(l)->get_voisin(m));
                }
            }
            this->set_bordure_fils(l,bordure_fils_tmp);
        }
    }
}

/**
 * @title: Constructeur d'une bordure
 * */
Bordure::~Bordure()
{
    for(int i = 0; i < 3; i++)
    {
        if(bordureFils[i] != nullptr)
        {
            // Logging::log(Logging::TRACE, "delete bordure fils %d", bordureFils[i]);
            delete bordureFils[i];
        }
    }
}

/**
 * @title: Obtention de la bordure fils
 *
 * @param Indice de la bordure fils doit être en 0 et 3.
 * */
Bordure * Bordure::get_bordure_fils(int indice)
{
    return this->bordureFils[indice];
}

/**
 * @title: Nombre de points de la bordure.
 *
 * @description: Permet de récuperer le nombre de points généré par la bordure.
 * Elle renvoie 0 car il y pas de points attribué pour la bordure
 *
 * @param status_du_jeu
 * @return un score de 0
 * */
int Bordure::get_points(int status_du_jeu)
{
    return 0;
}

/**
 * @title: Définir un type élément à la bordure
 *
 * @param le type de noeud
 * */
void Bordure::set_type_element(Noeud::type_element type_noeud)
{
    Noeud::element = type_noeud;
}

/**
 * @title: Ajout d'une bordure fils.
 *
 * @param indice l'indice de la bordure. L'indice est entre 0 et 3.
 * @param elmement le type élement de la bordure fils
 * */
void Bordure::set_bordure_fils(int indice, Noeud::type_element element)
{
    if(indice >= 0 && indice <= 3) 
    {
        this->bordureFils.at(indice) = new Bordure();
        this->bordureFils.at(indice)->set_type_element(element);
    } 
    else
    {
        Logging::log(Logging::DEBUG, "Impossible de set une bordure fils: l'indice n'est pas comprise entre 0 et 3");
    }
}

void Bordure::set_bordure_fils(int indice, Bordure * bordure_fils)
{
    this->bordureFils[indice] = bordure_fils;
}
