// LIBRAIRIES
#include "Joueur.hpp"

// FONCTIONS

Joueur::~Joueur()
{}


/**
 * @title: Récupère le score obtenu par le joueur
 *
 * @return score
 * */
int Joueur::get_score()
{
    return this->score;
}

/**
 * @title: Ajout en concatenant le score
 *
 * @param score le score doit être supérieur à 0
 * */
void Joueur::add_score(int score)
{
    if (score >= 0)
    {
        this->score = this->score + score;
    }
    else
    {
        Logging::log(Logging::DEBUG, "On ne peut pas ajouter en argument un score inférieur à 0 au joueur transaction annulé");
    }
}

// never used
int Joueur::choix_de_emplacement_libre() 
{
    return 0;
}

// never used
bool Joueur::choix_si_poser_meeple() 
{
    return false;
}

// never used
int Joueur::choix_de_element_libre() 
{
    return 0;
} 
