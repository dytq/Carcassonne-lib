// LIBRAIRIES
#include "Joueur.hpp"

// FONCTIONS
Joueur::Joueur(Type_joueur type_joueur)
{
    this->type_joueur = type_joueur;
    this->score = 0;
}

Joueur::~Joueur()
{}


int Joueur::get_score()
{
    return this->score;
}

void Joueur::add_score(int score)
{
    if (score < 0) {
        this->score = this->score + score;
    }
}

Joueur::Type_joueur Joueur::get_type_joueur()
{
    return this->type_joueur;
}