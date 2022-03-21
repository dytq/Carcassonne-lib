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
        // VARIABLES
        static enum Type_joueur{ROBOT, HUMAIN} Type_joueur_enum;

    private:
        int score;
        Type_joueur type_joueur;
        
    public:
        // CONSTRUCTEURS
        Joueur(Type_joueur type_joueur);

        // DESTRUCTEUR
        ~Joueur();

        // METHODES
        int get_score();
        void add_score(int score);
        Type_joueur get_type_joueur();
};

#endif // JOUEUR_HPP