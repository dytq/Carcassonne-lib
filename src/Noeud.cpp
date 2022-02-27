// LIBRAIRIES
#include "Noeud.hpp"

// FONCTIONS
Noeud::Noeud()
{
    
}

Noeud::~Noeud()
{}

void Noeud::set_lien(Noeud *noeud)
{

}

void Noeud::set_voisin(Noeud *noeud)
{

}

Noeud * Noeud::noeud_fils(Noeud *noeud_pere, int profondeur)
{
    int i = 0;

    for(Noeud * const &itNoeud : this->noeuds_voisins)
    {
        // si le noeud est le pere alors ce n'est pas un fils
        if(itNoeud == noeud_pere){
            i++;
        }

        // on regarde si on a atteins la profondeur de la liste
        if(i == profondeur) {
            return itNoeud;
        }
    }

    #ifndef LOG
    Logging::log(Logging::DEBUG, "aucun fils trouvé, trop profond ou le noeud n'a pas de fils, retour nullptr");
    #endif // LOG

    return nullptr;
}

int Noeud::get_nbr_voisins()
{
    return (int) this->noeuds_voisins.size();
}

bool Noeud::has_nullptr()
{
    std::list<Noeud *>::iterator iter = std::find(this->noeuds_voisins.begin(),this->noeuds_voisins.end(), nullptr);
    return iter != this->noeuds_voisins.end();
}

Noeud::type_element Noeud::get_type_element()
{
    return element;
}

void Noeud::set_type_element(Noeud::type_element type)
{
    this->element = type;
}
