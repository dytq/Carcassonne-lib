#ifndef JOUEUR_H
#define JOUEUR_H

#include <array>
#include <string>

#include "Meaple.h"
#include "Carte.h"

class Joueur {

    private:
        std::array<Meaple *,7> meaples;
        int score;
        std::string nom_joueur;

    public:
        static enum Type_joueur{ROBOT, HUMAIN} Type_joueur_enum;

        Joueur(Type_joueur type_joueur);
        std::string get_nom();
        void set_nom(std::string nom);
        void poser_meaples(Carte * carte, Element * element);
        int get_score();
        void ajouter_points(int points);
        bool list_meaple_vide();
        ~Joueur() {}
};

#endif // JOUEUR_H
