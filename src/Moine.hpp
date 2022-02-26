// DIRECTIVES
#ifndef MOINE_HPP
#define MOINE_HPP

// LIBRAIRIES
#include "Meeple.hpp"
#include "Joueur.hpp"
#include "Carte.hpp"

// CLASSE
class Moine : public Meeple
{
    private:
    // VARIABLES
    Carte * carte;

    public:
    // CONSTRUCTEURS
    Moine(Joueur * joueur, Noeud * noeud, Carte * carte);

    // DESTRUCTEUR
    ~Moine();

    // METHODES
    bool compter_points(int status_du_jeu, std::map<Joueur *, std::list<Meeple *>> mapListeMeeple, int * score);

};

#endif