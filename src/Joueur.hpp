// DIRECTIVES
#ifndef JOUEUR_HPP
#define JOUEUR_HPP

// LIBRAIRIES
#include <array>
#include <string>

#include "Meeple.hpp"
#include "Carte.hpp"

// CLASSE
class Joueur
{
    private:
        // VARIABLES
        std::array<Meeple *,7> meeple;
        int score;
        std::string nom_joueur;

    public:
        static enum Type_joueur{ROBOT, HUMAIN} Type_joueur_enum;

        // CONSTRUCTEURS
        Joueur(Type_joueur type_joueur);

        // DESTRUCTEUR
        ~Joueur();

        // METHODES
        std::string get_nom();
        void set_nom(std::string nom);
        void poser_meaples(Carte * carte, Element * element);
        int get_score();
        void ajouter_points(int points);
        bool list_meaple_vide();
};

#endif
