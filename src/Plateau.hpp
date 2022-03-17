// DIRECTIVES
#ifndef PLATEAU_HPP
#define PLATEAU_HPP

// LIBRAIRIES
#include <list>
#include <array>
#include <map>
#include <vector>
#include <string>

#include "Bordure.hpp"
#include "Tuile.hpp"
#include "Joueur.hpp"
#include "Pion.hpp"
#include "Constantes.hpp"
#include "Logging.hpp"

// CLASSE
/**
 * Classe Plateau
 *
 * Prends en charge la gestion logique d'un plateau de jeu.
 * */
class Plateau
{
    private:
        // VARIABLES
        std::Tuile *grille[NBR_TUILES * 2][NBR_TUILES * 2]; // grille représentant le plateau
        std::vector<Tuile *> pioche; // la pioche
        std::list<Joueur *> list_joueur; // liste des joueurs
        std::vector<Tuile *> liste_tuiles_emplacements_libres;
        std::map<Tuile *, std::list<Bordure *>> map_emplacement_possible; // stock les emplacements libre
        std::map<Joueur* , Pion *> mapJoueursPions; // associe une pile de pions à un Joueur

        // METHODES
        Joueur * rechercher_Joueur_plus_de_Pions(std::map<Joueur*, std::list<Meeple *>> mapJoueurListeMeeple);
        void desindexer_Meeple_dans_la_map(std::map<Joueur*, std::list<Meeple *>> mapJoueurListeMeeple);

    public:
        // CONSTRUCTEUR
        Plateau();

        // DESTRUCTEUR
        ~Plateau();

        // METHODES
        void init_plateau();
        void ajouter_joueur(Joueur * joueur, Pion * pion);

        Joueur * get_joueur();
        std::list<Tuile *> get_pioche();
        std::list<Joueur * > get_joueur_liste();
        void clear_liste_tuiles_emplacements_libres();
        std::vector<Tuile *> get_liste_tuiles_emplacements_libres();
        std::vector<std::list<Bordure* >> get_orientation_possible(Tuile * tuile);

        Tuile * piocher_tuile();
        void calcul_emplacement_libre(Tuile * tuile);
        void poser_tuile(Tuile * emplacement, Tuile * tuile, std::list<Bordure *> bordure);
        void compter_points(Joueur * joueur);
        Joueur * joueur_suivant();

        void evaluer_meeple(int status_du_jeu); // évaluation des scores
        bool stack_meeple_vide(Joueur * joueur);
        void poser_meeple(Joueur * joueur, Element * element, Tuile * tuile);
};

#endif