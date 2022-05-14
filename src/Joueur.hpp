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
    protected:
        int score;

    public:
        // DESTRUCTEUR
        virtual ~Joueur();

        // METHODES
        int get_score();
        void add_score(int score);
        virtual int choix_de_emplacement_libre(); 
        virtual bool choix_si_poser_meeple();
        virtual int choix_de_element_libre();
};

#endif // JOUEUR_HPP
