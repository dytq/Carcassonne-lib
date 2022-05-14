// LIBRAIRIES
#include "Meeple.hpp"

// FONCTIONS
/**
 * @title: Classe virutelle comptage des points
 *
 * @description: Permet de compter les points obtenu par un Meeple.
 * Les Meeples sont de différents type et applique des algos spécifique, par exemple pour l'évaluation.
 *
 * @param status_du_jeu permet en outre de savoir quelle poids prendre lors de l'évalution des points.
 * @param mapJoueurListMeeple Permet d'associer un joueur à une liste de meeple pour connaître les nombre de meeple rencontré et a qui il appartient
 * @param le score
 *  */
bool Meeple::compter_points(int status_du_jeu, std::map<Joueur *, std::list<Meeple*>> * mapJoueurListeMeeple, int * score)
{
	Logging::log(Logging::DEBUG, "comptage de points depuis un meeple non définie");
	return false;
}

/**
 * @title: Récupérer le noeud sur lequel le Meeple se situe.
 *
 * @return noeud le noeud souhaité.
 * */
Noeud * Meeple::get_noeud() {
    return this->noeud;
}

/**
 * @tile: Récupère le joueur auxquelle appartient le Meeple.
 *
 * @return joueur
 * */
Joueur * Meeple::get_joueur() {
    return this->joueur;
}

Meeple::~Meeple() 
{

}
