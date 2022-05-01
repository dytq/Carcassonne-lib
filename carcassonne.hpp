#ifndef CARCASSONNE_H
#define CARCASSONNE_H

#include "core/dictionary.h"
#include "core/reference.h"
#include "modules/carcassonne/src/Joueur.hpp"
#include "src/Plateau.hpp"
#include "src/BaseDeDonnees.hpp"
#include "core/array.h"
#include "core/class_db.h"
#include "core/dictionary.h"
#include "core/math/vector2.h"
#include "modules/carcassonne/src/Joueur.hpp"
#include <array>
#include <cstddef>
#include <utility>
#include <vector>

class Carcassonne : public Reference {
    /* API GODOT */
    GDCLASS(Carcassonne, Reference);

    /* Variables */
    Plateau * plateau;
    Tuile   * tuile_pioche;
    Joueur  * joueur1;
    Joueur  * joueur2;
    std::array<int, 3> emplacement_tuile_pioche;

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
    void calcul_element_libre();
    Array get_coord_element_tuile_pioche();
    int get_nbr_pion_joueur(int joueur_id);
    void poser_meeple(int joueur_id, int indice_element);
    void evaluation_points_meeple();
    void evaluation_points_meeple_final();
};

#endif // CARCASSONNE_HPP
