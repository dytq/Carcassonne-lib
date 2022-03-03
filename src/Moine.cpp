// LIBRAIRIES
#include "Moine.hpp"

// FONCTIONS
Moine::Moine(Joueur * joueur, Noeud * noeud, Tuile * tuile)
{
    Meeple::joueur = joueur;
    Meeple::noeud = noeud;
    this->tuile = tuile;
}

Moine::~Moine()
{}

bool Moine::compter_points(int status_du_jeu, std::map<Joueur *, std::list<Meeple *>> mapJoueurListeMeeple, int * score)
{
    return 0;
}