#ifndef BRIGAND_HPP
#define BRIGAND_HPP

#include "Meeple.hpp"
#include "Joueur.hpp"
#include "Noeud.hpp"

class Brigand : public Meeple
{
    private:
        Noeud * noeud_gauche;
        Noeud * noeud_droite;
    public:
        // CONSTRUCTEURS
        Brigand(Joueur * joueur, Noeud * noeud);

        // DESTRUCTEUR
        ~Brigand();

        // METHODES
        bool compter_points(int status_du_jeu, std::map<Joueur*, std::list<Meeple*>> * mapJoueurListMeeple, int * score);
};

#endif
