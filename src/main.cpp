// LIBRAIRIES
#include <iostream>
#include <list>
#include <tuple>
#include <map>
#include <vector>

#include "Plateau.hpp"
#include "Joueur.hpp"
#include "Bordure.hpp"
#include "Tuile.hpp"
#include "Constantes.hpp"

using namespace std;

// FONCTIONS
void afficher_elements(vector<Element *> list_element)
{

}

void afficher_liste_tuiles_emplacements_libres(vector<Tuile *> liste_tuiles_emplacements_libres)
{

}

void afficher_list_orientation_possible(vector<list<Bordure *>> orientation_possible)
{

}

// MAIN
int main()
{
    // * Initialise le plateau
    Plateau plateau;                   // Instancie le plateau
    plateau.charger_donnee("path");    // Charge les données depuis la bd
    plateau.init_plateau();            // Init la tuile en posant la première tuile sur le plateau (Tuile de base)

    // * Ajout des joueurs
    plateau.ajouter_joueur(new Joueur(Joueur::HUMAIN), new Pion());
    plateau.ajouter_joueur(new Joueur(Joueur::ROBOT), new Pion());

    // * Init le joueur initial
    Joueur * joueur = plateau.get_joueur(); // Récupère le joueur qui doit jouer

    // * Init etat du jeu
    bool fin_de_jeu = false; // Boolean de fin de partie

    // Main loop
    while(!fin_de_jeu)
    {
        if(plateau.get_pioche().size() != 0)
        {
            // * Piocher une tuile
            Tuile * tuile_pioche =  plateau.piocher_tuile(); // Pioche une tuile (recupère l'addresse de la tuile)
            cout << "Tuile piochée : " << tuile_pioche << endl;

            // * Chercher les emplacements libre
            plateau.clear_liste_tuiles_emplacements_libres();
            plateau.calcul_emplacement_libre(tuile_pioche); // Détermine tous les emplacements libre sur le plateau
            vector<Tuile * > liste_tuiles_emplacements_libres = plateau.get_liste_tuiles_emplacements_libres();

            // * Afficher les emplacement libre
            cout << "choisir un emplacement: " << endl;
            afficher_liste_tuiles_emplacements_libres(liste_tuiles_emplacements_libres);

            // * Choisir une case parmi celles proposées
            int index;
            cin >> index; // choisir l'indice de la liste


            Tuile * tuile_emplacement = liste_tuiles_emplacements_libres[index];

            // * Afficher les orientations possibles
            vector<list<Bordure*>> orientation_possible = plateau.get_orientation_possible(tuile_emplacement);
            cout << "choisir orientation" << endl;

            // #doit etre ajouté# : si le joueur veut revenir sur sa decision

            // * Choisir une orientation
            afficher_list_orientation_possible(orientation_possible);
            cin >> index;

            // * Poser la tuile sur l'empacement
            plateau.poser_tuile(tuile_pioche, tuile_emplacement, orientation_possible[index]); // Permet de remplacer l'addresse de l'emplacement libre par la tuile pioché (établir les connexions avec les voisins et voisins avec la tuile)

            // * Poser un pion ?
            if(plateau.stack_meeple_vide(joueur))
            {
                cout << "poser pions ?" << endl;
                bool poser_pion = true;
                cin >> poser_pion;

                if(poser_pion == true)
                {
                    /*
                    cout << "choisir emplacement" << endl;
                    vector<Element *> list_element = tuile_pioche->get_element(tuile_pioche);
                    afficher_elements(list_element);
                    cin >> index;
                    plateau.poser_meeple(joueur, list_element[index], tuile_pioche); // Permet au joueur de placer un pion sur la tuile
                    */
                }
            }

            // * compter les points
            plateau.evaluer_meeple(STATUS_EN_COURS); // Compte les points totalisés par les meaples mis en jeu si il y a lieu
            joueur = plateau.joueur_suivant(); // Passe au joueur suivant
        }

        else
        {
            fin_de_jeu = true; // Si on n'a plus de tuile
        }
    }

    // Compte les derniers points de fin de partie
    list<Joueur *> list_joueur = plateau.get_joueur_liste();
    list<Joueur *>::iterator it;

    plateau.evaluer_meeple(STATUS_FINAL);
    
    for (it = list_joueur.begin(); it != list_joueur.end(); ++it)
    {
        cout << "Joueur " << (*it)->get_nom() << " à obtenu " << (*it)->get_score();
    }

    return 0;
}