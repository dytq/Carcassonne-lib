#ifndef BRIGAND_HPP
#define BRIGAND_HPP

#include "Meeple.hpp"
#include "Joueur.hpp"
#include "Noeud.hpp"
#include "Element.hpp"

class Brigand : public Meeple
{
    public:
        // CONSTRUCTEURS
        Brigand(Joueur * joueur, Noeud * noeud);

        // DESTRUCTEUR
        ~Brigand();

        // METHODES
        bool compter_points(int status_du_jeu, std::map<Joueur*, std::list<Meeple*>> * mapJoueurListMeeple, int * score);
};

#endif
