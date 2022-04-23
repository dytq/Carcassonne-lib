// DIRECTIVES
#ifndef MOINE_HPP
#define MOINE_HPP

// LIBRAIRIES
#include "Meeple.hpp"
#include "Joueur.hpp"
#include "Tuile.hpp"
#include "Plateau.hpp"

// CLASSE
class Moine : public Meeple
{
    private:
    // VARIABLES
    Tuile * tuile;

    public:
    // CONSTRUCTEURS
    Moine(Joueur * joueur, Noeud * noeud, Tuile * tuile);

    // DESTRUCTEUR
    ~Moine();

    // METHODES
    bool compter_points(int status_du_jeu, std::map<Joueur *, std::list<Meeple *>> * mapListeMeeple, int * score) override;
};

#endif
