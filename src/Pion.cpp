// LIBRAIRIES
#include "Pion.hpp"

// FONCTIONS
/**
 * @title: Création d'un sac de Pion
 * */
Pion::Pion()
{
    Logging::log(Logging::TRACE, "création d'un stack de Pion");
    
    // initialisation du tableau de meeple
    for(int i = 0; i < (int) this->stackMeeple.max_size(); i++) 
    {
        this->stackMeeple[i] = nullptr;
    }
}

Pion::~Pion()
{}

/**
 * @title: Génere un meeple selon l'emplacement ou il se situe
 *
 * @param Joueur pour mettre le type joueur sur le meeple généré
 * @param element permet de savoir sur quelle élément il est situé
 * @param tuile pour connaitre son emplacement lors de certaine évaluation
 * @return Meeple un meeple généré, sinon l'élément n'est pas reconnu renvoie nullptr
 * */
Meeple * Pion::generate_meeple(Joueur * joueur, Element * element, const std::array<std::array<Tuile *, 144>,144> * etat_du_jeu, std::pair<int,int> position_tuile)
{
    if(element->get_type_element() == Noeud::VOID) 
    {
        Logging::log(Logging::DEBUG, "l'élement ou tente de forger un meeple est de type VOID, ne peut générer un meeple");
        return nullptr;
    }

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
        return new Moine(joueur, element, etat_du_jeu, position_tuile);
    }

    if(element->get_type_element() == Noeud::PLAINE)
    {
        Logging::log(Logging::TRACE, "génération d'un paysan");
        return new Paysan(joueur, element);
    }

    Logging::log(Logging::DEBUG,"génération d'un meeple à échoué, type element %d non reconnu", element->get_type_element());
    return nullptr;
}

/**
 * @title: Supprime un meeple du tableau et du plateau.
 *
 * @param meeple le meeple à supprimer.
 * */
void Pion::supprimer_meeple(Meeple * meeple) {
    Noeud * noeud = meeple->get_noeud();
    noeud->supprimer_meeple();

    for(int i = 0; i < (int) this->stackMeeple.max_size(); i++) 
    {
        if(this->stackMeeple[i] == meeple) 
        {
            this->stackMeeple[i] = nullptr;
            delete [] meeple;
            return;
        }
    }

    Logging::log(Logging::DEBUG, "emplacement dans le tableau non trouvé le meeple sera détruit alors qu'il ne se trouvait pas dans le tableau");
    delete [] meeple;
}

/**
 * @title: Ajouter un meeple dans un tableau.
 *
 * @param meeple le meeple à ajouter.
 * */
void Pion::ajouter_meeple(Meeple * meeple,int indice)
{
    if(meeple == nullptr)
    {
        Logging::log(Logging::DEBUG, "essaie d'inserer un meeple null dans le tableau");
    }
    if(this->stackMeeple[indice] == nullptr) 
    {
        Logging::log(Logging::TRACE, "ajout meeple à l'indice %d", indice);
        this->stackMeeple[indice] = meeple;
    }
}

/**
 * @title: Récuperé de façon constante la pile de meeple stocké
 *
 * @return la liste de meeple
 * */
const std::array<Meeple *,7> Pion::get_stack_meeple()
{
    return this->stackMeeple;
}

/**
 * @title: récupère le nombre de meeple posé
 * */
int Pion::get_nbr_meeple()
{
    int nbr_meeple = 0;
    for(int i = 0; i < (int) this->stackMeeple.max_size(); i++)
    {
        if(stackMeeple[i] != nullptr) 
        {
            nbr_meeple++;
        }
    }
    return nbr_meeple;
}

/**
 * @title: Determine s'il reste des pions à placer.
 *
 * @return bool si le pion est placé
 * */
bool Pion::si_pion_non_place() 
{
    auto iter = std::find(this->stackMeeple.begin(), this->stackMeeple.end(), nullptr);
    if(iter == std::end(this->stackMeeple))
    {
        return true;
    }
    return false;
}

/**
 * @title: Estime le nombre de points d'un élément
 *
 * @description: créer une meeple virtuelle sur l'éléments pour determiner le nombre de points qu'il potentiellment peut reporter à un élément donné 
 *
 * @param: le joueur qui fait l'évaluation
 * @param: element l'élément sur laquelle on estime le nombre de points que le joueur peut gagner
 * @param: le status du jeu
 * @param: etat_du_jeu est l'état du jeu courant
 * @param: position_tuile est la position de la tuile
 * */
int Pion::estimer_element_points(Joueur * joueur,  Element * element, int status_du_jeu, const std::array<std::array<Tuile *, 144>, 144> *etat_du_jeu, std::pair<int, int> position_tuile)
{
    int score = 0;
    Meeple *meeple = Pion::generate_meeple(joueur, element, etat_du_jeu, position_tuile);
    std::map<Joueur *, std::list<Meeple *>> mapJoueurListeMeeple;
    meeple->compter_points(status_du_jeu, &mapJoueurListeMeeple, &score);
    delete [] meeple; // supprime le meeple temporaire
    return score;
}

/**
 * @title: récupère l'indice du meeple dans le sac
 *
 * @param: l'adresse du meeple
 *
 * @return: l'indice dans le sac
 * */
int Pion::get_indice(Meeple * meeple) 
{
    int indice = -1;
    for(int i = 0; i < (int) this->stackMeeple.max_size(); i++) 
    {
        if(meeple == this->stackMeeple[i])
        {
            if(indice != - 1)
            {
                Logging::log(Logging::DEBUG, "Il y a plusieurs occurences d'un même meeple dans la pile");
            }
            indice = i;
        }
    }
    return indice;
}

/**
 * Récupère le premier indice libre dans le sac
 *
 * @return l'indice correspondant si rien trouvé renvoie -1
 * */
int Pion::get_premier_indice_libre()
{
    for(int i = 0; i < (int) this->stackMeeple.max_size(); i++)
    {
        if(this->stackMeeple[i] == nullptr) 
        {
            return i;
        }
    }
    return -1;
}
