#ifndef CARTE_H
#define CARTE_H

#include <array>
#include <list>
#include <vector>

#include "Bordure.h"
#include "Element.h"

class Carte {
    private:
        std::array<Carte*,4> carteVoisines;
        std::list<Bordure *> bordure;
        std::vector<Element *> element;
        bool est_vide();
    public:
        Carte();
        std::vector<Element *> get_element(Carte * carte);
        ~Carte();
};

#endif // CARTE_H
