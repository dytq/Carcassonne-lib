// DIRECTIVES
#ifndef JOUEUR_HPP
#define JOUEUR_HPP

// LIBRAIRIES
#include <list>
#include <string>
#include "Logging.hpp"

// CLASSE
class Joueur
{
    public:
        // VARIABLES
        static enum Type_joueur{ROBOT, HUMAIN} Type_joueur_enum;
        static enum Couleur{JAUNE,ROUGE,VERT,BLEU,NOIR} Couleur_enum;
    private:
        int score;
        Type_joueur type_joueur;
        Couleur couleur;
        
    public:
        // CONSTRUCTEURS
        Joueur(Type_joueur type_joueur, Couleur couleur);

        // DESTRUCTEUR
        ~Joueur();

        // METHODES
        int get_score();
        Couleur get_couleur();
        void add_score(int score);
        Type_joueur get_type_joueur();
};

#endif // JOUEUR_HPP
