// DIRECTIVES
#ifndef JOUEUR_HPP
#define JOUEUR_HPP

// LIBRAIRIES
#include <list>
#include <string>

#include "Meeple.hpp"
#include "Carte.hpp"

// CLASSE
class Joueur
{
    private:
        // VARIABLES
        std::list<Meeple *> meeple_stack;
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
        void poser_meaples(Carte * carte, Element * element);
        int get_score();
        void ajouter_points(int points);

        void ajouter_meeple_list(Meeple * meeple);
        void supprimer_meeple_list(Meeple * meeple);
        bool meeple_list_est_vide();
        const std::list<Meeple *> list_meeple();

};

#endif
