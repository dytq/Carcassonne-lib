// LIBRAIRIES
#include <iostream>
#include "Plateau.hpp"

// FONCTIONS
Plateau::Plateau()
{
    std::cout << "Création du plateau" << std::endl;
}

Plateau::~Plateau()
{}

void Plateau::init_plateau()
{

}

void Plateau::charger_donnee(std::string path)
{

}

void Plateau::ajouter_joueur(Joueur * joueur)
{

}

Joueur * Plateau::get_joueur()
{
    return NULL;
}

std::list<Carte*> Plateau::get_pioche()
{
    return this->pioche;
}

Carte * Plateau::piocher_carte()
{
    return NULL;
}

void Plateau::calcul_emplacement_libre(Carte *carte)
{

}

void Plateau::poser_carte(Carte *carte_pioche, Carte *carte_emplacement, std::list<Bordure *> bordure)
{

}

Joueur * Plateau::joueur_suivant()
{
    return NULL;
}

/**
 * Evaluation des Meeples pour chaque Joueurs
 *
 * Cette méthode permet de d'à partir de chaque Meeple des Joueurs d'évaluer s'il y a possibilité d'attribuer des points aux Joueurs
 * L'évaluation s'effectue sur tous les Meeples et les points sont distribuée selon la quantité de Meeple obtenu (pour l'évalation concurrencielle, ce n'est pas le cas pour les abbaye par exemple)
 *
 * @param status_du_jeu permet de faire une évaluation soit final soit en cours du jeu
 * */
void Plateau::evaluer_meeple(int status_du_jeu)
{

}

std::list<Joueur *> Plateau::get_joueur_liste()
{
    return this->list_joueur;
}

std::vector<Carte *> Plateau::get_list_carte_emplacement_libre()
{
    std::vector<Carte *> list_vide;
    
    return list_vide;
}

std::vector<std::list<Bordure *>> Plateau::get_orientation_possible(Carte *carte)
{
    std::vector<std::list<Bordure *>> list_vide;

    return list_vide;
}


bool Plateau::stack_meeple_vide(Joueur * joueur) {
    return true;
}

void Plateau::poser_meeple(Joueur * joueur, Carte * carte, Element * element) {


}
