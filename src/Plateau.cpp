// LIBRAIRIES
#include "Plateau.hpp"

// FONCTIONS
Plateau::Plateau()
{
    #ifndef LOG
    Logging::log(Logging::TRACE, "Création du plateau");
    #endif // LOG
}

Plateau::~Plateau()
{}

void Plateau::init_plateau()
{
    for(int i = 0; i < 4; i++){
        std::array<Carte *, 4> carteVoisines;
        std::array<Bordure *, 4> bordure;
        std::list<Element *> element;

        // init les cartes
        for(int i = 0; i < 4; i++)
        {
            carteVoisines[i] = nullptr;
        }

        // init bordure
        for(int i = 0; i < 4; i++)
        {
            bordure.at(i) = new Bordure();
        }

        // init les bordures
        bordure[0]->set_bordure_fils(1, Noeud::VILLE);

        bordure[1]->set_bordure_fils(0, Noeud::PLAINE);
        bordure[1]->set_bordure_fils(1, Noeud::ROUTE);
        bordure[1]->set_bordure_fils(2, Noeud::PLAINE);

        bordure[2]->set_bordure_fils(1, Noeud::PLAINE);

        bordure[3]->set_bordure_fils(0, Noeud::PLAINE);
        bordure[3]->set_bordure_fils(1, Noeud::ROUTE);
        bordure[3]->set_bordure_fils(2, Noeud::PLAINE);

        // init les elements
        std::list<Element *> elementCarte;
        Element * element1 = new Element(Noeud::VILLE);
        Element * element2 = new Element(Noeud::ROUTE);
        Element * element3 = new Element(Noeud::PLAINE);
        Element * element4 = new Element(Noeud::PLAINE);

        // init les voisins
        // bordure:
        bordure[0]->get_bordure_fils(1)->set_voisin(element1);

        bordure[1]->get_bordure_fils(0)->set_voisin(element3);
        bordure[1]->get_bordure_fils(1)->set_voisin(element2);
        bordure[1]->get_bordure_fils(2)->set_voisin(element4);

        bordure[2]->get_bordure_fils(1)->set_voisin(element4);

        bordure[3]->get_bordure_fils(0)->set_voisin(element4);
        bordure[3]->get_bordure_fils(1)->set_voisin(element2);
        bordure[3]->get_bordure_fils(2)->set_voisin(element3);

        // element:
        element1->set_voisin(bordure[0]->get_bordure_fils(1));

        element2->set_voisin(bordure[1]->get_bordure_fils(1));
        element2->set_voisin(bordure[3]->get_bordure_fils(1));

        element3->set_voisin(bordure[1]->get_bordure_fils(0));
        element3->set_voisin(bordure[3]->get_bordure_fils(0));

        element4->set_voisin(bordure[1]->get_bordure_fils(2));
        element4->set_voisin(bordure[2]->get_bordure_fils(1));
        element4->set_voisin(bordure[3]->get_bordure_fils(0));

        // Ajout des liens additionelles
        element3->set_lien(element1);

        // Creation de la carte
        Carte * carte = new Carte(carteVoisines, bordure, elementCarte);

        // Ajout de la carte dans le pioche
        this->pioche.push_front(carte); // front pour la première carte
    }
}

void Plateau::charger_donnee(std::string path)
{

}

void Plateau::ajouter_joueur(Joueur * joueur, Pion * pion)
{
    this->mapJoueursPions.insert(std::pair<Joueur *, Pion *>(joueur, pion));
}

Joueur * Plateau::get_joueur()
{
    return NULL;
}

std::list<Carte*> Plateau::get_pioche()
{
    return this->pioche;
}

Carte * Plateau::piocher_carte()
{
    return NULL;
}

void Plateau::calcul_emplacement_libre(Carte *carte)
{

}

void Plateau::poser_carte(Carte *carte_pioche, Carte *carte_emplacement, std::list<Bordure *> bordure)
{

}

Joueur * Plateau::joueur_suivant()
{
    return NULL;
}

/**
 * Recherche le Joueur qui à obtenue le plus de pions.
 *
 * @param mapJoueurListeMeeple Joueur associé à une liste de Meeple
 * */
Joueur * Plateau::rechercher_Joueur_plus_de_Pions(std::map<Joueur*, std::list<Meeple *>> mapJoueurListeMeeple)
{
    return NULL;
}

/**
 * Désindexe les Meeples du plateau.
 *
 * @param mapJoueurListeMeeple Joueur associé à une liste de Meeple */
void Plateau::desindexer_Meeple_dans_la_map(std::map<Joueur*, std::list<Meeple *>> mapJoueurListeMeeple)
{

}


/**
 * Evaluation des Meeples pour chaque Joueurs
 *
 * Cette méthode permet d'à partir de chaque Meeple des Joueurs d'évaluer s'il y a possibilité d'attribuer des points aux Joueurs
 * L'évaluation s'effectue sur tous les Meeples et les points sont distribuée selon la quantité de Meeple obtenu (pour l'évalation concurrencielle, ce n'est pas le cas pour les abbayes par exemple)
 *
 * @param status_du_jeu permet de faire une évaluation soit final soit en cours du jeu
 * */
void Plateau::evaluer_meeple(int status_du_jeu)
{
    for(auto const &itMap : this->mapJoueursPions)
    {
        const std::list<Meeple *> listMeeple = itMap.second->get_stack_meeple();

        for(auto const &itMeeple : listMeeple)
        {
            int score = 0;
            std::map<Joueur *, std::list<Meeple *>> mapJoueurListeMeeple;
            int est_complet = itMeeple->compter_points(status_du_jeu, mapJoueurListeMeeple, &score);

            if(est_complet == true || status_du_jeu )
            {
                Joueur * joueur = this->rechercher_Joueur_plus_de_Pions(mapJoueurListeMeeple);
                joueur->ajouter_points(score);
                this->desindexer_Meeple_dans_la_map(mapJoueurListeMeeple);
            }
        }
    }
}

std::list<Joueur *> Plateau::get_joueur_liste()
{
    return this->list_joueur;
}

std::vector<Carte *> Plateau::get_list_carte_emplacement_libre()
{
    std::vector<Carte *> list_vide;
    
    return list_vide;
}

std::vector<std::list<Bordure *>> Plateau::get_orientation_possible(Carte *carte)
{
    std::vector<std::list<Bordure *>> list_vide;

    return list_vide;
}


bool Plateau::stack_meeple_vide(Joueur * joueur)
{
    return true;
}

void Plateau::poser_meeple(Joueur * joueur, Element * element, Carte * carte)
{
    Meeple * meeple = Pion::generate_meeple(joueur, element, carte);
    element->ajouter_meeple(meeple);
    Pion * pion = this->mapJoueursPions.find(joueur)->second;
    pion->ajouter_meeple(meeple);
}
