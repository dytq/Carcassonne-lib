// LIBRAIRIES
#include "Pion.hpp"

// FONCTIONS
Pion::Pion()
{
    #ifndef LOG
    Logging::log(Logging::DEBUG, "création d'un stack de Pion");
    #endif // LOG
}

Pion::~Pion()
{}

Meeple * Pion::generate_meeple(Joueur * joueur, Element * element, Carte * carte)
{
    if(element->get_type_element() == Noeud::VILLE || element->get_type_element() == Noeud::VILLE_BLASON)
    {
        return new Chevalier(joueur, element);
    }

    if(element->get_type_element() == Noeud::ROUTE)
    {
        return new Brigand(joueur, element);
    }

    if(element->get_type_element() == Noeud::ABBAYE)
    {
        return new Moine(joueur, element, carte);
    }

    if(element->get_type_element() == Noeud::PLAINE)
    {
        return new Paysan(joueur, element);
    }

    #ifndef LOG
    Logging::log(Logging::DEBUG,"Ne peut pas générer un Meeple");
    #endif // LOG

    return nullptr;
}

void Pion::ajouter_meeple(Meeple * meeple)
{
    if(meeple == NULL)
    {
        #ifndef LOG
        Logging::log(Logging::DEBUG, "essaie d'inserer un meeple null dans la pile");
        #endif // LOG
    }

    this->stackMeeple.push_front(meeple);
}

void Pion::supprimer_meeple(Meeple * meeple)
{

}

const std::list<Meeple *> Pion::get_stack_meeple()
{
    return this->stackMeeple;
}
