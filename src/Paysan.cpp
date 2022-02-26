#include "Paysan.hpp"

Paysan::Paysan(Joueur * joueur, Noeud * noeud)
{
    Meeple::joueur = joueur;
    Meeple::noeud = noeud;

}

bool Paysan::compter_points(int status_du_jeu, std::map<Joueur *, std::list<Meeple *>> mapJoueurListeMeeple, int *score)
{

    return true;
}
