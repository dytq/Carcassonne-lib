#pragma once
// DIRECTIVES
#ifndef PLATEAU_HPP
#define PLATEAU_HPP

// LIBRAIRIES
#include <list>
#include <array>
#include <map>
#include <vector>
#include <string>
#include <iterator>

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

        std::map<Noeud *, std::vector<Noeud*>> noeuds_plateau; // liste de tous les noeuds du plateau
        
        // METHODES
        std::list<Joueur *> rechercher_Joueur_plus_de_Pions(std::map<Joueur *, std::list<Meeple *>>mapJoueurListeMeeple); // recherche concurencielle
        void desindexer_Meeple_dans_la_map(std::map<Joueur *, std::list<Meeple *>> mapJoueurListeMeeple); // met à jour les sacs de pions
        
        void ajouter_tuile_pioche(Tuile * tuile); 

        // Statique variable
        static int current_index_plateau;
        static std::vector<Noeud *> list_noeuds;
        static std::vector<Plateau *> list_plateau;
        static Plateau * current_plateau;
    
    public:     
        // CONSTRUCTEUR
        Plateau(const Plateau & plateau); // clone plateau   
        Plateau();

        // DESTRUCTEUR
        ~Plateau();

        friend class BaseDeDonnees; // allow use this keys


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

        static void init_root(Plateau * plateau_root)
        {
            if(!Plateau::list_plateau.empty())
            {
                Logging::log(Logging::DEBUG, "Plateau déjà initialisé");
                return;
            }
            list_plateau.push_back(plateau_root);
            current_plateau = plateau_root;
            plateau_root->update_noeud();
            current_index_plateau = 0;
        }

        static void add_child()
        {
            if(Plateau::list_plateau.empty())
            {
                Logging::log(Logging::DEBUG, "Plateau non initialisé");
                return;
            }
            Plateau * plateau_child = new Plateau(*current_plateau);
            Plateau::list_plateau.push_back(plateau_child);
        }

        static void add_children(int nbr_child)
        {
            for(int i = 0; i < nbr_child; i++)
            {
                add_child();
            }
        }
        static void set_at_back_child()
        {
            Plateau::current_index_plateau = (int) Plateau::list_plateau.size() - 1;
            Plateau::current_plateau = Plateau::list_plateau[Plateau::current_index_plateau];
            Plateau::list_plateau[Plateau::current_index_plateau]->update_noeud();
        }

        static void remove_back_child()
        {
            Plateau::list_plateau.pop_back();
            Plateau::set_at_back_child();
        }

        static int nbr_children()
        {
            return (int) Plateau::list_plateau.size();
        }
        
        // void static get_child(int nbr); // TODO tree plateau

        // TODO non static function
        static void ajouter_noeuds(Noeud * noeud, Plateau * plateau) 
        {
            plateau->noeuds_plateau.insert({noeud, std::vector<Noeud *> ()}); //insert(noeud, noeuds_voisins);
            list_noeuds.push_back(noeud);
            noeud->set_noeud_plateau(& plateau->noeuds_plateau);
        }

        std::vector<Noeud *> get_list_noeuds()
        {
            return current_plateau->list_noeuds;
        }

        std::map<Noeud*, std::vector<Noeud *>> get_noeud_plateau()
        {
            return current_plateau->noeuds_plateau;
        }

        // FONCTIONS 

        void init_plateau(); 
        
        void ajouter_joueur(Joueur * joueur, Pion * pion); 
        
        void calculer_element_libres(Tuile * tuile); 
        void calcul_emplacements_libres(Tuile *tuile); 
        
        void clear_element_libres();
        void clear_emplacement_libres();

        void poser_tuile(Tuile *tuile, std::array<int, 3> emplacement); 
        void poser_meeple(Joueur *joueur, Element *element, Meeple * meeple, int indice); 
        void poser_meeple(Joueur *joueur, Element *element, std::pair<int, int> position);

        void evaluer_meeple(int status_du_jeu); 
        
        bool stack_meeple_vide(Joueur *joueur); 
                
        Tuile *piocher_tuile(int indice_pioche); 
        Tuile *piocher_tuile_aleat(); 

        // TODO noeud appelle plateau au lieu de plateau update noeud
        void update_noeud();

        bool pioche_est_vide();
};

#endif
