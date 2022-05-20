#include "Robot.hpp"    

Robot::Robot(Type_robot type_robot)
{
    this->type_robot = type_robot;
    Joueur::score = 0;
    srand(time(0)); // robot aléatoire
}

void Robot::script_robot_aleat(Plateau * plateau, Tuile * tuile)
{      
    Logging::log(Logging::DEBUG, "robot choisi emplacement %d", tuile->get_id());
    //plateau->calcul_emplacements_libres(tuile);
    
    //int size_liste = plateau->get_liste_tuiles_emplacements_libres().size();

    this->indice_emplacement_libre = 0;

    Logging::log(Logging::DEBUG, "emplacement choisi %d, %d", indice_emplacement_libre, (int) plateau->get_liste_tuiles_emplacements_libres().size());

    //std::array<int,3> emplacement = plateau->get_liste_tuiles_emplacements_libres()[indice_emplacement_libre];
    /*
    plateau->poser_tuile(tuile, emplacement); // virutal board

    if(plateau->get_nbr_meeple(this) > 0)
    {
        this->si_poser_meeple = rand() % 2;
        if(si_poser_meeple) 
        {
            plateau->calculer_element_libres(tuile);
            int size_liste_element = plateau->get_element_libre().size();
            if(size_liste_element > 0)
            {
                this->indice_element_libre = rand() % size_liste_element;
                Logging::log(Logging::DEBUG, "robot pose meeple sur element: %d",this->indice_element_libre);
            }
        }
    }
    else
    {
        this->si_poser_meeple = false;
    }
    */
     this->si_poser_meeple = false;
}

void Robot::script_robot_minimax(Plateau * plateau, Tuile * tuile)
{
    // TODO
}

void Robot::update_ia(Plateau plateau, const Tuile * tuile_pioche)
{
    /*
    Logging::log(Logging::TRACE, "mise à jour de l'IA");    
    
    //Plateau * plateau_tmp = new Plateau(*plateau); // clonnage du plateau
    //Tuile * tuile_pioche_tmp = new Tuile(*tuile_pioche); // clonnage de la tuile
    
    if(tuile_pioche_tmp == nullptr)
    {
        Logging::log(Logging::DEBUG, "tuile pioche en paramettre de l'IA est null");
        return;
    }

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
    delete plateau_tmp;
    // delete tuile_pioche_tmp;
    */
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
    if(this->choix_si_poser_meeple() == false)
    {
        Logging::log(Logging::DEBUG, "Demande le choix de l'élément alors que le robot ne veut pas poser de meeple");
    }
    return this->indice_element_libre;
}
