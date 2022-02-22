// LIBRAIRIES
#include <iostream>
#include <list>
#include <tuple>
#include <map>
#include <vector>

#include "Plateau.hpp"
#include "Joueur.hpp"
#include "Bordure.hpp"
#include "Carte.hpp"
#include "Constantes.hpp"

using namespace std;

// FONCTIONS
void afficher_elements(vector<Element *> list_element)
{

}

void afficher_list_emplacement_libre(vector<Carte *> list_emplacement_libre)
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
    plateau.init_plateau();            // Init la carte en posant la première tuile sur le plateau (Tuile de base)

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
            // * Piocher une carte
            Carte * carte_pioche =  plateau.piocher_carte(); // Pioche une carte (recupère l'addresse de la carte)
            cout << "carte pioché : " << carte_pioche << endl;

            // * Chercher les emplacements libre
            plateau.calcul_emplacement_libre(carte_pioche); // Détermine tous les emplacements libre sur le plateau
            vector<Carte * > list_emplacement_libre = plateau.get_list_carte_emplacement_libre();

            // * Afficher les emplacement libre
            cout << "choisir un emplacement: " << endl;
            afficher_list_emplacement_libre(list_emplacement_libre);

            // * Choisir une case parmi celles proposées
            int index;
            cin >> index; // choisir l'indice de la liste


            Carte * carte_emplacement = list_emplacement_libre[index];

            // * Afficher les orientations possibles
            vector<list<Bordure*>> orientation_possible = plateau.get_orientation_possible(carte_emplacement);
            cout << "choisir orientation" << endl;

            // #doit etre ajouté# : si le joueur veut revenir sur sa decision

            // * Choisir une orientation
            afficher_list_orientation_possible(orientation_possible);
            cin >> index;

            // * Poser la carte sur l'empacement
            plateau.poser_carte(carte_pioche, carte_emplacement, orientation_possible[index]); // Permet de remplacer l'addresse de l'emplacement libre par la carte pioché (établir les connexions avec les voisins et voisins avec la carte)

            // * Poser un pion ?
            if(plateau.stack_meeple_vide(joueur))
            {
                cout << "poser pions ?" << endl;
                bool poser_pion = true;
                cin >> poser_pion;

                if(poser_pion == true)
                {
                    cout << "choisir emplacement" << endl;
                    vector<Element *> list_element = carte_pioche->get_element(carte_pioche);
                    afficher_elements(list_element);
                    cin >> index;
                    plateau.poser_meeple(joueur, list_element[index], carte_pioche); // Permet au joueur de placer un pion sur la carte
                }
            }

            // * compter les points
            plateau.evaluer_meeple(STATUS_EN_COURS); // Compte les points totalisées par les meaples mis en jeu si il y a lieu
            joueur = plateau.joueur_suivant(); // Passe au joueur suivant
        }

        else
        {
            fin_de_jeu = true; // Tant qu'on n'a plus de carte
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