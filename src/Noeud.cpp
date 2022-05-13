// LIBRAIRIES
#include "Noeud.hpp"

// FONCTIONS
Noeud::Noeud()
{
    /* Ne doit pas être utilisé */
}

Noeud::~Noeud()
{}

/**
 * @title: Récupère le nombre de points 
 * 
 * @description: une noeud ne retourne pas de points
 * 
 * @param: status du jeu pour évaluer le nombre de points 
 * */
int Noeud::get_points(int status_du_jeu)
{
    Logging::log(Logging::DEBUG, "Un noeud non défini ne donne pas de points");
    return 0;
}

/* @title: Établissement d'un lien d'un noeud vers un seul sens
 *
 * @param Noeud pour établir un lien
 * */
void Noeud::set_lien(Noeud *noeud)
{
    this->noeuds_voisins.push_back(noeud);
}

/**
 * @title: Établissement d'un lien avec un voisin dans les deux sens
 *
 * @param le noeud pour établir un lien
 * */
void Noeud::set_voisin(Noeud *noeud)
{
    this->set_lien(noeud);
    noeud->set_lien(this);
}

/**
 * @title: Récupérer le nombre de voisins.
 *
 * @return le nombre de voisins du noeud
 * */
int Noeud::get_nbr_voisins()
{
    return (int) this->noeuds_voisins.size();
}

/**
 * @title: Vérifie si le noeuds est une terminaison fini
 *
 * @return si c'est une terminaisaon pointant vers null
 * */
bool Noeud::has_nullptr()
{
    std::vector<Noeud *>::iterator iter = std::find(this->noeuds_voisins.begin(),this->noeuds_voisins.end(), nullptr);
    return iter != this->noeuds_voisins.end();
}

/**
 * @title: Récupérer le type d'élément du noeud
 *
 * @return le type d'élement 
 **/
Noeud::type_element Noeud::get_type_element()
{
    return this->element;
}

/**
 * @title: Mettre un type d'élement sur un noeud
 *
 * @param le type d'élément
 * */
void Noeud::set_type_element(Noeud::type_element type)
{
    this->element = type;
}

/**
 * @title: Supprime un meeple, ne doit pas être utilisé par Noeud
 * */
void Noeud::supprimer_meeple()
{
    Logging::log(Logging::DEBUG, "Le noeud ne represente pas un element");
}

/**
 * @title: Récupère le noeud voisin selon l'indice
 * */
Noeud * Noeud::get_voisin(int index)
{
    return this->noeuds_voisins[index];
}

// supprime en fonction de l'addresse du noeuds donner en param, si le noeud est null, il suprime le noeud null
void Noeud::remove_tuile_voisin(Noeud * noeud)
{
    for(int i = 0; i < (int) this->noeuds_voisins.size(); i++)
    {
        if(this->noeuds_voisins[i] == noeud)
        {
            this->noeuds_voisins.erase(this->noeuds_voisins.begin() + i);
            return;
        }
    }
}

/**
 * @title: Compare le type d'élément
 *
 * @description: Comparaison des types d'éléments pour le parcours et création du graphe
 *
 * @param: type_element1 est le type du premier élément
 * @param: type_element2 est le type du deuxième élément
 *
 * @return: si les éléments sont de même type
 * */
bool Noeud::compare_type_element(Noeud::type_element type_element1, Noeud::type_element type_element2) 
{
    if(type_element1 == type_element2) {
        return true;
    } else {
        if(type_element1 == Noeud::VILLE || type_element1 == Noeud::VILLE_BLASON) // ville est de même type que ville blason
        {
            if(type_element2 == Noeud::VILLE || type_element2 == Noeud::VILLE_BLASON) 
            {
                return true;
            }
        }
    }
    return false;
}
