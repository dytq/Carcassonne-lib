#ifndef PION_HPP
#define PION_HPP

#include <list>
#include <iostream>

#include "Meeple.hpp"
#include "Carte.hpp"
#include "Chevalier.hpp"
#include "Brigand.hpp"
#include "Moine.hpp"
#include "Joueur.hpp"
#include "Element.hpp"
#include "Noeud.hpp"

class Pion {
    private:
        std::list<Meeple *> stackMeeple;

    public:
        Pion();
        void ajouter_meeple(Meeple * meeple);
        void supprimer_meeple(Meeple * meeple);
        const std::list<Meeple *> get_stack_meeple();
        static Meeple * generate_meeple(Joueur * joueur, Element * element, Carte * carte) {
            if(element->get_type_element() == Noeud::VILLE) {
                return new Chevalier(joueur, element);
            }
            if(element->get_type_element() == Noeud::ROUTE) {
                return new Brigand(joueur, element);
            }
            if(element->get_type_element() == Noeud::ABBAYE) {
                return new Moine(joueur, element, carte);
            }
            #ifndef DEBUG
            std::cout << "Ne peut pas générer un Meeple" << std::endl;
            #endif // DEBUG
            return nullptr;
        }
};

#endif // PION_HPP
