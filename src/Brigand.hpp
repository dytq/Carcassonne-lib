#ifndef BRIGAND_HPP
#define BRIGAND_HPP

#include "Meeple.hpp"
#include "Joueur.hpp"
#include "Noeud.hpp"
#include "Element.hpp"

/**
 * @title: Meeple de type Brigand
 *
 * @description: Cette classe représente un meeple de type Brigand. Un brigand est placé sur une route. On otient des points quand soit une route se termine ou bien lorsque la route forme une boucle.
 * */
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
