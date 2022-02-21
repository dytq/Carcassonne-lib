#ifndef PION_HPP
#define PION_HPP

#include <list>
#include <iostream>

#include "Meeple.hpp"

class Pion {
    private:
        std::list<Meeple *> stackMeeple;

    public:
        Pion();
        void ajouter_meeple(Meeple * meeple);
        void supprimer_meeple(Meeple * meeple);
        const std::list<Meeple *> get_stack_meeple();
};

#endif // PION_HPP
