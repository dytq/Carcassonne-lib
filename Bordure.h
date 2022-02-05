#ifndef BORDURE_H
#define BORDURE_H

#include "Noeud.h"

class Bordure : Noeud {
    private:
        Type_noeud type_noeud;
    public:
        Bordure(Type_noeud type_noeud);
};

#endif //BORDURE_H
