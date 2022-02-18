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

void Plateau::compter_points(Joueur * joueur)
{

}

Joueur * Plateau::joueur_suivant()
{
    return NULL;
}

void Plateau::evaluer_meeple(Meeple::type_comptage comptage) {

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
