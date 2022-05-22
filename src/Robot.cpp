#include "Robot.hpp"  
#include <float.h>  

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

void Robot::minimax(Plateau *plateau, Tuile *tuile, float *meilleur_score, int *meilleur_choix)
{
    // Calcul des emplacements libres, nous devrons en choisir un donc donner l'indice
    // du meilleur choix et le meilleur score correspondant
    plateau->calcul_emplacements_libres(tuile);

    // Itération sur toutes les possibilités du robot
    for(long unsigned int i = 0; i < plateau->get_liste_tuiles_emplacements_libres().size(); i++)
    {
        Tuile *tuile_tmp = new Tuile(*tuile);

        plateau->add_child();
        plateau->set_at_back_child();

        std::array<int, 3> emplacement = plateau->get_liste_tuiles_emplacements_libres()[i];
        plateau->poser_tuile(tuile_tmp, emplacement);

        plateau->calculer_element_libres(tuile_tmp);
        int size_liste_element = plateau->get_element_libre().size();

        float score_courant = -FLT_MIN;

        if(size_liste_element > 0)
        {
            for(int j = 0; j < size_liste_element; j++)
            {
                score_courant = Pion::estimer_element_points(this, plateau->get_element_libre().at(j),
                STATUS_EN_COURS, plateau->get_grille(), {emplacement[0], emplacement[1]});

                if(score_courant > *meilleur_score)
                {
                    this->si_poser_meeple = true;
                    this->indice_element_libre = j;
                    *meilleur_score = score_courant;
                }
            }
        }

        else
        {
            score_courant = 0;
            this->si_poser_meeple = false;
        }

        float meilleur_score_adversaire_pondere = -FLT_MIN;

        // Itération sur toutes les possibilités de l'adversaire
        for(int j = 0; j < NBR_TYPES_TUILES; j++)
        {
            if(plateau->proba_type_tuile(j) > 0)
            {
                Tuile *tuile_courante = new Tuile(*plateau->piocher_tuile_type(j));
                
                float proba_tuile_courante = plateau->proba_type_tuile(tuile_courante->get_id_groupe());
                plateau->calcul_emplacements_libres(tuile_courante);

                // Itération sur les types de tuiles tirables et leur probabilité de sortir
                for(unsigned long int k = 0; k < plateau->get_liste_tuiles_emplacements_libres().size(); k++)
                {
                    float score_adversaire_courant = -FLT_MIN;

                    plateau->add_child();
                    plateau->set_at_back_child();
                    std::array<int, 3> emplacement_courant = plateau->get_liste_tuiles_emplacements_libres()[k];
                    plateau->poser_tuile(tuile_courante, emplacement_courant);

                    plateau->calculer_element_libres(tuile_courante);
                    int size_liste_element_courant = plateau->get_element_libre().size();

                    if(size_liste_element_courant > 0)
                    {
                        for(int l = 0; l < size_liste_element_courant; l++)
                        {
                            score_adversaire_courant = Pion::estimer_element_points(this, plateau->get_element_libre().at(l),
                            STATUS_EN_COURS, plateau->get_grille(), {emplacement[0], emplacement[1]});

                            if(score_adversaire_courant > *meilleur_score)
                            {
                                this->si_poser_meeple = true;
                                this->indice_element_libre = l;
                                *meilleur_score = score_adversaire_courant;
                            }
                        }
                    }

                    else
                    {
                        score_adversaire_courant = 0;
                        this->si_poser_meeple = false;
                    }

                    meilleur_score_adversaire_pondere = score_adversaire_courant * proba_tuile_courante;

                    if((score_adversaire_courant * proba_tuile_courante) > meilleur_score_adversaire_pondere)
                    {
                        meilleur_score_adversaire_pondere = score_adversaire_courant * proba_tuile_courante;
                    }

                    plateau->remove_back_child();
                }

                delete tuile_courante;
            }
        }
        
        score_courant -= meilleur_score_adversaire_pondere;

        if(score_courant > *meilleur_score)
        {
            *meilleur_score = score_courant;
            *meilleur_choix = i;
        }

        delete tuile_tmp;

        plateau->remove_back_child();
    }
}

void Robot::script_robot_minimax(Plateau *plateau, Tuile *tuile)
{
    Tuile *tuile_tmp = new Tuile(*tuile);

    // Variables à chercher
    float meilleur_score = -FLT_MIN;
    int meilleur_choix = 0;

    // Minimax en profondeur 2
    minimax(plateau, tuile_tmp, &meilleur_score, &meilleur_choix);

    // Affectation de l'indice à choisir et pose de la tuile
    this->indice_emplacement_libre = meilleur_choix;
    std::array<int, 3> emplacement = plateau->get_liste_tuiles_emplacements_libres()[indice_emplacement_libre];
    plateau->poser_tuile(tuile, emplacement);

    // Emplacement du meeple
    plateau->calculer_element_libres(tuile);
    int size_liste_element_courant = plateau->get_element_libre().size();
    float meilleur_score_meeple = -FLT_MIN;

    if(size_liste_element_courant > 0)
    {
        for(int i = 0; i < size_liste_element_courant; i++)
        {
            float score_meeple = Pion::estimer_element_points(this, plateau->get_element_libre().at(i),
            STATUS_EN_COURS, plateau->get_grille(), {emplacement[0], emplacement[1]});

            if(score_meeple > meilleur_score_meeple)
            {
                this->si_poser_meeple = true;
                this->indice_element_libre = i;
                meilleur_score_meeple = score_meeple;
            }
        }
    }

    else
    {
        this->si_poser_meeple = false;
    }

    delete tuile_tmp;
}

void Robot::update_ia(Plateau * plateau, Tuile * tuile_pioche)
{
    Logging::log(Logging::TRACE, "mise à jour de l'IA");    
    Tuile * tuile_pioche_tmp = new Tuile(*tuile_pioche);

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
