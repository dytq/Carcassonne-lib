#include "Robot.hpp"    

Robot::Robot(Type_robot type_robot)
{
    this->type_robot = type_robot;
    Joueur::score = 0;
}

void Robot::script_robot_aleat(Plateau * plateau, Tuile * tuile)
{
    Logging::log(Logging::DEBUG, "tuile %d", tuile);
           
    plateau->add_child();            // plateau ajout un enfant de lui meme
    plateau->set_at_back_child();    // on se met au niveau de l'enfant
    
    plateau->get_liste_tuiles_emplacements_libres().clear();

    plateau->calcul_emplacements_libres(tuile);
    std::vector<std::array<int,3>> liste_tuiles_emplacements_libres = plateau->get_liste_tuiles_emplacements_libres();

    int size_liste = plateau->get_liste_tuiles_emplacements_libres().size();

    this->indice_emplacement_libre = rand() % size_liste;
    
    for (long unsigned int i = 0; i < liste_tuiles_emplacements_libres.size(); i++) 
    {
		std::cout << "Emplacement n°" << i << " :\n"
			 << "Abscisse :\t" << liste_tuiles_emplacements_libres.at(i).at(0) << "\tOrdonnée :\t" << liste_tuiles_emplacements_libres.at(i).at(1) << "\tOrientation :\t" << (liste_tuiles_emplacements_libres.at(i).at(2) * 90) << "°" << std::endl;
	}
    
    Logging::log(Logging::DEBUG, "Robot a choisi emplacement %d/%d", indice_emplacement_libre, (int) plateau->get_liste_tuiles_emplacements_libres().size());

    std::array<int,3> emplacement = plateau->get_liste_tuiles_emplacements_libres()[indice_emplacement_libre];
        
    plateau->poser_tuile(tuile, emplacement);

    Logging::log(Logging::DEBUG, "Robot à %d meeple", plateau->get_nbr_meeple(this));

    if(plateau->get_nbr_meeple(this) > 0)
    {
        Logging::log(Logging::DEBUG, "Robot à assez de meeple pour placer son meeple");
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(1,6);
        int si_veut_placer = distribution(generator); 
        Logging::log(Logging::DEBUG, ">> %d", si_veut_placer);
        if(si_veut_placer < 50) // 50% de chance 
        {
             Logging::log(Logging::DEBUG, ">> true");
            this->si_poser_meeple = true;
        }
        else  
        {
            this->si_poser_meeple = false;
        }
        if(this->si_poser_meeple == true)
        {
            Logging::log(Logging::DEBUG, "Robot veut placer un Meeple");
            plateau->calculer_element_libres(tuile);
            int size_liste_element = plateau->get_element_libre().size();
            if(size_liste_element > 0)
            {
                this->indice_element_libre = rand() % size_liste_element;
                Logging::log(Logging::DEBUG, "Robot veut placer son Meeple à %d", this->indice_element_libre);
            }
            else 
            {
                Logging::log(Logging::DEBUG, "Robot ne peux pas placer de Meeple");
                this->si_poser_meeple = false;
            }
        }
    }
    else
    {
        this->si_poser_meeple = false;
    }
    
    plateau->remove_back_child(); // supprime le dernier et revient à l'état d'avant (root)
}

void Robot::minimax(Plateau *plateau, Tuile *tuile, uint32_t *meilleur_score, int *meilleur_choix)
{
    plateau->calcul_emplacements_libres(tuile);
    int size_liste = plateau->get_liste_tuiles_emplacements_libres().size();

    for(int i = 0; i < size_liste; i++)
    {
        plateau->add_child();
        plateau->set_at_back_child();
        std::array<int, 3> emplacement = plateau->get_liste_tuiles_emplacements_libres()[i];
        plateau->poser_tuile(tuile, emplacement);

        uint32_t score_courant = 0;  // Calculer score pour ce choix
        uint32_t meilleur_score_adversaire_pondere = INT32_MIN;

        for(int j = 0; j < NBR_TYPES_TUILES; j++)
        {
            //tuile_courante = ;
            //float proba_tuile_courante = ;
            //plateau->calcul_emplacements_libres(tuile_courante);

            for(int k = 0; k < plateau->get_liste_tuiles_emplacements_libres().size(); k++)
            {
                // Calculer meilleur score adversaire pondere par la probabilité pour lui de
                // piocher cette tuile
                /*

                uint32_t score_adversaire_courant = INT32_MIN;

                plateau->add_child();
                plateau->set_at_back_child();
                std::array<int, 3> emplacement = plateau->get_liste_tuiles_emplacements_libres()[];
                plateau->poser_tuile(tuile, emplacement);

                if((score_adversaire_courant * proba_tuile_courante) > meilleur_score_adversaire_pondere)
                {
                    meilleur_score_adversaire_pondere = score_adversaire_courant * proba_tuile_courante;
                }

                plateau->remove_back_child();
                */
            }
        }
        
        score_courant -= meilleur_score_adversaire_pondere;

        if(score_courant > *meilleur_score)
        {
            *meilleur_score = score_courant;
            *meilleur_choix = i;
        }

        plateau->remove_back_child();
    }
}

void Robot::script_robot_minimax(Plateau *plateau, Tuile *tuile)
{
    plateau->add_child();
    plateau->set_at_back_child();
    uint32_t meilleur_score = INT32_MIN;
    int meilleur_choix = 0;

    minimax(plateau, tuile, &meilleur_score, &meilleur_choix);

    this->indice_emplacement_libre = meilleur_choix;
    std::array<int, 3> emplacement = plateau->get_liste_tuiles_emplacements_libres()[indice_emplacement_libre];
    plateau->poser_tuile(tuile, emplacement);

    if(plateau->get_nbr_meeple(this) > 0)
    {
        this->si_poser_meeple = true;

        if(true) 
        {
            plateau->calculer_element_libres(tuile);
            int size_liste_element = plateau->get_element_libre().size();

            if(size_liste_element > 0)
            {
                this->indice_element_libre = rand() % size_liste_element;
            }

            else 
            {
                this->si_poser_meeple = false;
            }
        } 
    }

    else
    {
        this->si_poser_meeple = false;
    }

    plateau->remove_back_child();
}

void Robot::update_ia(Plateau * plateau, Tuile * tuile_pioche)
{
    Logging::log(Logging::TRACE, "mise à jour de l'IA");    
    Tuile * tuile_pioche_tmp = tuile_pioche  = new Tuile(*tuile_pioche);

    if(tuile_pioche_tmp == nullptr)
    {
        Logging::log(Logging::DEBUG, "tuile pioche en paramettre de l'IA est null");
        return;
    }

    switch(this->type_robot)
    {
        case(Robot::ALEAT):
             script_robot_aleat(plateau, tuile_pioche_tmp);
             break;
        
        case(Robot::MINIMAX):
             script_robot_minimax(plateau, tuile_pioche_tmp);
             break;
        
        default:
             Logging::log(Logging::DEBUG, "Type de l'IA non reconnu, initialisation des données par défaut");
             indice_emplacement_libre = 0;
             si_poser_meeple = false;
             indice_element_libre = 0;
    } 
    //tuile_pioche_tmp->reset_rotation();
    //delete tuile_pioche_tmp;
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
        Logging::log(Logging::DEBUG, "Demande le choix de l'élément alors que le robot ne veut pas poser de meeple, retourne le choix 0");
        return 0;
    }
    return this->indice_element_libre;
}
