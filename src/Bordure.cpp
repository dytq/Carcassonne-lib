// LIBRAIRIES
#include "Bordure.hpp"

// FONCTIONS

Bordure::~Bordure()
{}

/**
 * Permet de récupérer la bordure fils.
 *
 * @param l'indice de la bordure
 * */
Bordure * Bordure::get_bordure_fils(int indice)
{
    return this->bordureFils[indice];
}

/**
 * Permet de récuperer le nombre de points généré par la bordure.
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
 * Permet de mettre un type élément à la bordure
 *
 * @param le type de noeud
 * */
void Bordure::set_type_element(Noeud::type_element type_noeud)
{
    Noeud::element = type_noeud;
}

/**
 * Permet d'établir une bordure fils.
 *
 * @param indice l'indice de la bordure. L'indice est entre 0 et 3.
 * @param elmement le type élement de la bordure fils
 * */
void Bordure::set_bordure_fils(int indice, Noeud::type_element element)
{
    if(indice >= 0 && indice <= 3) {
        this->bordureFils.at(indice) = new Bordure();
        this->bordureFils.at(indice)->set_type_element(element);
    } else
    {
        Logging::log(Logging::DEBUG, "Impossible de set une bordure fils: l'indice n'est pas comprise entre 0 et 3");
    }
}