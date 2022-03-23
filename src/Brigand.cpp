// LIBRAIRIES
#include "Brigand.hpp"

// FONCTIONS
Brigand::Brigand(Joueur * joueur, Noeud * noeud)
{
    Meeple::joueur = joueur;
    Meeple::noeud = noeud;
}

Brigand::~Brigand()
{}

/**
 * Algorithme de comptage des points d'un brigand
 *
 * On effectue un parcours d'arbre en deux branches, on va tout à droite puis tout à gauche en collectant les points.
 * - Si on a un nullptr, ca veut dire que le chemin n'est pas fini
 * - Si on a un nombre de route ayant 1 voisins, le chemin est fini et on passe de l'autre sens de puis le noeud noyau.
 *
 * On vérifie au passage si on a une boucle.
 **/
bool Brigand::compter_points(int status_du_jeu, std::map<Joueur *, std::list<Meeple *>> * mapJoueurListeMeeple, int * score)
{
    bool is_complete = true;
    int i;

    *score = this->noeud->get_points(status_du_jeu);

    for(i = 0; i < 2; i++)
    {
        Noeud * noeud_courant = this->noeud->noeud_fils(nullptr, i);
        if(noeud_courant == nullptr)
        {
            return false;
        }
        Noeud * noeud_pere = this->noeud;

        // on continue tant qu'on a un noeud sans fils
        while(noeud_courant->get_nbr_voisins() > 2)
        {
            // Si on a un circuit on a finit le comptage des points
            if(noeud_courant == noeud)
            {
                return is_complete;
            }

            *score = noeud_courant->get_points(status_du_jeu);

            // Si on la route ne se termine pas
            if(!(noeud_courant->has_nullptr()))
            {
                is_complete = false;
                break;
            }

            noeud_courant = noeud_courant->noeud_fils(noeud_pere, 1);
        }
    }

    return is_complete;
}
