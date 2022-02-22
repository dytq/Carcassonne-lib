// LIBRAIRIES
#include "Bordure.hpp"

// FONCTIONS
Bordure::Bordure(Noeud::type_element type_noeud)
{

}

Bordure::~Bordure()
{}

std::array<Bordure *,3> Bordure::get_bordure_fils()
{
    return this->bordureFils;
}

void Bordure::set_bordure_fils(std::array<Bordure*,3> bordureFils)
{

}