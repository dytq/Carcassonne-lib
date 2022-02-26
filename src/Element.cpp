// LIBRAIRIES
#include "Element.hpp"

// FONCTIONS
Element::Element(Noeud::type_element type_element)
{
    Noeud::element = type_element;
}

Element::~Element()
{}

Meeple * Element::recuperer_meeple()
{
    return nullptr;
}

void Element::ajouter_meeple(Meeple * meeple)
{
    this->meeple = meeple;
}

void Element::supprimer_meeple()
{

}

int Element::get_points(int status_du_jeu) {
    if(status_du_jeu == STATUS_EN_COURS) {
        return this->point_en_cours;
    }
    if(status_du_jeu == STATUS_FINAL) {
        return this->point_final;
    }

    #ifndef DEBUG
    std::cout << "status du jeu non évalué pour l'élément" << std::endl;
    #endif // DEBUG

    return 0;
}