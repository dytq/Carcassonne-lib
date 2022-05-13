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
 * Gestion logique d'un plateau de jeu.
 * */
class Plateau
{
    private:
        // VARIABLES
        std::array<std::array<Tuile *, 144>, 144> grille; // grille du jeu
        
        std::vector<Tuile *> pioche; // la pioche
        std::vector<std::array<int, 3>> liste_tuiles_emplacements_libres; // liste des emplacements libres {abscisse, ordonnée, orientation}
        std::vector<Element *> element_libre; // liste des éléments libre

        std::map<Joueur *, Pion *> mapJoueursPions; // associe un sac de pions à un Joueur
        std::map<Tuile *, std::pair<int, int>> tuiles_candidates; // liste des tuiles candidates

        // METHODES
        std::list<Joueur *> rechercher_Joueur_plus_de_Pions(std::map<Joueur *, std::list<Meeple *>>mapJoueurListeMeeple); // recherche concurencielle
        void desindexer_Meeple_dans_la_map(std::map<Joueur *, std::list<Meeple *>> mapJoueurListeMeeple); // met à jour les sacs de pions

    public:
        // CONSTRUCTEUR
        Plateau();

        // DESTRUCTEUR
        ~Plateau();

        // METHODES
        // GETTER 
        Tuile * get_tuile_grille(int x, int y); 
        int     get_nbr_meeple(Joueur * joueur);
        Pion *  get_pion_joueur(Joueur * joueur);
        
        const std::vector<Element *>    get_element_libre(); 
        std::vector<std::array<int, 3>> get_liste_tuiles_emplacements_libres(); 

        const std::map<Tuile *,std::pair<int,int>>        get_tuiles_candidates();
        const std::array<std::array<Tuile *, 144>, 144> * get_grille();

        // SETTER
        
        // FONCTIONS STATIC
        static bool verifier_si_meeple_voisin(Noeud * noeud, Noeud::type_element type_element);  

        // FONTIONS 
        void init_plateau(); 
        
        void ajouter_joueur(Joueur * joueur, Pion * pion); 
        void ajouter_tuile_pioche(Tuile * tuile); 
        
        void calculer_element_libre(Tuile * tuile); 
        void calcul_emplacements_libres(Tuile *tuile); 
        
        void poser_tuile(Tuile *tuile, std::array<int, 3> emplacement); 
        void poser_meeple(Joueur *joueur, Element *element, Meeple * meeple, int indice); 
        void poser_meeple(Joueur *joueur, Element *element, std::pair<int, int> position);

        void evaluer_meeple(int status_du_jeu); 
        
        bool stack_meeple_vide(Joueur *joueur); 
                
        Tuile *piocher_tuile(int indice_pioche); 
        Tuile *piocher_tuile_aleat(); 
        
        bool pioche_est_vide();
};

#endif
