// LIBRAIRIES
#include "Joueur.hpp"

// FONCTIONS
Joueur::Joueur(Type_joueur type_joueur)
{
    this->type_joueur = type_joueur;
}

Joueur::~Joueur()
{}

std::string Joueur::get_nom()
{
    return nullptr;
}

void Joueur::set_nom(std::string nom)
{

}

int Joueur::get_score()
{
    return 0;
}

void Joueur::ajouter_points(int points)
{

}

Joueur::Type_joueur Joueur::get_type_joueur()
{
    return this->type_joueur;
}