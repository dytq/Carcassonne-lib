#include "Robot.hpp"

Robot::Robot(Type_robot type_robot)
{
    this->type_robot = type_robot;
    Joueur::score = 0;
}

void Robot::script_robot_aleat(Plateau * plateau, Tuile * tuile)
{
    // TODO
    this->indice_emplacement_libre = 0;
    this->si_poser_meeple = false;
    this->indice_element_libre = 0;
}

void Robot::script_robot_minimax(Plateau * plateau, Tuile * tuile)
{
    // TODO
}

void Robot::update_ia(const Plateau * plateau, const Tuile * tuile_pioche)
{
    Logging::log(Logging::TRACE, "mise à jour de l'IA");
    
    Plateau * plateau_tmp = new Plateau(*plateau); // clonnage du plateau
    Tuile * tuile_pioche_tmp = new Tuile(*tuile_pioche); // clonnage de la tuile
    
    switch(this->type_robot)
    {
        case(Robot::ALEAT):
             script_robot_aleat(plateau_tmp, tuile_pioche_tmp);
             break;
        
        case(Robot::MINIMAX):
             script_robot_minimax(plateau_tmp, tuile_pioche_tmp);
             break;
        
        default:
             Logging::log(Logging::DEBUG, "Type de l'IA non reconnu, initialisation des données par défaut");
             indice_emplacement_libre = 0;
             si_poser_meeple = false;
             indice_element_libre = 0;
    } 
    // delete plateau_tmp;
    // delete tuile_pioche_tmp;
}

int Robot::choix_de_emplacement_libre()
{
    return this->indice_emplacement_libre;
}

bool Robot::choix_si_poser_meeple()
{
    return this->si_poser_meeple;
}

int Robot::choix_de_element_libre()
{
    return this->indice_element_libre;
}
