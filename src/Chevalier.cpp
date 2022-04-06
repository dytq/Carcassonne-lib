// LIBRAIRIES
#include "Chevalier.hpp"

// FONCTIONS
Chevalier::Chevalier(Joueur * joueur, Noeud * noeud)
{
    Meeple::joueur = joueur;
    Meeple::noeud = noeud;
}

Chevalier::~Chevalier()
{}

/**
 * Algorithme du comptage des points pour le Chevalier.
 *
 * Parcours du réseau de noeuds en profondeur.
 **/
bool Chevalier::compter_points(int status_du_jeu, std::map<Joueur *, std::list<Meeple *>> * mapJoueurListeMeeple, int * score)
{
    std::list<Noeud*> pileNoeud;   // pile pour le parcours des fils
    std::list<Noeud*> noeudMarque; // marque tous les noeuds rencontrés

    bool isComplete = true;

    *score = this->noeud->get_points(status_du_jeu);
    pileNoeud.push_back(this->noeud);
    noeudMarque.push_back(this->noeud);

    while(!pileNoeud.empty())
    {
        std::list<Noeud*>::iterator iterNoeud = pileNoeud.begin();

        Noeud * noeudCentrale = *iterNoeud;
        pileNoeud.pop_front();

        int i;

        for(i = 0; i < noeudCentrale->get_nbr_voisins(); i++)
        {
            Noeud * noeud_fils = noeudCentrale->noeud_fils(nullptr, i);

            if(noeudCentrale->has_nullptr())
            {
                isComplete = false;
            }

            if(std::find(noeudMarque.begin(), noeudMarque.end(), noeud_fils) == noeudMarque.end())
            {
                noeudMarque.push_back(noeud_fils);
                pileNoeud.push_back(noeud_fils);
                *score = noeud_fils->get_points(status_du_jeu);
            }
        }
    }

    return isComplete;
}