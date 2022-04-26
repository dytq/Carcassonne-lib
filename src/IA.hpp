// DIRECTIVES
#ifndef IA_HPP
#define IA_HPP

// LIBRAIRIES
#include <vector>
#include <array>
#include <stdbool.h>

// STRUCTURE
typedef struct resultatIA
{
	int coupOptimal;
	bool poserMeeple;
	int positionMeeple;
} resultatIA;


// CLASSE
class IA
{
    private:
        // VARIABLES

    public:
        // CONSTRUCTEURS
        IA();

        // DESTRUCTEUR
        ~IA();

        // METHODES
		resultatIA jouerCoupAleatoire(std::vector<std::array<int, 3>> liste_tuiles_emplacements_libres);
		resultatIA jouerCoup(std::vector<std::array<int, 3>> liste_tuiles_emplacements_libres);
};

#endif