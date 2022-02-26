// LIBRAIRIES
#include "Pion.hpp"

// FONCTIONS
Pion::Pion()
{
    #ifndef DEBUG
    std::cout << "création d'un stack de Pion" << std::endl;
    #endif // DEBUG
}

Pion::~Pion()
{}

Meeple * Pion::generate_meeple(Joueur * joueur, Element * element, Carte * carte)
{
    if(element->get_type_element() == Noeud::VILLE)
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

    #ifndef DEBUG
    std::cout << "Ne peut pas générer un Meeple" << std::endl;
    #endif

    return nullptr;
}

void Pion::ajouter_meeple(Meeple * meeple)
{
    if(meeple == NULL)
    {
        #ifndef DEBUG
        std::cout << "essaie d'inserer un meeple null dans la pile" << std::endl;
        #endif // DEBUG
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
