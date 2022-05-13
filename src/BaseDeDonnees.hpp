#include "Plateau.hpp"

// constantes pour les tuiles en doublons
#define NOMBRE_TUILES_2 2
#define NOMBRE_TUILES_3 3
#define NOMBRE_TUILES_4 4
#define NOMBRE_TUILES_5 5
#define NOMBRE_TUILES_8 8
#define NOMBRE_TUILES_9 9

/**
 * @title: Base de données de tuiles
 *
 * @description: Cette classe permet de génerer la base de données de la pioche.
 * */
class BaseDeDonnees
{
    public:
        static Plateau * generer_plateau_vanilla();
        // static Plateau * generer_plateau_extension();
};
