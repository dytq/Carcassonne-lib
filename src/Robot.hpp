#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "Joueur.hpp"
#include "Plateau.hpp"

class Robot : public Joueur
{
    public: 
        static enum Type_robot{ALEAT,MINIMAX} type_robot_enumm;
    
    private:
        Type_robot type_robot; 

    public: 
        Robot(Type_robot type_robot);
        
        void update_ia(Plateau * plateau);
        
        int choix_de_emplacement_libre() override;
        bool choix_si_poser_meeple() override;
        int choix_de_element_libre() override; 
};

#endif // ROBOT_HPP
