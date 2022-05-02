// DIRECTIVES
#ifndef MOINE_HPP
#define MOINE_HPP

// LIBRAIRIES
#include "Meeple.hpp"
#include "Joueur.hpp"
#include "Tuile.hpp"

// CLASSE
class Moine : public Meeple
{
    private:
    // VARIABLES
    const std::array<std::array<Tuile *,144>,144> * etat_du_jeu;
    std::pair<int,int> position_tuile;

    public:
    // CONSTRUCTEURS
    Moine(Joueur * joueur, Noeud * noeud, const std::array<std::array<Tuile *, 144>,144> * etat_du_jeu, std::pair<int,int> position);

    // DESTRUCTEUR
    ~Moine();

    // METHODES
    bool compter_points(int status_du_jeu, std::map<Joueur *, std::list<Meeple *>> * mapListeMeeple, int * score) override;
};

#endif
