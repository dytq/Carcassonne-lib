// LIBRAIRIES
#include "Joueur.hpp"

// FONCTIONS
/**
 * Permet de créer un joueur. Elle initialise son score à 0 par défaut.
 *
 * @param type_joueur  est le type de joueur
 * */
Joueur::Joueur(Type_joueur type_joueur)
{
    Logging::log(Logging::TRACE, "Création du joueur de type %d", type_joueur);
    this->type_joueur = type_joueur;
    this->score = 0;
}

Joueur::~Joueur()
{}


/**
 * Permet de récuperer le score obtenu par le joueur
 *
 * @return score
 * */
int Joueur::get_score()
{
    return this->score;
}

/**
 * Permet d'ajouter en concatenant le score
 *
 * @param score le score doit être supérieur à 0
 * */
void Joueur::add_score(int score)
{
    if (score < 0)
    {
        this->score = this->score + score;
    }
    else
    {
        Logging::log(Logging::DEBUG, "On ne peut pas ajouté en argument est inférieur à 0 au joueur");
    }
}

/**
 * Permet d'obtenir le type de joueur
 *
 * @return type de joueur
 * */
Joueur::Type_joueur Joueur::get_type_joueur()
{
    return this->type_joueur;
}