// LIBRAIRIES
#include <cstddef>
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
#include "Humain.hpp"
#include "Robot.hpp"


using namespace std;

// FONCTIONS
void afficher_elements(vector<Element *> list_element) 
{
	int i = 0;
	for (Element *element : list_element) 
    {
		if (!Plateau::verifier_si_meeple_voisin(element, element->get_type_element())) 
        {
			cout << "Element n°" << i << ": " << element->get_type_element() << endl;
		} 
        else 
        {
			cout << "Element n°" << i << " (impossible à placer): " << element->get_type_element() << endl;
		}
		i++;
	}
}

void afficher_plateau(Plateau * plateau) 
{
    
	for (int i = 0; i < 144; i++) 
    {
		for (int j = 0; j < 144; j++) 
        {
            
			if (plateau->get_tuile_grille(i, j) != nullptr) 
            {
				Tuile *tuile = plateau->get_tuile_grille(i, j);

				cout << "coords (" << i << "," << j << ") " << tuile->get_id() << endl;
				if (tuile->get_id() != -1)
                {
                    if(tuile->get_id() < -1 || tuile->get_id() > 72)
                    {
                        Logging::log(Logging::CRITICAL, "tuile ayant un id non alloué, echec du programme");
                        exit(false);
                    }
					cout << "Elements de la tuile: " << endl;
					for (auto element : tuile->getElements()) 
                    {
						cout << " " << element->get_type_element();

						Meeple *meeple = element->get_meeple();
						if (meeple != nullptr) 
                        {
							// cout << " (meeple " << meeple->get_joueur()->get_couleur() << ")";
						}
					}
					cout << endl;
				}
			}
		}
	}
}

void afficher_liste_tuiles_emplacements_libres(vector<array<int, 3>> liste_tuiles_emplacements_libres) {
	for (long unsigned int i = 0; i < liste_tuiles_emplacements_libres.size(); i++) 
    {
		cout << "Emplacement n°" << i << " :\n"
			 << "Abscisse :\t" << liste_tuiles_emplacements_libres.at(i).at(0) << "\tOrdonnée :\t" << liste_tuiles_emplacements_libres.at(i).at(1) << "\tOrientation :\t" << (liste_tuiles_emplacements_libres.at(i).at(2) * 90) << "°" << endl;
	}
}

// MAIN
int main() {
    Plateau plateau;
    plateau.init_root(BaseDeDonnees::generer_plateau_vanilla());
        cout << "size pioche " << plateau.pioche_est_vide() << endl;

    plateau.init_plateau();

	
    /* Initialisation des joueurs */
    vector<Joueur *> list_joueur;
    list_joueur.push_back(new Robot(Robot::ALEAT));
    list_joueur.push_back(new Robot(Robot::ALEAT));

    for(Joueur * joueur : list_joueur)
    {
        plateau.ajouter_joueur(joueur, new Pion());
    }
    
    int i = 0;    
    
    /* Boucle principale */
    
    //while (!plateau.pioche_est_vide()) 
    //{
        for(int j = 0; j < 50; j++) {


        Joueur * joueur_courant = list_joueur[i%2];

		/* Afficher le plateau */
		afficher_plateau(&plateau);

        /* Piocher une tuile */
        //Tuile *tuile_pioche = plateau.piocher_tuile_aleat(); // Pioche une tuile au hasard et l'enlève de la pioche
        Tuile *tuile_pioche = plateau.piocher_tuile(5);
        cout << "Tuile piochée n° / " << tuile_pioche->get_id() << endl;

        /* Mettre à jour IA */
        Robot * robot = dynamic_cast<Robot *>(joueur_courant);
        if(robot != nullptr)
        {
            robot->update_ia(&plateau, tuile_pioche);
        }

        /* Chercher les emplacements libres et les afficher */
        plateau.calcul_emplacements_libres(tuile_pioche); // Détermine tous les emplacements possibles sur le plateau
        vector<array<int, 3>> liste_tuiles_emplacements_libres = plateau.get_liste_tuiles_emplacements_libres();
        cout << "Choisir l'index d'un emplacement de 0 à " << liste_tuiles_emplacements_libres.size() << endl;
        afficher_liste_tuiles_emplacements_libres(liste_tuiles_emplacements_libres);
        
        int indice_emplacement_libre = 0;
        
        cout << indice_emplacement_libre << endl;

        plateau.poser_tuile(tuile_pioche, liste_tuiles_emplacements_libres[indice_emplacement_libre]);
        
        /* Placer un meeple sur la tuile pioché */
        if (joueur_courant->choix_si_poser_meeple()) // on regarde si le joueur_courant à bien assez de tuile
        {
            cout << "Joueur" << i%2 << "veut-il poser pions ?(oui/non)" << endl; // le joueur_courant n'est pas obligé de poser un meeple
            if (joueur_courant->choix_si_poser_meeple()) 
            {
                cout << "Choisir élement" << endl;
                vector<Element *> list_element = tuile_pioche->getElements();
                afficher_elements(list_element);
                std::pair<int, int> coordonnee_tuile_pioche = { liste_tuiles_emplacements_libres[indice_emplacement_libre][0], liste_tuiles_emplacements_libres[indice_emplacement_libre][1] };
                
                int indice_element = joueur_courant->choix_de_element_libre();
                plateau.poser_meeple(joueur_courant, list_element[indice_element], coordonnee_tuile_pioche); // Permet au joueur_courant de placer un pion sur la tuile
            }
        }   

		/* Compter les points de tous les joueurs */
		plateau.evaluer_meeple(STATUS_EN_COURS); 
        i = i + 1; // joueur suivant
    }
    
    /* free data */
	return 0;
}
