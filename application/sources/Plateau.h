#ifndef PLATEAU_H
#define PLATEAU_H

#include <list>
#include <array>
#include <map>
#include <vector>
#include <string>

#include "Joueur.h"
#include "Carte.h"

class Plateau {

    private:
        std::list<Carte *> pioche; // la pioche
        std::list<Joueur *> list_joueur; // liste des joueurs
        std::map<Carte *, std::list<Bordure *>> map_emplacement_possible; // stock les emplacements libre
        Carte * carte_depart; // case de depart (graphe connexe)

    public:
        Plateau();
        void charger_donnee(std::string path);
        void init_plateau();
        void ajouter_joueur(Joueur * joueur);

        Joueur * get_joueur();
        std::list<Carte*> get_pioche();
        std::list<Joueur * > get_joueur_liste();
        std::vector<Carte *> get_list_carte_emplacement_libre();
        std::vector<std::list<Bordure* >> get_orientation_possible(Carte * carte);

        Carte * piocher_carte();
        void calcul_emplacement_libre(Carte * carte);
        void poser_carte(Carte * emplacement, Carte * carte, std::list<Bordure *> bordure);
        void compter_points(Joueur * joueur);
        Joueur * joueur_suivant();
        void compter_points_restant(Joueur * joueur);

        ~Plateau() {}
};

#endif // PLATEAU_H
