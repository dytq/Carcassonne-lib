// LIBRAIRIES
#include "Element.hpp"

// FONCTIONS
Element::Element(Noeud::type_element type_element)
{
    Noeud::element = type_element;
}

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
