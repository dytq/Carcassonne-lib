// LIBRAIRIES
#include "Moine.hpp"

// FONCTIONS
Moine::Moine(Joueur * joueur, Noeud * noeud, std::array<std::array<Tuile *, 144>,144> * etat_du_jeu, std::pair<int,int> position)
{
    Meeple::joueur = joueur;
    Meeple::noeud = noeud;
    this->etat_du_jeu = etat_du_jeu;
    this->position_tuile = position;
}

Moine::~Moine()
{}

/**
 * @title : algorithme de comptage de points pour un moine
 *
 * @description : L'algorithme stoque dans un tableau de tuiles les tuiles adjacentes à la tuile de la moine et les compte.
 * Elle compte un point pour elle même.
 *
 * @param : status_du_jeu : si l'évaluation se fait en fin de partie ou non
 * @param : mapJoueurListMeeple : il y a pas d'évaluation concurentielles de meeple, donc la map contient seulement le joueur à qui appartient le partisan.
 * @param : *score : le score du joueur obtenu.
 *
 * @return : si l'évaluation du moine est complète
 */
bool Moine::compter_points(int status_du_jeu, std::map<Joueur *, std::list<Meeple *>> * mapJoueurListeMeeple, int * score)
{
    // On récupère la liste des tuiles adjacentes tuile où se trouve le moine
    std::vector<std::pair<int,int>> voisins_coord = {
        std::make_pair(position_tuile.first, position_tuile.second + 1),
        std::make_pair(position_tuile.first + 1, position_tuile.second + 1),
        std::make_pair(position_tuile.first + 1, position_tuile.second),
        std::make_pair(position_tuile.first + 1, position_tuile.second - 1),
        std::make_pair(position_tuile.first, position_tuile.second - 1),
        std::make_pair(position_tuile.first - 1, position_tuile.second - 1),
        std::make_pair(position_tuile.first - 1, position_tuile.second),
        std::make_pair(position_tuile.first - 1, position_tuile.second + 1)
    };
   
    bool est_complete = true;
    *score = 1;                                                                 // on compte la tuile de base 
    for(auto voisin_coord : voisins_coord) 
    {
        Tuile * tuile = etat_du_jeu->at(voisin_coord.first).at(voisin_coord.second);
        if(tuile  != nullptr)
        {
            Logging::log(Logging::DEBUG, "Moine::compter_points %d <%d,%d>", tuile->get_id_groupe(), voisin_coord.first, voisin_coord.second);
            if(tuile->get_id_groupe() != -1)
            {
                *score += 1;
            }
        }
        else 
        {
            est_complete =false;
        }
    }

    return est_complete;
}
