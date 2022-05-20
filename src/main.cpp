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

void afficher_plateau(Plateau plateau) 
{
    
	for (int i = 0; i < 144; i++) 
    {
		for (int j = 0; j < 144; j++) 
        {
            
			if (plateau.get_tuile_grille(i, j) != nullptr) 
            {
				Tuile *tuile = plateau.get_tuile_grille(i, j);

				cout << "coords (" << i << "," << j << ") " << tuile->get_id() << endl;
				if (tuile->get_id() != -1)
                {
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
    plateau.init_plateau();

	/* Initialisation du plateau */
	//Plateau plateau;   // Génération du plateau depuis la base de données
	//plateau.init_plateau(BaseDeDonnees::generer_plateau_vanilla()); // Initialisation du plateau en plaçcant la tuile de base

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
	//while (!plateau->pioche_est_vide()) {
    plateau.add_child();
	/*
    cout << "-----------" << endl;
    plateau.set_at_back_child();
    afficher_plateau(plateau);
    cout << "-----------" << endl;
    */
    for(int j = 0; j < 2; j++) {
        Joueur * joueur_courant = list_joueur[i%2];

		/* Afficher le plateau */
		afficher_plateau(plateau);

        /* Piocher une tuile */
        Tuile *tuile_pioche = plateau.piocher_tuile_aleat(); // Pioche une tuile au hasard et l'enlève de la pioche
        cout << "Tuile piochée n°" << tuile_pioche->get_id() << endl;

        /* Mettre à jour IA */
        Robot * robot = dynamic_cast<Robot *>(joueur_courant);
        if(robot != nullptr)
        {
            robot->update_ia(plateau, tuile_pioche);
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
        if (false) // on regarde si le joueur_courant à bien assez de tuile
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
        /*
        if(j < 3)
        {
            afficher_plateau(plateau);
            p1 = new Plateau(*plateau);
            Tuile * t3 = p1->get_tuile_grille(71, 71);
            cout << "tuile :" << t3->get_id() << endl;
            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j < 3; j++)
                {   
                    if(t3->getBordure(i) == nullptr) 
                    {
                        cout << "bordure vide" << endl;
                    }
                    else 
                    {
                        if(t3->getBordure(i)->get_bordure_fils(j) == nullptr) 
                        {
                            Logging::log(Logging::DEBUG,"Error pas de fils voisins");
                        }
                        else 
                        {
                        int nbr_voisin = t3->getBordure(i)->get_bordure_fils(j)->get_nbr_voisins();
                        cout << "nbr voisin" << i << "," << j << "=" << nbr_voisin << endl;
                        for(int k = 0; k < nbr_voisin; k++)
                        {

                            Noeud * noeud  = t3->getBordure(i)->get_bordure_fils(j)->get_voisin(k);
                            cout << "noeud " << noeud << endl;
                        }
                        }
                    }
                }
            }
        }
        */
        
		/* Compter les points de tous les joueurs */
		plateau.evaluer_meeple(STATUS_EN_COURS); 
        i = i + 1; // joueur suivant
    }
    
    afficher_plateau(plateau);
	cout << "-----------" << endl;
    plateau.set_at_back_child();
    afficher_plateau(plateau);
    cout << "-----------" << endl;
    cout << "nbr children: " << plateau.nbr_children() << endl;
    /* free data */
    //delete plateau;
	return 0;
}
