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

int Brigand::compter_points(int status_du_jeu, std::map<Joueur *, std::list<Meeple *>> mapJoueurListeMeeple, int * score)
{
    return 0;
}