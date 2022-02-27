// LIBRAIRIES
#include "Bordure.hpp"

// FONCTIONS
Bordure::Bordure()
{

}

Bordure::~Bordure()
{}

Bordure * Bordure::get_bordure_fils(int indice)
{
    return this->bordureFils[indice];
}

int Bordure::get_points(int status_du_jeu)
{
    return 0;
}

void Bordure::set_type_element(Noeud::type_element type_noeud)
{
    Noeud::element = type_noeud;
}

void Bordure::set_bordure_fils(int indice, Noeud::type_element element)
{
    this->bordureFils.at(indice) = new Bordure();
    this->bordureFils.at(indice)->set_type_element(element);
}
