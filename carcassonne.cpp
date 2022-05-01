#include "carcassonne.hpp"

/* API de Carcassonne */

// Initialise le jeu (génération d'un plateau)
void Carcassonne::init_jeu() {
    this->plateau = BaseDeDonnees::generer_plateau_vanilla();
    plateau->init_plateau();
    
    Joueur * joueur1 = new Joueur(Joueur::HUMAIN, Joueur::JAUNE);
    Joueur * joueur2 = new Joueur(Joueur::ROBOT, Joueur::ROUGE);
    
    plateau->ajouter_joueur(joueur1, new Pion(7));
    plateau->ajouter_joueur(joueur2, new Pion(7));

    this->joueur1 = joueur1;
    this->joueur2 = joueur2;
}

// Pioche une tuile
void Carcassonne::piocher_tuile() {
    this->tuile_pioche = plateau->piocher_tuile_aleat();
}

// Récupere l'identifiant d'une tuile
int Carcassonne::tuile_pioche_id() {
    return this->tuile_pioche->get_id() +1;
}

// Récupere l'identifiant d'une tuile d'une coordonées x y
int Carcassonne::get_coord_id(int x, int y) {
    Tuile * tuile = this->plateau->get_tuile_grille(x, y);
    if(tuile != nullptr) {
        return tuile->get_id_groupe();
    } 
    return -2;
}

// Calcul les emplacements libre d'une tuile
void Carcassonne::calcul_emplacement_libre() 
{
    this->plateau->calcul_emplacements_libres(this->tuile_pioche);
}

// Calcul les élements libre d'une tuile
void Carcassonne::calcul_element_libre() 
{
    this->plateau->calculer_element_libre(this->tuile_pioche);
}

// Récupère les coordonnées des emplacements libre
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

// Pose la tuile pioché sur la grille
void Carcassonne::poser_tuile_pioche(int x, int y, int orientation) {
    this->emplacement_tuile_pioche.at(0) = x;
    this->emplacement_tuile_pioche.at(1) = y;
    this->emplacement_tuile_pioche.at(2) = orientation;
    this->plateau->poser_tuile(tuile_pioche, this->emplacement_tuile_pioche);
}

// Récupère les coordonnées des éléments de la tuile piochée
Array Carcassonne::get_coord_element_tuile_pioche() {
    Array element_tuile;
    for(auto element : this->plateau->get_element_libre()) 
    {
        Vector2 coord = Vector2(element->get_coords().first, element->get_coords().second);
        element_tuile.append(coord);
    }
    return element_tuile;
}

// Pose un meeple sur un élément
void Carcassonne::poser_meeple(int joueur_id, int indice_element) {
    Joueur * joueur = nullptr;
    if(joueur_id == 1) {
        joueur = this->joueur1;
    } 
    if(joueur_id == 2) {
        joueur = this->joueur2;
    }

    this->plateau->poser_meeple(joueur, this->plateau->get_element_libre()[indice_element], std::make_pair(emplacement_tuile_pioche.at(0), emplacement_tuile_pioche.at(1)));
}

// Evalue les points des meeples en cours de jeu
void Carcassonne::evaluation_points_meeple() {
    this->plateau->evaluer_meeple(STATUS_EN_COURS);
}

// Evalue les points des meeples en fin de jeu
void Carcassonne::evaluation_points_meeple_final() {
    this->plateau->evaluer_meeple(STATUS_FINAL);
}

// Récupère le nombre de pions restant pour un joueur
int Carcassonne::get_nbr_pion_joueur(int joueur_id) 
{
    if(joueur_id == 1) {
        return this->plateau->get_nbr_pion(this->joueur1);
    }
    if(joueur_id == 2) {
        return this->plateau->get_nbr_pion(this->joueur2);
    }
    return 0;
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
    ClassDB::bind_method(D_METHOD("poser_meeple", "joueur_id", "indice_id"),&Carcassonne::poser_meeple);
    ClassDB::bind_method(D_METHOD("evaluation_points_meeple"),&Carcassonne::evaluation_points_meeple);
    ClassDB::bind_method(D_METHOD("evaluation_points_meeple_final"),&Carcassonne::evaluation_points_meeple_final);
    ClassDB::bind_method(D_METHOD("calcul_element_libre"),&Carcassonne::calcul_element_libre);
    ClassDB::bind_method(D_METHOD("get_nbr_pion_joueur", "joueur_id"),&Carcassonne::get_nbr_pion_joueur);
}

Carcassonne::Carcassonne() {

}
