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

bool Moine::compter_points(int status_du_jeu, std::map<Joueur *, std::list<Meeple *>> * mapJoueurListeMeeple, int * score)
{
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
    *score = 1; // on compte la tuile de base 
    for(auto voisin_coord : voisins_coord) 
    {
        Tuile * tuile = etat_du_jeu->at(voisin_coord.first).at(voisin_coord.second);
        if(tuile  != nullptr)
        {
            Logging::log(Logging::DEBUG, "Moine::compter_points %d <%d,%d>", tuile->getId(), voisin_coord.first, voisin_coord.second);
            if(tuile->getId() != -1)
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
