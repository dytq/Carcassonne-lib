// LIBRAIRIES
#include <iostream>
#include <list>
#include <map>
#include <tuple>
#include <vector>

#include "BaseDeDonnees.hpp"
#include "Bordure.hpp"
#include "Constantes.hpp"
#include "Joueur.hpp"
#include "Plateau.hpp"
#include "Tuile.hpp"

using namespace std;

// FONCTIONS
void afficher_elements(vector<Element *> list_element) {
	int i = 0;
	for (Element *element : list_element) {
		if (!Plateau::verifier_si_meeple_voisin(element, element->get_type_element())) {
			cout << "Element n°" << i << ": " << element->get_type_element() << endl;
		} else {
			cout << "Element n°" << i << " (impossible à placer): " << element->get_type_element() << endl;
		}
		i++;
	}
}

void afficher_plateau(Plateau *plateau) {
	for (int i = 0; i < 144; i++) {
		for (int j = 0; j < 144; j++) {
			if (plateau->get_tuile_grille(i, j) != nullptr) {
				Tuile *tuile = plateau->get_tuile_grille(i, j);

				cout << "coords (" << i << "," << j << ") " << tuile->get_id() << endl;
				if (tuile->get_id() != -1) {
					cout << "Elements de la tuile: " << endl;
					for (auto element : tuile->getElements()) {
						cout << " " << element->get_type_element();

						Meeple *meeple = element->get_meeple();
						if (meeple != nullptr) {
							cout << " (meeple " << meeple->get_joueur()->get_couleur() << ")";
						}
					}
					cout << endl;
				}
			}
		}
	}
}

void afficher_liste_tuiles_emplacements_libres(vector<array<int, 3>> liste_tuiles_emplacements_libres) {
	for (long unsigned int i = 0; i < liste_tuiles_emplacements_libres.size(); i++) {
		cout << "Emplacement n°" << i << " :\n"
			 << "Abscisse :\t" << liste_tuiles_emplacements_libres.at(i).at(0) << "\tOrdonnée :\t" << liste_tuiles_emplacements_libres.at(i).at(1) << "\tOrientation :\t" << (liste_tuiles_emplacements_libres.at(i).at(2) * 90) << "°" << endl;
	}
}

// MAIN
int main() {
	/* Initialisation du plateau */
	Plateau *plateau = BaseDeDonnees::generer_plateau_vanilla(); // Génération du plateau depuis la base de données
	plateau->init_plateau(); // Initialisation du plateau en plaçcant la tuile de base

	/* Initialisation des joueurs */
	Joueur *joueur1 = new Joueur(Joueur::HUMAIN, Joueur::JAUNE);
	Joueur *joueur2 = new Joueur(Joueur::ROBOT, Joueur::ROUGE);

	plateau->ajouter_joueur(joueur1, new Pion());
	plateau->ajouter_joueur(joueur2, new Pion());

	int token = 0; // Token pour savoir qui joue

	Joueur *joueur; // Joueur qui joue

	/* Boucle principale */
	while (!plateau->pioche_est_vide()) {
		/* Détermine le joueur qui joue */
		if (token == 0) {
			joueur = joueur1;
		} else {
			joueur = joueur2;
		}

		/* Afficher le plateau */
		afficher_plateau(plateau);

		/* Piocher une tuile */
		Tuile *tuile_pioche = plateau->piocher_tuile_aleat(); // Pioche une tuile au hasard et l'enlève de la pioche
		cout << "Tuile piochée n°" << tuile_pioche->get_id() << endl;

		/* Chercher les emplacements libres et les afficher */
		plateau->calcul_emplacements_libres(tuile_pioche); // Détermine tous les emplacements possibles sur le plateau
		vector<array<int, 3>> liste_tuiles_emplacements_libres = plateau->get_liste_tuiles_emplacements_libres();
		cout << "Choisir l'index d'un emplacement de 0 à " << liste_tuiles_emplacements_libres.size() << endl;
		afficher_liste_tuiles_emplacements_libres(liste_tuiles_emplacements_libres);

		/* choisir un emplacement libre et poser la tuile*/
		int indice_emplacement_libre;
		cin >> indice_emplacement_libre;
		plateau->poser_tuile(tuile_pioche, liste_tuiles_emplacements_libres[indice_emplacement_libre]);

		std::pair<int, int> coordonnee_tuile_pioche = { liste_tuiles_emplacements_libres[indice_emplacement_libre][0], liste_tuiles_emplacements_libres[indice_emplacement_libre][1] };

		/* Placer un meeple sur la tuile pioché */
		if (plateau->stack_meeple_vide(joueur)) // on regarde si le joueur à bien assez de tuile
		{
			cout << "Joueur" << token + 1 << "veut-il poser pions ?(oui/non)" << endl; // le joueur n'est pas obligé de poser un meeple
			string poser_pion;
			cin >> poser_pion;

			if (!poser_pion.compare("oui")) {
				cout << "Choisir emplacement" << endl;

				vector<Element *> list_element = tuile_pioche->getElements();
				afficher_elements(list_element);
				int indice_element;
				cin >> indice_element;
				plateau->poser_meeple(joueur, list_element[indice_element], coordonnee_tuile_pioche); // Permet au joueur de placer un pion sur la tuile
			}
		}

		/* Compter les points de tous les joueurs */
		plateau->evaluer_meeple(STATUS_EN_COURS);

		/* Joueur suivant */
		token = 1 - token;
	}

	/* Compter les derniers points de fin de partie */
	plateau->evaluer_meeple(STATUS_FINAL);
	return 0;
}
