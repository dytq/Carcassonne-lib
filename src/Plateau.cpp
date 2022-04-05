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
            grille[i][j] = nullptr;
        }
    }
    grille[NBR_TUILES-1][NBR_TUILES-1] = pioche[0];
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
	int random = rand() % pioche.size();
	Tuile *tmp = pioche[random];

	pioche.erase(pioche.begin());

    return tmp;
}

void Plateau::calcul_emplacements_libres(Tuile *tuile)
{
	this -> liste_tuiles_emplacements_libres.clear();

	// Calcul des emplacements libres
	std::vector<std::array<int, 2>> tmp;

    for(int i = 0; i < (NBR_TUILES * 2); i++)
	{
		for(int j = 0; i < (NBR_TUILES * 2); i++)
		{
			if(grille[i][j] != nullptr)
			{
				std::array<int, 2> element = {i + 1, j};

				if((grille[i + 1][j] == nullptr) && (std::find(tmp.begin(), tmp.end(), element) == end(tmp)))
				{
					tmp.push_back(element);
				}

				element = {i, j + 1};

				if((grille[i + 1][j] == nullptr) && (std::find(tmp.begin(), tmp.end(), element) == end(tmp)))
				{
					tmp.push_back(element);
				}

				element = {i - 1, j};

				if((grille[i + 1][j] == nullptr) && (std::find(tmp.begin(), tmp.end(), element) == end(tmp)))
				{
					tmp.push_back(element);
				}

				element = {i, j - 1};

				if((grille[i + 1][j] == nullptr) && (std::find(tmp.begin(), tmp.end(), element) == end(tmp)))
				{
					tmp.push_back(element);
				}
			}
		}
	}

	// Calcul des orientations
	for(int i = 0; i < (int)tmp.size(); i++)
	{
		// Modifier pour tenir compte de toutes les tuiles voisines

        for(int j = 0; j < NBR_ORIENTATIONS_TUILES; j++)
        {
            std::array<int, 3> tuileCandidate = {tmp.at(i).at(0), tmp.at(i).at(1), j};
		    Tuile *tuileCompare = grille[tuileCandidate.at(0) + 1][tuileCandidate.at(1)];

            if((tuileCompare != nullptr)
            && (std::find(liste_tuiles_emplacements_libres.begin(), liste_tuiles_emplacements_libres.end(), tuileCandidate) == liste_tuiles_emplacements_libres.end())
            && (tuile->bordureCompatible(tuileCompare, j)))
            {
                this->liste_tuiles_emplacements_libres.push_back(tuileCandidate);
            }

            tuileCompare = grille[tuileCandidate.at(0)][tuileCandidate.at(1) + 1];

            if((tuileCompare != nullptr)
            && (std::find(liste_tuiles_emplacements_libres.begin(), liste_tuiles_emplacements_libres.end(), tuileCandidate) == liste_tuiles_emplacements_libres.end())
            && (tuile->bordureCompatible(tuileCompare, j)))
            {
                this->liste_tuiles_emplacements_libres.push_back(tuileCandidate);
            }

            tuileCompare = grille[tuileCandidate.at(0) - 1][tuileCandidate.at(1)];

            if((tuileCompare != nullptr)
            && (std::find(liste_tuiles_emplacements_libres.begin(), liste_tuiles_emplacements_libres.end(), tuileCandidate) == liste_tuiles_emplacements_libres.end())
            && (tuile->bordureCompatible(tuileCompare, j)))
            {
                this->liste_tuiles_emplacements_libres.push_back(tuileCandidate);
            }

            tuileCompare = grille[tuileCandidate.at(0)][tuileCandidate.at(1) - 1];

            if((tuileCompare != nullptr)
            && (std::find(liste_tuiles_emplacements_libres.begin(), liste_tuiles_emplacements_libres.end(), tuileCandidate) == liste_tuiles_emplacements_libres.end())
            && (tuile->bordureCompatible(tuileCompare, j)))
            {
                this->liste_tuiles_emplacements_libres.push_back(tuileCandidate);
            }	
        }
	}
}

void Plateau::poser_tuile(Tuile *tuile, std::array<int, 3> emplacement)
{

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
void Plateau::poser_meeple(Joueur * joueur, Element * element, Tuile * tuile)
{
    Meeple * meeple = Pion::generate_meeple(joueur, element, tuile);
    element->ajouter_meeple(meeple);
    Pion * pion = this->mapJoueursPions.at(joueur);
    pion->ajouter_meeple(meeple);
}

void Plateau::ajouter_tuile_pioche(Tuile *tuile)
{
    this->pioche.push_back(tuile);
}