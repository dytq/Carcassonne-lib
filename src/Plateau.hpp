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
#include "Element.hpp"
#include "Noeud.hpp"

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
        std::array<std::array<Tuile *, 144>, 144> grille;
        std::vector<Tuile *> pioche; // la pioche
        std::vector<std::array<int, 3>> liste_tuiles_emplacements_libres; // liste des emplacements libres {abscisse, ordonnée, orientation}
        std::map<Joueur *, Pion *> mapJoueursPions; // associe une pile de pions à un Joueur
        std::map<Tuile *, std::pair<int, int>> tuiles_candidates; // liste des tuiles candidates
        std::vector<Element *> element_libre;

        // METHODES
        std::list<Joueur *> rechercher_Joueur_plus_de_Pions(std::map<Joueur *, std::list<Meeple *>>mapJoueurListeMeeple);
        void desindexer_Meeple_dans_la_map(std::map<Joueur *, std::list<Meeple *>> mapJoueurListeMeeple);

    public:
        // CONSTRUCTEUR
        Plateau();

        // DESTRUCTEUR
        ~Plateau();

        // METHODES
        void init_plateau();
        void ajouter_joueur(Joueur * joueur, Pion * pion);
        void ajouter_tuile_pioche(Tuile * tuile);
        std::vector<Tuile *> get_pioche();
        std::vector<std::array<int, 3>> get_liste_tuiles_emplacements_libres();
        std::map<Tuile *,std::pair<int,int>> get_tuiles_candidates();

        void calculer_element_libre(Tuile * tuile);

        int get_nbr_meeple(Joueur * joueur);

        Tuile *get_tuile_grille(int x, int y);
        const std::array<std::array<Tuile *, 144>, 144> * get_grille();

        Tuile *piocher_tuile(int index);
        Tuile *piocher_tuile_aleat();
        void calcul_emplacements_libres(Tuile *tuile);
        void poser_tuile(Tuile *tuile, std::array<int, 3> emplacement);
        void compter_points(Joueur *joueur);

        void evaluer_meeple(int status_du_jeu); // évaluation des scores
        bool stack_meeple_vide(Joueur *joueur);
        void poser_meeple(Joueur *joueur, Element *element, Meeple * meeple, int indice);
        static bool verifier_si_meeple_voisin(Noeud * noeud, Noeud::type_element type_element); 

        const std::vector<Element *> get_element_libre();

        Pion * get_pion_joueur(Joueur * joueur);

        bool pioche_est_vide();
};  

#endif
