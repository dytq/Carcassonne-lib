// LIBRAIRIES
#include "Moine.hpp"

// FONCTIONS
Moine::Moine(Joueur * joueur, Noeud * noeud, Carte * carte)
{
    Meeple::joueur = joueur;
    Meeple::noeud = noeud;
    this->carte =  carte;
}

Moine::~Moine()
{}

int Moine::compter_points(int status_du_jeu, std::map<Joueur *, std::list<Meeple *>> mapJoueurListeMeeple, int * score)
{
    return 0;
}