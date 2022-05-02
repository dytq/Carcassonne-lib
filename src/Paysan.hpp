// DIRECTIVES
#ifndef PAYSAN_HPP
#define PAYSAN_HPP

// LIBRAIRIES
#include <list>
#include <iostream>

#include "Meeple.hpp"
#include "Noeud.hpp"
#include "Constantes.hpp"
#include "Element.hpp"

// CLASSE
class Paysan : public Meeple
{
    public:
        Paysan(Joueur * joueur, Noeud * noeud);
        bool compter_points(int status_du_jeu, std::map<Joueur *, std::list<Meeple *>> * mapJoueurListeMeeple, int *score) override;
};


#endif
