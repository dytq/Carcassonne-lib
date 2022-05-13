// LIBRAIRIES
#include "Joueur.hpp"

// FONCTIONS
/**
 * @title: Constructeur d'un joueur
 *
 * @param type_joueur  est le type de joueur
 * @param couleur est la couleur des ses pions 
 * */
Joueur::Joueur(Type_joueur type_joueur, Couleur couleur)
{
    Logging::log(Logging::TRACE, "Création du joueur de type %d", type_joueur);
    this->type_joueur = type_joueur;
    this->couleur = couleur;
    this->score = 0;
}

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

/**
 * @title: Retourne le type de joueur
 *
 * @return type de joueur
 * */
Joueur::Type_joueur Joueur::get_type_joueur()
{
    return this->type_joueur;
}

/**
 * @title: Retourne la couleur du joueur
 *
 * @return couleur
 * */
Joueur::Couleur Joueur::get_couleur()
{
    return this->couleur;
}
