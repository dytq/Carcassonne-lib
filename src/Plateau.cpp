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
    Logging::log(Logging::TRACE, "Chargement de la base de données");

    for(int i = 0; i < (NBR_TUILES * 2); i++)
    {
        for(int j = 0; j < (NBR_TUILES * 2); j++)
        {
            this->grille[i][j] = nullptr;
        }
    }
   
    Logging::log(Logging::DEBUG, "Ajout de la Tuile de base au plateau %d ", pioche[0]);
    
    this->grille[NBR_TUILES-1][NBR_TUILES-1] = pioche[0];
    pioche.erase(pioche.begin());
}

void Plateau::ajouter_joueur(Joueur * joueur, Pion * pion)
{
    this->mapJoueursPions.insert(std::pair<Joueur *, Pion *>(joueur, pion));
}

Joueur * Plateau::get_joueur()
{
    return nullptr;
}

std::vector<Tuile *> Plateau::get_pioche()
{
    return this->pioche;
}

Tuile *Plateau::piocher_tuile()
{
    srand(time(NULL));
	int random = rand() % this->pioche.size();
    Logging::log(Logging::TRACE, "Pioche la tuile %d", random);

	Tuile *tuile = this->pioche[random];
	pioche.erase(pioche.begin() + random);

    return tuile;
}

Tuile *Plateau::get_tuile_grille(int x, int y)
{
    return this->grille[x][y];
}

void Plateau::calcul_emplacements_libres(Tuile *tuile)
{
	this -> liste_tuiles_emplacements_libres.clear();

	// Listage des emplacements libres au bord du plateau dans tmp
	std::vector<std::array<int, 2>> tmp;

    for(int i = 1; i < ((NBR_TUILES * 2) - 1); i++)
	{
		for(int j = 1; i < ((NBR_TUILES * 2) - 1); i++)
		{
			if(this->grille[i][j] != nullptr)
			{
				std::array<int, 2> position = {i + 1, j};

				if((this->grille[position.at(0)][position.at(1)] == nullptr) && (std::find(tmp.begin(), tmp.end(), position) == end(tmp)))
				{
					tmp.push_back(position);
				}

				position = {i, j + 1};

				if((this->grille[position.at(0)][position.at(1)] == nullptr) && (std::find(tmp.begin(), tmp.end(), position) == end(tmp)))
				{
					tmp.push_back(position);
				}

				position = {i - 1, j};

				if((this->grille[position.at(0)][position.at(1)] == nullptr) && (std::find(tmp.begin(), tmp.end(), position) == end(tmp)))
				{
					tmp.push_back(position);
				}

				position = {i, j - 1};

				if((this->grille[position.at(0)][position.at(1)] == nullptr) && (std::find(tmp.begin(), tmp.end(), position) == end(tmp)))
				{
					tmp.push_back(position);
				}
			}
		}
	}

	// Calcul des orientations possibles pour chaque emplacement possible stocké dans tmp
	for(long unsigned int i = 0; i < tmp.size(); i++)
	{
		Tuile *copie = tuile;
        std::array<int, 2> courant = tmp.at(i);

        for(int j = 0; j < NBR_ORIENTATIONS_TUILES; j++)
        {
            if(copie->borduresCompatibles(this->grille[courant.at(0)][courant.at(1) + 1], 0)
            && copie->borduresCompatibles(this->grille[courant.at(0) + 1][courant.at(1)], 1)
            && copie->borduresCompatibles(this->grille[courant.at(0)][courant.at(1) - 1], 2)
            && copie->borduresCompatibles(this->grille[courant.at(0) - 1][courant.at(1)], 3))
            {
                this->liste_tuiles_emplacements_libres.push_back({courant.at(0), courant.at(1), j});
            }

            copie->rotationHoraire();
        }
	}
}

void Plateau::poser_tuile(Tuile *tuile, std::array<int, 3> emplacement)
{
    for(int i = 0; i < emplacement.at(2); i++)
    {
        tuile->rotationHoraire();
    }

    this->grille[emplacement.at(0)][emplacement.at(1)] = tuile;
}

Joueur *Plateau::joueur_suivant()
{
    return nullptr;
}

/**
 * Recherche le Joueur qui à obtenue le plus de pions.
 *
 * @param mapJoueurListeMeeple Joueur associé à une liste de Meeple
 * */
std::list<Joueur *> Plateau::rechercher_Joueur_plus_de_Pions(std::map<Joueur*, std::list<Meeple *>> mapJoueurListeMeeple)
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

    for(auto const & joueur : this->mapJoueursPions)
    {
        int tmp = joueur.second->get_stack_meeple().size();
        if(tmp == max)
        {
            list_joueur.push_back(joueur.first);
        }
    }

    if(list_joueur.empty())
    {
        //Logging::DEBUG("Attention il y pas de joueur qui reçoit les points lors de l'évaluation");
    }
    return list_joueur;
}

/**
 * Désindexe les Meeples du plateau.
 *
 * @param mapJoueurListeMeeple Joueur associé à une liste de Meeple */
void Plateau::desindexer_Meeple_dans_la_map(std::map<Joueur*, std::list<Meeple *>> mapJoueurListeMeeple)
{
    for(auto const & itMap : mapJoueurListeMeeple)
    {
        Joueur * joueur = itMap.first;
        for(auto const &meeple : itMap.second)
        {
            this->mapJoueursPions.at(joueur)->supprimer_meeple(meeple);
        }
    }
}

/**
 * Evaluation des Meeples pour chaque Joueurs
 *
 * Cette méthode permet d'à partir de chaque Meeple des Joueurs d'évaluer s'il y a possibilité d'attribuer des points aux Joueurs
 * L'évaluation s'effectue sur tous les Meeples et les points sont distribuée selon la quantité de Meeple obtenu (pour l'évalation concurrencielle, ce n'est pas le cas pour les abbayes par exemple)
 *
 * @param status_du_jeu permet de faire une évaluation soit final soit en cours du jeu
 * */
void Plateau::evaluer_meeple(int status_du_jeu)
{
    for(auto const &itMap : this->mapJoueursPions)
    {
        const std::list<Meeple *> listMeeple = itMap.second->get_stack_meeple();

        for(auto const &itMeeple : listMeeple)
        {
            int score = 0;
            std::map<Joueur *, std::list<Meeple *>> mapJoueurListeMeeple; // Associe un joueur et une pile de pions
            int est_tuileComparelet = itMeeple->compter_points(status_du_jeu, & mapJoueurListeMeeple, &score);

            if(est_tuileComparelet == true || status_du_jeu )
            {
                std::list<Joueur *> list_joueur_max;
                list_joueur_max = this->rechercher_Joueur_plus_de_Pions(mapJoueurListeMeeple);// problème: en cas d'égalité
                for(auto const & joueur : list_joueur_max)
                {
                    joueur->add_score(score);
                    // Logging
                }
                this->desindexer_Meeple_dans_la_map(mapJoueurListeMeeple);
            }
        }
    }
}

std::list<Joueur *> Plateau::get_joueur_liste()
{
    return this->list_joueur;
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
 * @return bool si le meeple peut être posé|     pioche.erase(0);
 * */
void Plateau::poser_meeple(Joueur * joueur, Element *elem, Tuile * tuile)
{
    Meeple * meeple = Pion::generate_meeple(joueur, elem, tuile);
    elem->ajouter_meeple(meeple);
    Pion * pion = this->mapJoueursPions.at(joueur);
    pion->ajouter_meeple(meeple);
}

void Plateau::ajouter_tuile_pioche(Tuile *tuile)
{
    this->pioche.push_back(tuile);
}
