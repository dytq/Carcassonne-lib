// LIBRAIRIES
#include "Plateau.hpp"

// FONCTIONS
Plateau::Plateau()
{
    Logging::log(Logging::TRACE, "Création du plateau");
}

Plateau::~Plateau()
{}

void Plateau::init_plateau()
{
    Logging::log(Logging::TRACE, "Initilisation de la grille");

    for(int i = 0; i < (NBR_TUILES * 2); i++)
    {
        for(int j = 0; j < (NBR_TUILES * 2); j++)
        {
            this->grille[i][j] = nullptr;
        }
    }
   
    Logging::log(Logging::DEBUG, "Ajout de la Tuile de base au plateau %d ", pioche[0]);
    
    std::array<int, 3> coord = {NBR_TUILES-1, NBR_TUILES-1, 0};
    this->poser_tuile(pioche[0], coord);
    pioche.erase(pioche.begin());
}

void Plateau::ajouter_joueur(Joueur * joueur, Pion * pion)
{
    this->mapJoueursPions.insert(std::pair<Joueur *, Pion *>(joueur, pion));
}

Tuile *Plateau::piocher_tuile_aleat()
{
    srand(time(NULL));
	int random = rand() % this->pioche.size();
    Logging::log(Logging::TRACE, "Pioche la tuile %d", random);
    return this->piocher_tuile(random);
}

Tuile *Plateau::piocher_tuile(int index)
{
    Tuile *tuile = this->pioche[index];
	pioche.erase(pioche.begin() + index);
    return tuile;
}      

Tuile *Plateau::get_tuile_grille(int x, int y)
{
    return this->grille[x][y];
}

/**
 * @title : Calculer les emplacments libres
 *
 * tuiles candidates, on effectue des rotations et on vérifie si les 
 * interfaces de bordures sont compatibles.
 *
 * @param : tuile : tuile à poser
 * */
void Plateau::calcul_emplacements_libres(Tuile *tuile)
{
    this->liste_tuiles_emplacements_libres.clear();
    // Logging::log(Logging::TRACE, "Tuile = %d", tuile->getId());
    // On parcourt la liste des emplacements candidates
    for(auto tuile_candidate : this->tuiles_candidates) 
    {
        std::pair<int, int> emplacement = tuile_candidate.second;
        // Logging::log(Logging::DEBUG, "Tuile candidates : <%d,%d> %d", emplacement.first, emplacement.second, tuile_candidate.first->getId());
        std::array<std::pair<int,int>, 4> tuile_coords_voisines = {
            std::make_pair(emplacement.first, emplacement.second + 1),
            std::make_pair(emplacement.first + 1, emplacement.second),
            std::make_pair(emplacement.first, emplacement.second - 1),
            std::make_pair(emplacement.first - 1, emplacement.second)
        };
        
        int bordure_voisines = 2;
        int bordure_tuiles = 0;


        for(int i = 0; i < 4; i++)  // on tourne la carte 
        {
            bool est_compatible = true; // permet de savoir si c'est compatible 
            
            for(auto tuile_coord_voisine : tuile_coords_voisines)
            {
            
                Tuile *tuile_voisine = this->grille[tuile_coord_voisine.first][tuile_coord_voisine.second];
                if(tuile_voisine != nullptr)
                {
                    if(tuile_voisine->get_id() != -1)
                    {

                        //Logging::log(Logging::DEBUG, "Tuile voisine %d", tuile_voisine->getId());
                        //Logging::log(Logging::DEBUG, "Comparaison des bordures voisines <%d==%d> ", bordure_voisines, bordure_tuiles);
                         
                        Bordure *bordure_voisine = tuile_voisine->getBordure(bordure_voisines);
                        Bordure *bordure_tuile = tuile->getBordure(bordure_tuiles);
                        
                        for(int k = 0; k < 3; k++) 
                        {
                            //Logging::log(Logging::DEBUG, "Tuile voisine bordure %d", bordure_voisine->get_bordure_fils(k)->get_type_element());
                            //Logging::log(Logging::DEBUG, "Tuile bordure Tuile pioche %d", bordure_tuile->get_bordure_fils(k)->get_type_element());
                            Noeud::type_element type_element_voisine = bordure_voisine->get_bordure_fils(2 - k)->get_type_element();
                            Noeud::type_element type_element_tuile = bordure_tuile->get_bordure_fils(k)->get_type_element();
                            if(type_element_tuile == Noeud::VILLE || type_element_tuile == Noeud::VILLE_BLASON)
                            {
                                if(type_element_voisine != Noeud::VILLE && type_element_voisine != Noeud::VILLE_BLASON)
                                {
                                    est_compatible = false;
                                }

                            } 
                            else 
                            {
                                if(type_element_tuile != type_element_voisine)
                                {
                                    est_compatible = false;
                                }
                            }
                        }
                    } 
                }
                bordure_voisines = (1 + bordure_voisines) % 4;
                bordure_tuiles = (1 + bordure_tuiles) % 4;
            }
            if(est_compatible)
            {
                std::array<int, 3> emplacement_libre = {emplacement.first, emplacement.second, i};
                this->liste_tuiles_emplacements_libres.push_back(emplacement_libre);
                //Logging::log(Logging::DEBUG, "ajout de l'emplacement libre <%d,%d,%d>", emplacement_libre.at(0), emplacement_libre.at(1), emplacement_libre.at(2));
            }
            tuile->rotationHoraire();
        }   
        //Logging::log(Logging::DEBUG, "on change d'emplacement");
    }
}

/** 
 * @titre : Fonction qui permet de poser une tuile sur le plateau.
 *
 * @description : Place une tuile selon les paramètres données par 
 * emplacement. La tuile peut prendre la place d'une tuile candidates 
 * qui sera remplacé par la tuile placée. Les bordures sont connectées 
 * entre les deux tuiles.
 *
 * @param tuile : tuile à poser
 * @param coord : coordonnées de la tuile
 */
void Plateau::poser_tuile(Tuile *tuile, std::array<int, 3> emplacement)
{
    // effectue la rotation de la tuile à placer
    for(int i = 0; i < emplacement.at(2); i++)
    {
        tuile->rotationHoraire();
    }
    
    // supprime l'ancienne tuile candidate qu'on doit remplacer 
    if(this->grille[emplacement.at(0)][emplacement.at(1)] != nullptr) {
        Tuile *tuile_a_suppr = this->grille[emplacement.at(0)][emplacement.at(1)];
        Logging::log(Logging::TRACE, "supprime tuile tmp %d : <%d %d>", tuile_a_suppr, emplacement.at(0), emplacement.at(1));
        this->tuiles_candidates.erase(tuile_a_suppr);
        this->grille[emplacement.at(0)][emplacement.at(1)] = nullptr;
    } else {
        Logging::log(Logging::DEBUG, "supprime pas tuile tmp null");
        Logging::log(Logging::DEBUG, "%d <%d,%d>", this->grille[emplacement.at(0)][emplacement.at(1)], emplacement.at(0), emplacement.at(1));
    }

    // placement de la tuile (tableau de rotation de tuile)
    this->grille[emplacement.at(0)][emplacement.at(1)] = tuile;

    // liste des coordonnées des voisins de la tuile 
    std::array<std::pair<int,int>, 4> tuile_voisines = {
        std::make_pair(emplacement.at(0), emplacement.at(1) + 1),
        std::make_pair(emplacement.at(0) + 1, emplacement.at(1)),
        std::make_pair(emplacement.at(0), emplacement.at(1) - 1),
        std::make_pair(emplacement.at(0) - 1, emplacement.at(1))
    };
    
    // les interfaces des tuiles voisines sont décalés 
    int bordure_voisines = 2; 
    int bordure_tuiles = 0;


    // ajout des tuiles candidates sur la grille et connection des bordures
    for(auto tuile_coord_voisine : tuile_voisines)
    {
        Tuile * tuile_voisine = this->grille[tuile_coord_voisine.first][tuile_coord_voisine.second];

        if(tuile_voisine == nullptr)
        {
            std::array<Bordure *, 4> bordure_tmp;
            std::vector<Element *> element_tmp;
            Tuile * tuile_candidate = new Tuile(-1, bordure_tmp, element_tmp);
            this->grille[tuile_coord_voisine.first][tuile_coord_voisine.second] = tuile_candidate;
            this->tuiles_candidates[tuile_candidate] = std::make_pair(tuile_coord_voisine.first,tuile_coord_voisine.second);
        } 
        else 
        {
            if(tuile_voisine->get_id() != -1) 
            {
                Logging::log(Logging::TRACE, "set border tuile voisine %d", tuile_voisine->get_id());
                for(int i = 0; i < 3; i++)
                {
                    Bordure * bordure_tuile_voisine_fils = tuile_voisine->getBordure(bordure_voisines)->get_bordure_fils(i);
                    Bordure * bordure_tuile_fils = tuile->getBordure(bordure_tuiles)->get_bordure_fils(2 - i); // inverse le sens depuis le reférencielle de l'autre tuile
                    
                    if(bordure_tuile_voisine_fils->get_type_element() != Noeud::VOID) 
                    {
                        // on enlève le pointeur nullptr des bodures fils des tuiles 
                        bordure_tuile_voisine_fils->remove_tuile_voisin(nullptr);
                        bordure_tuile_fils->remove_tuile_voisin(nullptr); 
                        bordure_tuile_voisine_fils->set_voisin(bordure_tuile_fils);      
                    }
                }
            }
        }

        bordure_tuiles = (1 + bordure_tuiles) % 4;      
        bordure_voisines = (1 + bordure_voisines) % 4;
    }
}

/**
 * Recherche le Joueur qui à obtenue le plus de pions.
 *
 * @param mapJoueurListeMeeple Joueur associé à une liste de Meeple
 * */
int rechercher_max_list_meeple(std::map<Joueur *, std::list<Meeple *>> mapJoueurListeMeeple) 
{
    std::list<Joueur *> list_joueur;
    int max = 0;
    for(auto const & joueur : mapJoueurListeMeeple)
    {
        int tmp = joueur.second.size();
        if(max < tmp) {
            max = tmp;
        }
    }
    return max;
}

/**
 * @titre : Désindexe les Meeples du plateau.
 *
 * @param mapJoueurListeMeeple Joueur associé à une liste de Meeple 
 * */
void Plateau::desindexer_Meeple_dans_la_map(std::map<Joueur*, std::list<Meeple *>> mapJoueurListeMeeple)
{
    Logging::log(Logging::TRACE, "Desindexation des meeples");
    for(auto const & itMap : mapJoueurListeMeeple)
    {
        Joueur * joueur = itMap.first;
        for(auto const &meeple : itMap.second)
        {
            this->mapJoueursPions.at(joueur)->supprimer_meeple(meeple);
            //Logging::log(Logging::TRACE, "Desindexe meeple: %d du joueur %d",meeple, joueur->get_type_joueur() + 1);
        }
    }
}

/**
 * @title : Evaluation des Meeples pour chaque Joueurs
 *
 * @description : Cette méthode permet d'à partir de chaque Meeple 
 * des Joueurs d'évaluer s'il y a possibilité d'attribuer des points 
 * aux Joueurs. L'évaluation s'effectue sur tous les Meeples et les 
 * points sont distribuée selon la quantité de Meeple obtenu 
 * (pour l'évalation concurrencielle, ce n'est pas le cas pour les 
 * abbayes par exemple)
 *
 * @param status_du_jeu :  permet de faire une évaluation soit final 
 * soit en cours du jeu
 * */
void Plateau::evaluer_meeple(int status_du_jeu)
{
    for(auto const &itMap : this->mapJoueursPions)
    {
        //Logging::log(Logging::TRACE, "Evaluation pour des meeples du Joueur %d", itMap.first->get_couleur());
        const std::array<Meeple *, 7> arrayMeeple = itMap.second->get_stack_meeple();

        for(auto const &itMeeple : arrayMeeple)
        {
            if(itMeeple != nullptr)
            {
                int score = 0;
                std::map<Joueur *, std::list<Meeple *>> mapJoueurListeMeeple; // Associe un joueur et une pile de pions
                Logging::log(Logging::TRACE, "Comptage de points");
                bool est_complet = itMeeple->compter_points(status_du_jeu, & mapJoueurListeMeeple, &score);
                Logging::log(Logging::TRACE, "Score obtenu : %d", score);

                if(est_complet == true || status_du_jeu == STATUS_FINAL)
                {
                    Logging::log(Logging::TRACE, "Evaluation des points");
                    int max_lenght = 0; // valeur max de meeple
                    max_lenght = rechercher_max_list_meeple(mapJoueurListeMeeple);
                    Logging::log(Logging::TRACE, "max meeple: %d", max_lenght);
                    for(auto const &mapitr : mapJoueurListeMeeple)
                    {
                        if((int) mapitr.second.size() == max_lenght)
                        {
                            mapitr.first->add_score(score);
                            Logging::log(Logging::TRACE, "ajout du score %d",score);
                        }
                    }
                    this->desindexer_Meeple_dans_la_map(mapJoueurListeMeeple);
                }
            }
        }
    }
}

std::vector<std::array<int, 3>> Plateau::get_liste_tuiles_emplacements_libres()
{
    return this->liste_tuiles_emplacements_libres;
}

bool Plateau::stack_meeple_vide(Joueur * joueur)
{
    return this->mapJoueursPions.at(joueur)->si_pion_non_place();
}

/**
 * Permet de poser un meeple
 *
 * @return bool si le meeple peut être posé
 * */
void Plateau::poser_meeple(Joueur * joueur, Element *elem, Meeple * meeple, int indice)
{
    Logging::log(Logging::DEBUG, "Ajout meeple %d dans element", meeple);
    elem->ajouter_meeple(meeple);
    // Logging::log(Logging::DEBUG, "Ajout meeple %d dans pion pour le joueur %d", meeple, joueur->get_type_joueur());
    Pion * pion = this->mapJoueursPions.at(joueur);
    pion->ajouter_meeple(meeple, indice);
}

void Plateau::poser_meeple(Joueur * joueur, Element *elem, std::pair<int, int> position)
{
    Meeple * meeple = Pion::generate_meeple(joueur, elem, &this->grille, position);
    elem->ajouter_meeple(meeple);
    Pion * pion = this->mapJoueursPions.at(joueur);
    pion->ajouter_meeple(meeple, pion->get_premier_indice_libre());
}

void Plateau::ajouter_tuile_pioche(Tuile *tuile)
{
    this->pioche.push_back(tuile);
}

/**
 * @title: Vérifie si il y a un meeple dans une même zone
 *
 * @description: réalise un parcours en profondeur et récolte les meeples.
 *
 * @param: Noeud est le noeud de départ
 * @param: type_element pour ne faire que le parcour si un même type d'éléments 
 *
 * @return si il y a un meeple sur une même zone
 * */
bool Plateau::verifier_si_meeple_voisin(Noeud * noeud, Noeud::type_element type_element) 
{
    std::list<Noeud*> pilenoeud;   // pile pour le parcours des fils
    std::list<Noeud*> noeudmarque; // marque tous les noeuds rencontrés

    bool meeple_est_present = false;

    pilenoeud.push_back(noeud);
    noeudmarque.push_back(noeud);
   
    while(!pilenoeud.empty())
    {
        std::list<Noeud*>::iterator iterNoeud = pilenoeud.begin();

        Noeud * noeudcentrale = *iterNoeud;
        
        Element * element = dynamic_cast<Element *>(noeudcentrale);
        if(element != nullptr)
        {
            if(noeudcentrale != noeud)
            {
                Meeple * meeple = element->get_meeple();
                if(meeple != nullptr) 
                {
                    Logging::log(Logging::DEBUG, "meeple trouvé %d %d", meeple->get_noeud()->get_type_element(), type_element);
                    meeple_est_present = true;
                    break;
                }
            }
            
        } 

        // logging::log(logging::trace, "evaluation d'un noeud %d", noeudcentrale);
        
        pilenoeud.pop_front();

        int i;
    
        for(i = 0; i < noeudcentrale->get_nbr_voisins(); i++)
        {
            Noeud * noeud_fils = noeudcentrale->get_voisin(i);
            // logging::log(logging::trace, "noeud fils %d %d", i, noeud_fils);
            // logging::log(logging::trace, "noeud fils %d est non null", i);
            if(noeud_fils != nullptr)
            {
                if(Noeud::compare_type_element(noeud_fils->get_type_element(), type_element)) // un prés peut pointer vers une ville
                {
                    if(noeudmarque.end() == std::find(noeudmarque.begin(), noeudmarque.end(), noeud_fils))
                    {
                        //logging::log(logging::trace, "noeud fils %d n'est pas marqué", i);
                        pilenoeud.push_back(noeud_fils);
                        noeudmarque.push_back(noeud_fils);
                    } else {
                        //logging::log(logging::trace, "noeud fils %d est déjà marqué", i);
                    }
                }
            }
        }
    }
    return meeple_est_present;
}

int Plateau::get_nbr_meeple(Joueur * joueur) 
{
    Pion *pion = this->mapJoueursPions[joueur];
    return pion->get_nbr_meeple();
}

void Plateau::calculer_element_libre(Tuile * tuile) {
    std::vector<Element *> list_elements = tuile->getElements();
    this->element_libre.clear();

    for(auto element : list_elements) {
        if(! Plateau::verifier_si_meeple_voisin(element, element->get_type_element())) 
        {
            this->element_libre.push_back(element);
        }
    }
}

const std::vector<Element *> Plateau::get_element_libre() 
{
    return this->element_libre;
}

const std::array<std::array<Tuile *, 144>, 144> * Plateau::get_grille() 
{
    return &this->grille;
}

Pion * Plateau::get_pion_joueur(Joueur * joueur) 
{
    return this->mapJoueursPions[joueur];
}

bool Plateau::pioche_est_vide()
{
    if(this->pioche.empty()) {
        return true;
    }
    return false;
}
