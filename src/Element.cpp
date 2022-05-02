// LIBRAIRIES
#include "Element.hpp"

// FONCTIONS
/**
 * L'element est associé à un type élement, elle s'initialise à son emplacement meeple à nullptr
 *
 * @param type_element le type d'élément
 * */
Element::Element(Noeud::type_element type_element, std::pair<float,float> coordonnees)
{
    // initialise les coordonnées
    this->coordonnees.first = coordonnees.first;
    this->coordonnees.second = coordonnees.second;

    // initialise par défaut le meeple à nullptr
    this->meeple = nullptr;

    // permet d'assigner les points obtenu en fonctions du type d'élément lors du comptage des points
    Noeud::element = type_element;
    switch (type_element) {
        case Noeud::ABBAYE:
            this->point_en_cours = POINTS_ABBAYE_COMPLET;
            this->point_final = POINTS_ABBAYE_INCOMPLET;
            break;
        case Noeud::PLAINE:
            this->point_en_cours = 0; // non évalué
            this->point_final = POINTS_PAYSANS;
            break;
        case Noeud::ROUTE:
            this->point_en_cours = POINTS_ROUTE_COMPLET;
            this->point_final = POINTS_ROUTE_INCOMPLET;
            break;
        case Noeud::VILLE:
            this->point_en_cours = POINTS_VILLE_COMPLET;
            this->point_final = POINTS_VILLE_INCOMPLET;
            break;
        case Noeud::VILLE_BLASON:
            this->point_en_cours = POINTS_VILLE_BLASON_COMPLET;
            this->point_final = POINTS_VILLE_BLASON_INCOMPLET;
            break;
        default:
            Logging::log(Logging::DEBUG, "Le nombre de point ne peut pas être attribué à l'élément");
            break;
    }
}

Element::~Element()
{}

/**
 * getter du meeple situé sur l'élément
 *
 * @return meeple
 * */
Meeple * Element::get_meeple()
{
    return this->meeple;
}

/**
 * Permet d'ajouter un meeple sur l'élément
 *
 * @return meeple
 * */
void Element::ajouter_meeple(Meeple * meeple)
{
    this->meeple = meeple;
}

/**
 * Permet de supprimer symboliquement un meeple actuellement situé sur l'élément
 *
 * */
void Element::supprimer_meeple()
{
    this->meeple = nullptr;
}

/**
 * Permet de recupérer le nombre de points obtenu par la case
 *
 * @param status du jeu le nombre de points obtenu selon le status du jeu est différent
 * @return retourne le score reçut
 * */
int Element::get_points(int status_du_jeu) {
    if(status_du_jeu == STATUS_EN_COURS) {
        return this->point_en_cours;
    }
    if(status_du_jeu == STATUS_FINAL) {
        return this->point_final;
    }
    Logging::log(Logging::DEBUG, "status du jeu non évalué pour l'élément");
    return 0;
}

const std::pair<float, float> Element::get_coords() 
{
    return this->coordonnees;
}