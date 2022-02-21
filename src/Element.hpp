// DIRECTIVES
#ifndef ELEMENT_HPP
#define ELEMENT_HPP

// LIBRAIRIES
#include <iostream>

#include "Noeud.hpp"
#include "Meeple.hpp"
#include "Joueur.hpp"
#include "Chevalier.hpp"
#include "Brigand.hpp"
#include "Moine.hpp"

// CLASSE
class Element : public Noeud
{
    private:
        // VARIABLES
        Meeple * meeple;
        int point_en_cours;
        int point_final;

    public:
        // CONSTRUCTEURS
        Element(Noeud::type_element type_noeud);

        // DESTRUCTEUR
        ~Element();

        // METHODES
        Meeple * recuperer_meeple();
        void supprimer_meeple();
        void set_point(int point, int i);
        void ajouter_meeple(Meeple * meeple);
        static Meeple * generate_meeple(Joueur * joueur, Element * element) {// TODO creer héritage pour les elements -> fontion static dans la super classe
            if(element->element == Noeud::VILLE) {
                return new Chevalier(joueur, element);
            }
            if(element->element == Noeud::ROUTE) {
                return new Brigand(joueur, element);
            }
            if(element->element == Noeud::ABBAYE) {
                return new Moine(joueur, element);
            }
            #ifndef DEBUG
            std::cout << "Ne peut pas générer un Meeple" << std::endl;
            #endif // DEBUG
            return nullptr;
        }
};

#endif
