#ifndef PION_HPP
#define PION_HPP

#include <list>

#include "Meeple.hpp"

class Pion {
    private:
        std::list<Meeple *> stackMeeple;

    public:
        void ajouter_meeple(Meeple * meeple);
        void supprimer_meeple(Meeple * meeple);
        const std::list<Meeple *> get_stack_meeple();
};

#endif // PION_HPP
