// LIBRAIRIES
#include "Noeud.hpp"

// FONCTIONS
Noeud::Noeud()
{
    
}

void Noeud::set_link(Noeud *noeud)
{

}

std::list<Noeud> Noeud::get_noeud_voisins()
{
    std::list<Noeud> list_vide;
    return list_vide;
}

Noeud::type_element Noeud::get_type_element() {
    return element;
}
