// LIBRAIRIES
#include "Moine.hpp"

// FONCTIONS
Moine::Moine(Joueur * joueur, Noeud * noeud, std::array<std::array<Tuile *, 144>,144> * etat_du_jeu, std::pair<int,int> position)
{
    Meeple::joueur = joueur;
    Meeple::noeud = noeud;
    this->etat_du_jeu = etat_du_jeu;
    this->position_tuile = position;
}

Moine::~Moine()
{}

bool Moine::compter_points(int status_du_jeu, std::map<Joueur *, std::list<Meeple *>> * mapJoueurListeMeeple, int * score)
{
    return 0;
}
