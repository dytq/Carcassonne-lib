#include "carcassonne.hpp"
#include "core/array.h"
#include "core/class_db.h"
#include "core/dictionary.h"
#include "core/math/vector2.h"
#include <array>
#include <vector>

/* API de Carcassonne */

void Carcassonne::init_jeu() {
    this->plateau = BaseDeDonnees::generer_plateau_vanilla();
    plateau->init_plateau();
    
    Joueur * joueur1 = new Joueur(Joueur::HUMAIN, Joueur::JAUNE);
    Joueur * joueur2 = new Joueur(Joueur::ROBOT, Joueur::ROUGE);
    
    plateau->ajouter_joueur(joueur1, new Pion(7));
    plateau->ajouter_joueur(joueur2, new Pion(7));
}

void Carcassonne::piocher_tuile() {
    this->tuile_pioche = plateau->piocher_tuile_aleat();
}

int Carcassonne::tuile_pioche_id() {
    return this->tuile_pioche->get_id() +1;
}

int Carcassonne::get_coord_id(int x, int y) {
    Tuile * tuile = this->plateau->get_tuile_grille(x, y);
    if(tuile != nullptr) {
        return tuile->get_id_groupe();
    } 
    return -2;
}

void Carcassonne::calcul_emplacement_libre() 
{
    this->plateau->calcul_emplacements_libres(this->tuile_pioche);
}

Dictionary Carcassonne::get_coord_emplacement_libre()
{
    std::vector<std::array<int, 3>> liste_tuiles_emplacements_libres = plateau->get_liste_tuiles_emplacements_libres();
    Dictionary tuiles_libres;

    for(auto emplacement : liste_tuiles_emplacements_libres) 
    {
        Vector2 coord = Vector2(Vector2(emplacement.at(0), emplacement.at(1)));
        if(!tuiles_libres.has(coord)) 
        {
            Array array_orientation;
            array_orientation.append(emplacement.at(2));
            tuiles_libres[coord] = array_orientation;
        } 
        else 
        {
            ((Array) tuiles_libres[coord]).append(emplacement.at(2));
        }
    }
    return tuiles_libres;
}

void Carcassonne::poser_tuile_pioche(int x, int y, int orientation) {
    std::array<int, 3> emplacement;
    emplacement.at(0) = x;
    emplacement.at(1) = y;
    emplacement.at(2) = orientation;
    this->plateau->poser_tuile(tuile_pioche, emplacement);
}

Array Carcassonne::get_coord_element_tuile_pioche() {
    Array element_tuile;
    for(auto element : this->tuile_pioche->getElements()) 
    {
        Vector2 coord = Vector2(element->get_coords().first, element->get_coords().second);
        element_tuile.append(coord);
    }
    return element_tuile;
}

void Carcassonne::_bind_methods() {
    ClassDB::bind_method(D_METHOD("init_jeu"),&Carcassonne::init_jeu);
    ClassDB::bind_method(D_METHOD("piocher_tuile"),&Carcassonne::piocher_tuile);
    ClassDB::bind_method(D_METHOD("tuile_pioche_id"),&Carcassonne::tuile_pioche_id);
    ClassDB::bind_method(D_METHOD("get_coord_id", "x", "y"),&Carcassonne::get_coord_id);
    ClassDB::bind_method(D_METHOD("calcul_emplacement_libre"),&Carcassonne::calcul_emplacement_libre);
    ClassDB::bind_method(D_METHOD("get_coord_emplacement_libre"),&Carcassonne::get_coord_emplacement_libre);
    ClassDB::bind_method(D_METHOD("poser_tuile_pioche", "x", "y", "orientation"),&Carcassonne::poser_tuile_pioche);
    ClassDB::bind_method(D_METHOD("get_coord_element_tuile_pioche"),&Carcassonne::get_coord_element_tuile_pioche);
}

Carcassonne::Carcassonne() {

}
