// DIRECTIVES
#ifndef JOUEUR_HPP
#define JOUEUR_HPP

// LIBRAIRIES
#include <list>
#include <string>

// CLASSE
class Joueur
{
    public:
        static enum Type_joueur{ROBOT, HUMAIN} Type_joueur_enum;

    private:
        // VARIABLES
        int score;
        std::string nom_joueeur;
        Type_joueur type_joueur;
    public:
        // CONSTRUCTEURS
        Joueur(Type_joueur type_joueur);

        // DESTRUCTEUR
        ~Joueur();

        // METHODES
        std::string get_nom();
        void set_nom(std::string nom);
        int get_score();
        Type_joueur get_type_joueur();
        void ajouter_points(int points);
};

#endif
