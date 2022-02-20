// LIBRAIRIES
#include "Joueur.hpp"

// FONCTIONS
Joueur::Joueur(Type_joueur type_joueur)
{

}

std::string Joueur::get_nom()
{
    return nullptr;
}

void Joueur::set_nom(std::string nom)
{

}

void Joueur::poser_meaples(Carte * carte, Element * element)
{

}

int Joueur::get_score()
{
    return 0;
}

void Joueur::ajouter_points(int points)
{

}

const std::list<Meeple *> Joueur::list_meeple()
{
    return this->meeple_stack;
}


void Joueur::ajouter_meeple_list(Meeple * meeple) {

}
