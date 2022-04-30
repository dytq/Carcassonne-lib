#ifndef CARCASSONNE_H
#define CARCASSONNE_H

#include "core/dictionary.h"
#include "core/reference.h"
#include "src/Plateau.hpp"
#include "src/BaseDeDonnees.hpp"

class Carcassonne : public Reference {
    GDCLASS(Carcassonne, Reference);
    Plateau * plateau;
    Tuile * tuile_pioche;

protected:
    static void _bind_methods();

public:
    Carcassonne();
    void init_jeu();
    void piocher_tuile();
    int tuile_pioche_id();
    int get_coord_id(int x, int y);
    void calcul_emplacement_libre();
    Dictionary get_coord_emplacement_libre();
    void poser_tuile_pioche(int x, int y, int orientation);
    Array get_coord_element_tuile_pioche();
};

#endif // CARCASSONNE_HPP
