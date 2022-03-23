// LIBRAIRIES
#include "Pion.hpp"

// FONCTIONS
/**
 * Permet la création d'une pile de Pion
 *
 * @param nbr_meeple est le nombre de meeple qu'on souhaite disposer pour le joueur
 * */
Pion::Pion(int nbr_meeple)
{
    Logging::log(Logging::TRACE, "création d'un stack de Pion");
    this->nbr_meeple_max = nbr_meeple;
}

Pion::~Pion()
{}

/**
 * Permet de générer un meeple selon l'emplacement ou il se situe
 *
 * @param Joueur pour mettre le type joueur sur le meeple généré
 * @param element permet de savoir sur quelle élément il est situé
 * @param tuile pour connaitre son emplacement lors de certaine évaluation
 * @return Meeple un meeple généré, sinon l'élément n'est pas reconnu renvoie nullptr
 * */
Meeple * Pion::generate_meeple(Joueur * joueur, Element * element, Tuile * tuile)
{
    if(element->get_type_element() == Noeud::VILLE || element->get_type_element() == Noeud::VILLE_BLASON)
    {
        Logging::log(Logging::TRACE, "génération d'un chevalier");
        return new Chevalier(joueur, element);
    }

    if(element->get_type_element() == Noeud::ROUTE)
    {
        Logging::log(Logging::TRACE, "génération d'un brigand");
        return new Brigand(joueur, element);
    }

    if(element->get_type_element() == Noeud::ABBAYE)
    {
        Logging::log(Logging::TRACE, "génération d'un moine");
        return new Moine(joueur, element, tuile);
    }

    if(element->get_type_element() == Noeud::PLAINE)
    {
        Logging::log(Logging::TRACE, "génération d'un paysan");
        return new Paysan(joueur, element);
    }

    Logging::log(Logging::DEBUG,"génération d'un meeple à échoué");
    return nullptr;
}

/**
 * Permet de supprimer un meeple du tableau.
 *
 * @param meeple le meeple à supprimer.
 * */
void Pion::supprimer_meeple(Meeple * meeple) {
    Noeud * noeud = meeple->get_noeud();
    noeud->supprimer_meeple();
    this->stackMeeple.remove(meeple);
}

/**
 * Permet d'ajouter un meeple dans un tableau.
 *
 * @param meeple le meeple à ajouter.
 * */
void Pion::ajouter_meeple(Meeple * meeple)
{
    if(si_pion_non_place() == true) {
       if(meeple == NULL)
        {
            Logging::log(Logging::DEBUG, "essaie d'inserer un meeple null dans la pile");
        }
       this->stackMeeple.push_front(meeple);
    }
}

/**
 * Permet de récuperé de façon constante la pile de meeple stocké
 *
 * @return la liste de meeple
 * */
const std::list<Meeple *> Pion::get_stack_meeple()
{
    return this->stackMeeple;
}

/**
 * Permet de savoir s'il reste des pions à placer.
 *
 * @return bool si le pion est placé
 * */
bool Pion::si_pion_non_place() {
    if((int) this->stackMeeple.size() < this->nbr_meeple_max) {
        return true;
    }
    return false;
}

int Pion::estimer_meeple_points(Meeple *meeple, int status_du_jeu)
{
    int score;
    meeple->compter_points(status_du_jeu, nullptr , &score);
    return score;
}
