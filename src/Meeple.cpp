// LIBRAIRIES
#include "Meeple.hpp"

// FONCTIONS
/**
 * Classe virutelle comptage des points
 *
 * Permet de compter les points obtenu par un Meeple. Les Meeples sont de différents type et applique des algos spécifique
 *
 * @param status_du_jeu permet en outre de savoir quelle poids prendre lors de l'évalution des points.
 * @param mapJoueurListMeeple Permet d'associer un joueur à une liste de meeple pour connaître les nombre de meeple rencontré et a qui il appartient
 * @param le score
 *  */
bool Meeple::compter_points(int status_du_jeu, std::map<Joueur *, std::list<Meeple*>> mapJoueurListeMeeple, int * score)
{
    #ifndef LOG
	Logging::log(Logging::DEBUG, "comptage de points depuis un meeple non définie");
	#endif // LOG
	return false;
}