// LIBRAIRIES
#include "Noeud.hpp"

// FONCTIONS
/* Ne doit pas être utilisé */
Noeud::Noeud()
{

}

Noeud::~Noeud()
{}


int Noeud::get_points(int status_du_jeu)
{
    Logging::log(Logging::DEBUG, "Un noeud non défini ne donne pas de points");
    return 0;
}

/* Permet de faire une lien sur un seul sens
 *
 * @param Noeud pour établir un lien
 * */
void Noeud::set_lien(Noeud *noeud)
{
    this->noeuds_voisins.push_front(noeud);
}

/**
 * Permet de faire un lien avec un voisin dans les deux sens
 *
 * @param le noeud pour établir un lien
 * */
void Noeud::set_voisin(Noeud *noeud)
{
    this->set_lien(noeud);
    noeud->set_lien(this);
}

/**
 * Permet d'obtenir les fils voisins selon la profondeur.
 * Utilisé pour l'évaluation des points par exemple.
 *
 * @param noeud_pere est le noeud de départ
 * @param profondeur est la profondeur de la liste
 * */
Noeud * Noeud::noeud_fils(Noeud *noeud_pere, int profondeur)
{
    int i = 0;

    for(Noeud * const &itNoeud : this->noeuds_voisins)
    {
        // si le noeud est le pere alors ce n'est pas un fils
        if(itNoeud == noeud_pere){
            i++;
        }

        // on regarde si on a atteins la profondeur de la liste
        if(i == profondeur) {
            return itNoeud;
        }
    }

    Logging::log(Logging::DEBUG, "aucun fils trouvé, trop profond ou le noeud n'a pas de fils, retour nullptr");
    return nullptr;
}

/**
 * Permet de récupérer le nombre de voisins.
 *
 * @return  le nombre de voisins du noeud
 * */
int Noeud::get_nbr_voisins()
{
    return (int) this->noeuds_voisins.size();
}

/**
 * Permet de vérifié si le noeuds est une terminaison fini
 *
 * @return si c'est une terminaisaon pointant vers null
 * */
bool Noeud::has_nullptr()
{
    std::list<Noeud *>::iterator iter = std::find(this->noeuds_voisins.begin(),this->noeuds_voisins.end(), nullptr);
    return iter != this->noeuds_voisins.end();
}

/**
 * Permet de récupérer le type d'élément du noeud
 *
 * @return le type d'élement */
Noeud::type_element Noeud::get_type_element()
{
    return this->element;
}

/**
 * Permet de mettre un type d'élement sur un noeud
 *
 * @param le type d'élément
 * */
void Noeud::set_type_element(Noeud::type_element type)
{
    this->element = type;
}

void Noeud::supprimer_meeple()
{
    Logging::log(Logging::DEBUG, "Le noeud ne represente pas un element");
}

Noeud * Noeud::get_front_voisin()
{
    return this->noeuds_voisins.front();
}
