#include "Robot.hpp"

Robot::Robot(Type_robot type_robot)
{
    this->type_robot = type_robot;
    Joueur::score = 0;
}

void Robot::update_ia(Plateau * plateau)
{

}

int Robot::choix_de_emplacement_libre()
{
    return 0;
}

bool Robot::choix_si_poser_meeple()
{
    return false;
}

int Robot::choix_de_element_libre()
{
    return 0;
}
