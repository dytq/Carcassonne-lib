#ifndef ROBOT_HPP
#define ROBOT_HPP
#include <time.h>
#include <random>
#include "Joueur.hpp"
#include "Plateau.hpp"
#include "Tuile.hpp"
#include "Logging.hpp"

class Robot : public Joueur
{
    public: 
        static enum Type_robot{ALEAT,MINIMAX} type_robot_enumm;
    
    private:
        Type_robot type_robot; 
        int indice_emplacement_libre;
        bool si_poser_meeple;
        int indice_element_libre;
        void script_robot_aleat(Plateau * plateau, Tuile * tuile);
        void script_robot_minimax(Plateau * plateau, Tuile * tuile);

    public: 
        Robot(Type_robot type_robot);
        
        void update_ia(Plateau * plateau, Tuile * tuile_pioche);
        
        int choix_de_emplacement_libre() override;
        bool choix_si_poser_meeple() override;
        int choix_de_element_libre() override; 
};

#endif // ROBOT_HPP
