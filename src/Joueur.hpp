// DIRECTIVES
#ifndef JOUEUR_HPP
#define JOUEUR_HPP

// LIBRAIRIES
#include <list>
#include <string>

#include "Carte.hpp"

// CLASSE
class Joueur
{
    private:
        // VARIABLES
        int score;
        std::string nom_joueeur;

    public:
        static enum Type_joueur{ROBOT, HUMAIN} Type_joueur_enum;
        // CONSTRUCTEURS
        Joueur(Type_joueur type_joueur);

        // DESTRUCTEUR
        ~Joueur();

        // METHODES
        std::string get_nom();
        void set_nom(std::string nom);
        int get_score();
        void ajouter_points(int points);
};

#endif
