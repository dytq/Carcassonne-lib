#ifndef BRIGAND_HPP
#define BRIGAND_HPP

#include "Meeple.hpp"
#include "Joueur.hpp"

class Brigand : public Meeple
{
    public:
        // CONSTRUCTEURS
        Brigand(Joueur * joueur, Noeud * noeud);

        // DESTRUCTEUR
        ~Brigand();

        // METHODES
        int compter_points(int status_du_jeu, std::map<Joueur*, std::list<Meeple*>>, int * score);
};

#endif