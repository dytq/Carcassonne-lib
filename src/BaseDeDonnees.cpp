#include "BaseDeDonnees.hpp"

/**
 * @title : génération d'un plateau de jeu de type vanilla
 *
 * @description : cette fonction permet de générer un plateau de jeu de type vanilla, on initialise tous les tuiles de la pioche. Dans le jeu vanialla, il y a 72 tuiles, certaines tuiles sont en double.
 *
 * @return : le plateau de jeu généré
 */
Plateau * BaseDeDonnees::generer_plateau_vanilla()
{
    int id = 0;
    Plateau * plateau = new Plateau();
    // Tuile 1 (x4)
    {
    for (int nb = 0 ; nb <NOMBRE_TUILES_4 ; nb++)
    {
            std::array<Bordure *, 4> bordure;
            std::vector<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
                bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(0, Noeud::VOID);
            bordure[0]->set_bordure_fils(1, Noeud::VILLE);
            bordure[0]->set_bordure_fils(2, Noeud::VOID);

            bordure[1]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[1]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[1]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[2]->set_bordure_fils(0, Noeud::VOID);
            bordure[2]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(2, Noeud::VOID);

            bordure[3]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[3]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[3]->set_bordure_fils(2, Noeud::PLAINE);

            // init les elements
            std::vector<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE,std::make_pair(0.5, 0.9));
            Element * element2 = new Element(Noeud::ROUTE,std::make_pair(0.5, 0.5));
            Element * element3 = new Element(Noeud::PLAINE,std::make_pair(0.5,0.7));
            Element * element4 = new Element(Noeud::PLAINE,std::make_pair(0.5,0.2));

            // init les voisins
            // bordure:

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));

            element2->set_voisin(bordure[1]->get_bordure_fils(1));
            element2->set_voisin(bordure[3]->get_bordure_fils(1));

            element3->set_voisin(bordure[1]->get_bordure_fils(0));
            element3->set_voisin(bordure[3]->get_bordure_fils(2));

            element4->set_voisin(bordure[1]->get_bordure_fils(2));
            element4->set_voisin(bordure[2]->get_bordure_fils(1));
            element4->set_voisin(bordure[3]->get_bordure_fils(0));

            // Ajout des liens additionels
            element3->set_lien(element1);
           
            // ajoute nullptr vers voisin de la bordure non connecté
            bordure[0]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(2)->set_lien(nullptr);
           
            bordure[1]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[2]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[3]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(2)->set_lien(nullptr);


            // Ajout element dans le vecteur
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);
            elementTuile.push_back(element4);

            // Creation de la carte
            Tuile * tuile = new Tuile(id, 1, bordure, elementTuile);
            
            id ++;
            // AJOUT de la carte dans le pioche
            plateau->ajouter_tuile_pioche(tuile);
        
    }
    }
    // Tuile 2 (x3)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_3 ; nb++)
    {
            std::array<Bordure *, 4> bordure;
            std::vector<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
                bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(0, Noeud::VOID);
            bordure[0]->set_bordure_fils(1, Noeud::VILLE);
            bordure[0]->set_bordure_fils(2, Noeud::VOID);

            bordure[1]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[1]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[1]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[2]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[2]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(0, Noeud::VOID);
            bordure[3]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[3]->set_bordure_fils(2, Noeud::VOID);

            // init les elements
            std::vector<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE, std::make_pair(0.5,0.9));
            Element * element2 = new Element(Noeud::ROUTE, std::make_pair(0.5,0.5));
            Element * element3 = new Element(Noeud::PLAINE, std::make_pair(0.2,0.5));
            Element * element4 = new Element(Noeud::PLAINE, std::make_pair(0.8,0.1));

            // init les voisins

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));

            element2->set_voisin(bordure[1]->get_bordure_fils(1));
            element2->set_voisin(bordure[2]->get_bordure_fils(1));

            element3->set_voisin(bordure[1]->get_bordure_fils(0));
            element3->set_voisin(bordure[2]->get_bordure_fils(2));
            element3->set_voisin(bordure[3]->get_bordure_fils(1));

            element4->set_voisin(bordure[1]->get_bordure_fils(2));
            element4->set_voisin(bordure[2]->get_bordure_fils(0));

            // Ajout des liens additionelles
            element3->set_lien(element1);

            // ajoute nullptr vers voisin de la bordure non connecté
            bordure[0]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(2)->set_lien(nullptr);
           
            bordure[1]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[2]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[3]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(2)->set_lien(nullptr);


            // Ajout element dans le vecteur
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);
            elementTuile.push_back(element4);

            // Creation de la carte
            Tuile * carte = new Tuile(id, 2, bordure, elementTuile);
            id++;

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte);
    }
    }

    // Tuile 3 (x3)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_3 ; nb++){

            std::array<Bordure *, 4> bordure;
            std::vector<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(0, Noeud::VOID);
            bordure[0]->set_bordure_fils(1, Noeud::VILLE);
            bordure[0]->set_bordure_fils(2, Noeud::VOID);

            bordure[1]->set_bordure_fils(0, Noeud::VOID);
            bordure[1]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[1]->set_bordure_fils(2, Noeud::VOID);

            bordure[2]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[2]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[3]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[3]->set_bordure_fils(2, Noeud::PLAINE);

            // init les elements
            std::vector<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE,std::make_pair(0.5,0.9));
            Element * element2 = new Element(Noeud::ROUTE,std::make_pair(0.5,0.5));
            Element * element3 = new Element(Noeud::PLAINE,std::make_pair(0.8,0.5));
            Element * element4 = new Element(Noeud::PLAINE,std::make_pair(0.2,0.2));

            // init les voisins

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));

            element2->set_voisin(bordure[2]->get_bordure_fils(1));
            element2->set_voisin(bordure[3]->get_bordure_fils(1));

            element3->set_voisin(bordure[1]->get_bordure_fils(1));
            element3->set_voisin(bordure[2]->get_bordure_fils(0));
            element3->set_voisin(bordure[3]->get_bordure_fils(2));

            element4->set_voisin(bordure[2]->get_bordure_fils(2));
            element4->set_voisin(bordure[3]->get_bordure_fils(0));

            // Ajout des liens additionelles
            element3->set_lien(element1);

            // ajoute nullptr vers voisin de la bordure non connecté
            bordure[0]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(2)->set_lien(nullptr);
           
            bordure[1]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[2]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[3]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(2)->set_lien(nullptr);

            // Ajout element dans le vector
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);
            elementTuile.push_back(element4);

            // Creation de la carte
            Tuile * carte = new Tuile(id, 3, bordure, elementTuile);
            id++;

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
    }
    }

    // Tuile 4 (x5)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_5 ; nb++){

            std::array<Bordure *, 4> bordure;
            std::vector<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(0, Noeud::VOID);
            bordure[0]->set_bordure_fils(1, Noeud::VILLE);
            bordure[0]->set_bordure_fils(2, Noeud::VOID);

            bordure[1]->set_bordure_fils(0, Noeud::VOID);
            bordure[1]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[1]->set_bordure_fils(2, Noeud::VOID);

            bordure[2]->set_bordure_fils(0, Noeud::VOID);
            bordure[2]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(2, Noeud::VOID);

            bordure[3]->set_bordure_fils(0, Noeud::VOID);
            bordure[3]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[3]->set_bordure_fils(2, Noeud::VOID);

            // init les elements
            std::vector<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE,std::make_pair(0.5,0.9));
            Element * element2 = new Element(Noeud::PLAINE,std::make_pair(0.5,0.5));

            // init les voisins

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));

            element2->set_voisin(bordure[1]->get_bordure_fils(1));
            element2->set_voisin(bordure[2]->get_bordure_fils(1));
            element2->set_voisin(bordure[3]->get_bordure_fils(1));

            // Ajout des liens additionelles
            element2->set_lien(element1);

            // ajoute nullptr vers voisin de la bordure non connecté
            bordure[0]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(2)->set_lien(nullptr);
           
            bordure[1]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[2]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[3]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(2)->set_lien(nullptr);

            // Ajout element dans le vector
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);

            // Creation de la carte
            Tuile * carte = new Tuile(id,4, bordure, elementTuile);
            id++;

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
    }
    }

    // Tuile 5 (x3)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_3 ; nb++){

            std::array<Bordure *, 4> bordure;
            std::vector<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(0, Noeud::VOID);
            bordure[0]->set_bordure_fils(1, Noeud::VILLE);
            bordure[0]->set_bordure_fils(2, Noeud::VOID);

            bordure[1]->set_bordure_fils(0, Noeud::VOID);
            bordure[1]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[1]->set_bordure_fils(2, Noeud::VOID);

            bordure[2]->set_bordure_fils(0, Noeud::VOID);
            bordure[2]->set_bordure_fils(1, Noeud::VILLE);
            bordure[2]->set_bordure_fils(2, Noeud::VOID);

            bordure[3]->set_bordure_fils(0, Noeud::VOID);
            bordure[3]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[3]->set_bordure_fils(2, Noeud::VOID);

            // init les elements
            std::vector<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE,std::make_pair(0.5,0.9));
            Element * element2 = new Element(Noeud::PLAINE,std::make_pair(0.5,0.5));
            Element * element3 = new Element(Noeud::VILLE,std::make_pair(0.5,0.1));

            // init les voisins
            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));

            element2->set_voisin(bordure[1]->get_bordure_fils(1));
            element2->set_voisin(bordure[3]->get_bordure_fils(1));

            element3->set_voisin(bordure[2]->get_bordure_fils(1));

            // Ajout des liens additionelles
            element2->set_lien(element1);
            element2->set_lien(element3);

            // ajoute nullptr vers voisin de la bordure non connecté
            bordure[0]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(2)->set_lien(nullptr);
           
            bordure[1]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[2]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[3]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(2)->set_lien(nullptr);



            // Ajout element dans le vecteur
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);

            // Creation de la carte
            Tuile * carte = new Tuile(id, 5, bordure, elementTuile);
            id++;

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
    }
    }

    // Tuile 6 (x2)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_2 ; nb++){

            std::array<Bordure *, 4> bordure;
            std::vector<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(0, Noeud::VOID);
            bordure[0]->set_bordure_fils(1, Noeud::VILLE);
            bordure[0]->set_bordure_fils(2, Noeud::VOID);

            bordure[1]->set_bordure_fils(0, Noeud::VOID);
            bordure[1]->set_bordure_fils(1, Noeud::VILLE);
            bordure[1]->set_bordure_fils(2, Noeud::VOID);

            bordure[2]->set_bordure_fils(0, Noeud::VOID);
            bordure[2]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(2, Noeud::VOID);

            bordure[3]->set_bordure_fils(0, Noeud::VOID);
            bordure[3]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[3]->set_bordure_fils(2, Noeud::VOID);

            // init les elements
            std::vector<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE,std::make_pair(0.5,0.9));
            Element * element2 = new Element(Noeud::VILLE,std::make_pair(0.5,0.9));
            Element * element3 = new Element(Noeud::PLAINE,std::make_pair(0.5,0.5));

            // init les voisins
            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));

            element2->set_voisin(bordure[1]->get_bordure_fils(1));

            element3->set_voisin(bordure[2]->get_bordure_fils(1));
            element3->set_voisin(bordure[3]->get_bordure_fils(1));

            // Ajout des liens additionelles
            element3->set_lien(element1);
            element3->set_lien(element2);

            // ajoute nullptr vers voisin de la bordure non connecté
            bordure[0]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(2)->set_lien(nullptr);
           
            bordure[1]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[2]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[3]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(2)->set_lien(nullptr);

            // Ajout element dans le vecteur
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);

            // Creation de la carte
            Tuile * carte = new Tuile(id, 6, bordure, elementTuile);
            id++;

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
    }
    }

    // Tuile 7 (x8)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_8 ; nb++){

            std::array<Bordure *, 4> bordure;
            std::vector<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[0]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[0]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[1]->set_bordure_fils(0, Noeud::VOID);
            bordure[1]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[1]->set_bordure_fils(2, Noeud::VOID);

            bordure[2]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[2]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(0, Noeud::VOID);
            bordure[3]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[3]->set_bordure_fils(2, Noeud::VOID);

            // init les elements
            std::vector<Element *> elementTuile;
            Element * element1 = new Element(Noeud::PLAINE,std::make_pair(0.2,0.5));
            Element * element2 = new Element(Noeud::ROUTE,std::make_pair(0.5,0.5));
            Element * element3 = new Element(Noeud::PLAINE,std::make_pair(0.8,0.8));

            // init les voisins
            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(0));
            element1->set_voisin(bordure[3]->get_bordure_fils(1));
            element1->set_voisin(bordure[2]->get_bordure_fils(2));

            element2->set_voisin(bordure[0]->get_bordure_fils(1));
            element2->set_voisin(bordure[2]->get_bordure_fils(1));

            element3->set_voisin(bordure[0]->get_bordure_fils(2));
            element3->set_voisin(bordure[1]->get_bordure_fils(1));
            element3->set_voisin(bordure[2]->get_bordure_fils(0));

            // Ajout des liens additionelles
            // Aucun

            // ajoute nullptr vers voisin de la bordure non connecté
            bordure[0]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(2)->set_lien(nullptr);
           
            bordure[1]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[2]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[3]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(2)->set_lien(nullptr);

            // Ajout element dans le vecteur
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);

            // Creation de la carte
            Tuile * carte = new Tuile(id, 7, bordure, elementTuile);
            id++;

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
    }
    }

    // Tuile 8 (x9)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_9 ; nb++){

            std::array<Bordure *, 4> bordure;
            std::vector<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(0, Noeud::VOID);
            bordure[0]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[0]->set_bordure_fils(2, Noeud::VOID);

            bordure[1]->set_bordure_fils(0, Noeud::VOID);
            bordure[1]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[1]->set_bordure_fils(2, Noeud::VOID);

            bordure[2]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[2]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[3]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[3]->set_bordure_fils(2, Noeud::PLAINE);

            // init les elements
            std::vector<Element *> elementTuile;
            Element * element1 = new Element(Noeud::PLAINE,std::make_pair(0.9,0.9));
            Element * element2 = new Element(Noeud::ROUTE,std::make_pair(0.5,0.5));
            Element * element3 = new Element(Noeud::PLAINE,std::make_pair(0.1,0.1));

            // init les voisins
            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[1]->get_bordure_fils(1));
            element1->set_voisin(bordure[2]->get_bordure_fils(0));
            element1->set_voisin(bordure[3]->get_bordure_fils(2));

            element2->set_voisin(bordure[2]->get_bordure_fils(1));
            element2->set_voisin(bordure[3]->get_bordure_fils(1));

            element3->set_voisin(bordure[2]->get_bordure_fils(2));
            element3->set_voisin(bordure[3]->get_bordure_fils(0));

            // Ajout des liens additionelles
            // Aucun

            // ajoute nullptr vers voisin de la bordure non connecté
            bordure[0]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(2)->set_lien(nullptr);
           
            bordure[1]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[2]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[3]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(2)->set_lien(nullptr);


            // Ajout element dans le vecteur
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);

            // Creation de la carte
            Tuile * carte = new Tuile(id, 8, bordure, elementTuile);
            id++;

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
    }
    }

    // Tuile 9 (x3)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_3 ; nb++){

            std::array<Bordure *, 4> bordure;
            std::vector<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(0, Noeud::VOID);
            bordure[0]->set_bordure_fils(1, Noeud::VILLE);
            bordure[0]->set_bordure_fils(2, Noeud::VOID);

            bordure[1]->set_bordure_fils(0, Noeud::VOID);
            bordure[1]->set_bordure_fils(1, Noeud::VILLE);
            bordure[1]->set_bordure_fils(2, Noeud::VOID);

            bordure[2]->set_bordure_fils(0, Noeud::VOID);
            bordure[2]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(2, Noeud::VOID);

            bordure[3]->set_bordure_fils(0, Noeud::VOID);
            bordure[3]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[3]->set_bordure_fils(2, Noeud::VOID);

            // init les elements
            std::vector<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE,std::make_pair(0.8,0.8));
            Element * element2 = new Element(Noeud::PLAINE,std::make_pair(0.4,0.4));

            // init les voisins
            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[1]->get_bordure_fils(1));

            element2->set_voisin(bordure[2]->get_bordure_fils(1));
            element2->set_voisin(bordure[3]->get_bordure_fils(1));

            // Ajout des liens additionelles
            element2->set_lien(element1);

            // ajoute nullptr vers voisin de la bordure non connecté
            bordure[0]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(2)->set_lien(nullptr);
           
            bordure[1]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[2]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[3]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(2)->set_lien(nullptr);


            // Ajout element dans le vecteur
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);

            // Creation de la carte
            Tuile * carte = new Tuile(id, 9, bordure, elementTuile);
            id++;

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
    }
    }

    // Tuile 10 (x2)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_2 ; nb++){

            std::array<Bordure *, 4> bordure;
            std::vector<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(0, Noeud::VOID);
            bordure[0]->set_bordure_fils(1, Noeud::VILLE_BLASON);
            bordure[0]->set_bordure_fils(2, Noeud::VOID);

            bordure[1]->set_bordure_fils(0, Noeud::VOID);
            bordure[1]->set_bordure_fils(1, Noeud::VILLE_BLASON);
            bordure[1]->set_bordure_fils(2, Noeud::VOID);

            bordure[2]->set_bordure_fils(0, Noeud::VOID);
            bordure[2]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(2, Noeud::VOID);

            bordure[3]->set_bordure_fils(0, Noeud::VOID);
            bordure[3]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[3]->set_bordure_fils(2, Noeud::VOID);

            // init les elements
            std::vector<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE_BLASON,std::make_pair(0.8,0.8));
            Element * element2 = new Element(Noeud::PLAINE,std::make_pair(0.4,0.4));

            // init les voisins
            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[1]->get_bordure_fils(1));

            element2->set_voisin(bordure[2]->get_bordure_fils(1));
            element2->set_voisin(bordure[3]->get_bordure_fils(1));

            // Ajout des liens additionelles
            element2->set_lien(element1);

            // ajoute nullptr vers voisin de la bordure non connecté
            bordure[0]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(2)->set_lien(nullptr);
           
            bordure[1]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[2]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[3]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(2)->set_lien(nullptr);


            // Ajout element dans le vecteur
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);

            // Creation de la carte
            Tuile * carte = new Tuile(id, 10, bordure, elementTuile);
            id++;

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
    }
    }

    // Tuile 11 (x3)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_3 ; nb++){

            std::array<Bordure *, 4> bordure;
            std::vector<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(0, Noeud::VOID);
            bordure[0]->set_bordure_fils(1, Noeud::VILLE);
            bordure[0]->set_bordure_fils(2, Noeud::VOID);

            bordure[1]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[1]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[1]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[2]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[2]->set_bordure_fils(2, Noeud::PLAINE);
            
            bordure[3]->set_bordure_fils(0, Noeud::VOID);
            bordure[3]->set_bordure_fils(1, Noeud::VILLE);
            bordure[3]->set_bordure_fils(2, Noeud::VOID);

            // init les elements
            std::vector<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE,std::make_pair(0.2,0.8));
            Element * element2 = new Element(Noeud::ROUTE,std::make_pair(0.6,0.6));
            Element * element3 = new Element(Noeud::PLAINE,std::make_pair(0.8,0.3));
            Element * element4 = new Element(Noeud::PLAINE,std::make_pair(0.9,0.1));

            // init les voisins
            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[3]->get_bordure_fils(1));

            element2->set_voisin(bordure[1]->get_bordure_fils(1));
            element2->set_voisin(bordure[2]->get_bordure_fils(1));

            element3->set_voisin(bordure[1]->get_bordure_fils(0));
            element3->set_voisin(bordure[2]->get_bordure_fils(2));
        
            element4->set_voisin(bordure[1]->get_bordure_fils(2));
            element4->set_voisin(bordure[2]->get_bordure_fils(0));

            // Ajout des liens additionelles
            element3->set_lien(element1);

            // ajoute nullptr vers voisin de la bordure non connecté
            bordure[0]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(2)->set_lien(nullptr);
           
            bordure[1]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[2]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[3]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(2)->set_lien(nullptr);


            // Ajout element dans le vecteur
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);
            elementTuile.push_back(element4);


            // Creation de la carte
            Tuile * carte = new Tuile(id, 11, bordure, elementTuile);
            id++;

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
    }
    }

    // Tuile 12 (x2)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_2 ; nb++){

            std::array<Bordure *, 4> bordure;
            std::vector<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(0, Noeud::VOID);
            bordure[0]->set_bordure_fils(1, Noeud::VILLE_BLASON);
            bordure[0]->set_bordure_fils(2, Noeud::VOID);

            bordure[1]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[1]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[1]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[2]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[2]->set_bordure_fils(2, Noeud::PLAINE);
            
            bordure[3]->set_bordure_fils(0, Noeud::VOID);
            bordure[3]->set_bordure_fils(1, Noeud::VILLE_BLASON);
            bordure[3]->set_bordure_fils(2, Noeud::VOID);

            // init les elements
            std::vector<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE_BLASON,std::make_pair(0.2,0.8));
            Element * element2 = new Element(Noeud::ROUTE,std::make_pair(0.6,0.6));
            Element * element3 = new Element(Noeud::PLAINE,std::make_pair(0.8,0.3));
            Element * element4 = new Element(Noeud::PLAINE,std::make_pair(0.9,0.1));

            // init les voisins
            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[3]->get_bordure_fils(1));

            element2->set_voisin(bordure[1]->get_bordure_fils(1));
            element2->set_voisin(bordure[2]->get_bordure_fils(1));

            element3->set_voisin(bordure[1]->get_bordure_fils(0));
            element3->set_voisin(bordure[2]->get_bordure_fils(2));
            
            element4->set_voisin(bordure[1]->get_bordure_fils(2));
            element4->set_voisin(bordure[2]->get_bordure_fils(0));
            // Ajout des liens additionelles
            element3->set_lien(element1);

            // ajoute nullptr vers voisin de la bordure non connecté
            bordure[0]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(2)->set_lien(nullptr);
           
            bordure[1]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[2]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[3]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(2)->set_lien(nullptr);


            // Ajout element dans le vecteur
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);
            elementTuile.push_back(element4);

            // Creation de la carte
            Tuile * carte = new Tuile(id, 12, bordure, elementTuile);
            id++;

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
    }
    }

    // Tuile 13 (x1)
    {

            std::array<Bordure *, 4> bordure;
            std::vector<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
                bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(0, Noeud::VOID);
            bordure[0]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[0]->set_bordure_fils(2, Noeud::VOID);

            bordure[1]->set_bordure_fils(0, Noeud::VOID);
            bordure[1]->set_bordure_fils(1, Noeud::VILLE);
            bordure[1]->set_bordure_fils(2, Noeud::VOID);

            bordure[2]->set_bordure_fils(0, Noeud::VOID);
            bordure[2]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(2, Noeud::VOID);
            
            bordure[3]->set_bordure_fils(0, Noeud::VOID);
            bordure[3]->set_bordure_fils(1, Noeud::VILLE);
            bordure[3]->set_bordure_fils(2, Noeud::VOID);

            // init les elements
            std::vector<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE,std::make_pair(0.5,0.5));
            Element * element2 = new Element(Noeud::PLAINE,std::make_pair(0.5,0.9));
            Element * element3 = new Element(Noeud::PLAINE,std::make_pair(0.5,0.1));

            // init les voisins
            // element:
            element1->set_voisin(bordure[1]->get_bordure_fils(1));
            element1->set_voisin(bordure[3]->get_bordure_fils(1));

            element2->set_voisin(bordure[0]->get_bordure_fils(1));

            element3->set_voisin(bordure[2]->get_bordure_fils(1));

            // Ajout des liens additionelles
            element2->set_lien(element1);
            element3->set_lien(element1);

            // ajoute nullptr vers voisin de la bordure non connecté
            bordure[0]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(2)->set_lien(nullptr);
           
            bordure[1]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[2]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[3]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(2)->set_lien(nullptr);

           // Ajout element dans le vector
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);

            // Creation de la carte
            Tuile * carte = new Tuile(id, 13, bordure, elementTuile);
            id++;

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
    }

    // Tuile 14 (x2)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_2 ; nb++){

            std::array<Bordure *, 4> bordure;
            std::vector<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(0, Noeud::VOID);
            bordure[0]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[0]->set_bordure_fils(2, Noeud::VOID);

            bordure[1]->set_bordure_fils(0, Noeud::VOID);
            bordure[1]->set_bordure_fils(1, Noeud::VILLE_BLASON);
            bordure[1]->set_bordure_fils(2, Noeud::VOID);

            bordure[2]->set_bordure_fils(0, Noeud::VOID);
            bordure[2]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(2, Noeud::VOID);

            bordure[3]->set_bordure_fils(0, Noeud::VOID);
            bordure[3]->set_bordure_fils(1, Noeud::VILLE_BLASON);
            bordure[3]->set_bordure_fils(2, Noeud::VOID);

            // init les elements
            std::vector<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE_BLASON,std::make_pair(0.5,0.5));
            Element * element2 = new Element(Noeud::PLAINE,std::make_pair(0.5,0.9));
            Element * element3 = new Element(Noeud::PLAINE,std::make_pair(0.5,0.1));

            // init les voisins
            // element:
            element1->set_voisin(bordure[1]->get_bordure_fils(1));
            element1->set_voisin(bordure[3]->get_bordure_fils(1));

            element2->set_voisin(bordure[0]->get_bordure_fils(1));

            element3->set_voisin(bordure[2]->get_bordure_fils(1));

            // Ajout des liens additionelles
            element2->set_lien(element1);
            element3->set_lien(element1);

            // ajoute nullptr vers voisin de la bordure non connecté
            bordure[0]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(2)->set_lien(nullptr);
           
            bordure[1]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[2]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[3]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(2)->set_lien(nullptr);


            // Ajout element dans le vecteur
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);

            // Creation de la carte
            Tuile * carte = new Tuile(id, 14, bordure, elementTuile);
            id++;

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
    }
    }

    // Tuile 15 (x3)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_3 ; nb++){

            std::array<Bordure *, 4> bordure;
            std::vector<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(0, Noeud::VOID);
            bordure[0]->set_bordure_fils(1, Noeud::VILLE);
            bordure[0]->set_bordure_fils(2, Noeud::VOID);

            bordure[1]->set_bordure_fils(0, Noeud::VOID);
            bordure[1]->set_bordure_fils(1, Noeud::VILLE);
            bordure[1]->set_bordure_fils(2, Noeud::VOID);

            bordure[2]->set_bordure_fils(0, Noeud::VOID);
            bordure[2]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(2, Noeud::VOID);

            bordure[3]->set_bordure_fils(0, Noeud::VOID);
            bordure[3]->set_bordure_fils(1, Noeud::VILLE);
            bordure[3]->set_bordure_fils(2, Noeud::VOID);

            // init les elements
            std::vector<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE,std::make_pair(0.5,0.5));
            Element * element2 = new Element(Noeud::PLAINE,std::make_pair(0.5,0.1));

            // init les voisins
            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[1]->get_bordure_fils(1));
            element1->set_voisin(bordure[3]->get_bordure_fils(1));

            element2->set_voisin(bordure[2]->get_bordure_fils(1));

            // Ajout des liens additionelles
            element2->set_lien(element1);

            // ajoute nullptr vers voisin de la bordure non connecté
            bordure[0]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(2)->set_lien(nullptr);
           
            bordure[1]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[2]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[3]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(2)->set_lien(nullptr);


            // Ajout element dans le vecteur
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);

            // Creation de la carte
            Tuile * carte = new Tuile(id, 15, bordure, elementTuile);
            id++;

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
    }
    }

    // Tuile 16 (x1)
    {
            std::array<Bordure *, 4> bordure;
            std::vector<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
                bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(0, Noeud::VOID);
            bordure[0]->set_bordure_fils(1, Noeud::VILLE_BLASON);
            bordure[0]->set_bordure_fils(2, Noeud::VOID);

            bordure[1]->set_bordure_fils(0, Noeud::VOID);
            bordure[1]->set_bordure_fils(1, Noeud::VILLE_BLASON);
            bordure[1]->set_bordure_fils(2, Noeud::VOID);

            bordure[2]->set_bordure_fils(0, Noeud::VOID);
            bordure[2]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(2, Noeud::VOID);

            bordure[3]->set_bordure_fils(0, Noeud::VOID);
            bordure[3]->set_bordure_fils(1, Noeud::VILLE_BLASON);
            bordure[3]->set_bordure_fils(2, Noeud::VOID);

            // init les elements
            std::vector<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE_BLASON,std::make_pair(0.5,0.5));
            Element * element2 = new Element(Noeud::PLAINE,std::make_pair(0.5,0.1));

            // init les voisins
            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[1]->get_bordure_fils(1));
            element1->set_voisin(bordure[3]->get_bordure_fils(1));

            element2->set_voisin(bordure[2]->get_bordure_fils(1));

            // Ajout des liens additionelles
            element2->set_lien(element1);

            // ajoute nullptr vers voisin de la bordure non connecté
            bordure[0]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(2)->set_lien(nullptr);
           
            bordure[1]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[2]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[3]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(2)->set_lien(nullptr);

            // Ajout element dans le vector
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);

            // Creation de la carte
            Tuile * carte = new Tuile(id, 16, bordure, elementTuile);
            id++;

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
    }

    // Tuile 17 (x1)
    {
            std::array<Bordure *, 4> bordure;
            std::vector<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
                bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(0, Noeud::VOID);
            bordure[0]->set_bordure_fils(1, Noeud::VILLE_BLASON);
            bordure[0]->set_bordure_fils(2, Noeud::VOID);

            bordure[1]->set_bordure_fils(0, Noeud::VOID);
            bordure[1]->set_bordure_fils(1, Noeud::VILLE_BLASON);
            bordure[1]->set_bordure_fils(2, Noeud::VOID);

            bordure[2]->set_bordure_fils(0, Noeud::VOID);
            bordure[2]->set_bordure_fils(1, Noeud::VILLE_BLASON);
            bordure[2]->set_bordure_fils(2, Noeud::VOID);

            bordure[3]->set_bordure_fils(0, Noeud::VOID);
            bordure[3]->set_bordure_fils(1, Noeud::VILLE_BLASON);
            bordure[3]->set_bordure_fils(2, Noeud::VOID);

            // init les elements
            std::vector<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE_BLASON,std::make_pair(0.5,0.5));

            // init les voisins
            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[1]->get_bordure_fils(1));
            element1->set_voisin(bordure[2]->get_bordure_fils(1));
            element1->set_voisin(bordure[3]->get_bordure_fils(1));

            // Ajout des liens additionelles
                // Aucun

            // ajoute nullptr vers voisin de la bordure non connecté
            bordure[0]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(2)->set_lien(nullptr);
           
            bordure[1]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[2]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[3]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(2)->set_lien(nullptr);

            // Ajout element dans le vecteur
            elementTuile.push_back(element1);

            // Creation de la carte
            Tuile * carte = new Tuile(id, 17, bordure, elementTuile);
            id++;

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
    }

    // Tuile 18 (x1)
    {

            std::array<Bordure *, 4> bordure;
            std::vector<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
                bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(0, Noeud::VOID);
            bordure[0]->set_bordure_fils(1, Noeud::VILLE);
            bordure[0]->set_bordure_fils(2, Noeud::VOID);

            bordure[1]->set_bordure_fils(0, Noeud::VOID);
            bordure[1]->set_bordure_fils(1, Noeud::VILLE);
            bordure[1]->set_bordure_fils(2, Noeud::VOID);

            bordure[2]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[2]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(0, Noeud::VOID);
            bordure[3]->set_bordure_fils(1, Noeud::VILLE);
            bordure[3]->set_bordure_fils(2, Noeud::VOID);

            // init les elements
            std::vector<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE,std::make_pair(0.5,0.5));
            Element * element2 = new Element(Noeud::ROUTE,std::make_pair(0.5,0.1));
            Element * element3 = new Element(Noeud::PLAINE,std::make_pair(0.6,0.1));
            Element * element4 = new Element(Noeud::PLAINE,std::make_pair(0.4,0.1));

            // init les voisins
            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[1]->get_bordure_fils(1));
            element1->set_voisin(bordure[3]->get_bordure_fils(1));

            element2->set_voisin(bordure[2]->get_bordure_fils(1));

            element3->set_voisin(bordure[2]->get_bordure_fils(0));

            element4->set_voisin(bordure[2]->get_bordure_fils(2));

            // Ajout des liens additionelles
            element3->set_lien(element1);
            element4->set_lien(element1);

            // ajoute nullptr vers voisin de la bordure non connecté
            bordure[0]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(2)->set_lien(nullptr);
           
            bordure[1]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[2]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[3]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(2)->set_lien(nullptr);

           // Ajout element dans le vecteur
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);
            elementTuile.push_back(element4);

            // Creation de la carte
            Tuile * carte = new Tuile(id, 18, bordure, elementTuile);
            id++;

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
    }

    // Tuile 19 (x2)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_2 ; nb++){

            std::array<Bordure *, 4> bordure;
            std::vector<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(0, Noeud::VOID);
            bordure[0]->set_bordure_fils(1, Noeud::VILLE_BLASON);
            bordure[0]->set_bordure_fils(2, Noeud::VOID);

            bordure[1]->set_bordure_fils(0, Noeud::VOID);
            bordure[1]->set_bordure_fils(1, Noeud::VILLE_BLASON);
            bordure[1]->set_bordure_fils(2, Noeud::VOID);

            bordure[2]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[2]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(0, Noeud::VOID);
            bordure[3]->set_bordure_fils(1, Noeud::VILLE_BLASON);
            bordure[3]->set_bordure_fils(2, Noeud::VOID);

            // init les elements
            std::vector<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE_BLASON,std::make_pair(0.5,0.5));
            Element * element2 = new Element(Noeud::ROUTE,std::make_pair(0.5,0.1));
            Element * element3 = new Element(Noeud::PLAINE,std::make_pair(0.6,0.1));
            Element * element4 = new Element(Noeud::PLAINE,std::make_pair(0.4,0.1));

            // init les voisins
            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[1]->get_bordure_fils(1));
            element1->set_voisin(bordure[3]->get_bordure_fils(1));

            element2->set_voisin(bordure[2]->get_bordure_fils(1));

            element3->set_voisin(bordure[2]->get_bordure_fils(0));

            element4->set_voisin(bordure[2]->get_bordure_fils(2));

            // Ajout des liens additionelles
            element3->set_lien(element1);
            element4->set_lien(element1);

            // ajoute nullptr vers voisin de la bordure non connecté
            bordure[0]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(2)->set_lien(nullptr);
           
            bordure[1]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[2]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[3]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(2)->set_lien(nullptr);


            // Ajout element dans le vecteur
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);
            elementTuile.push_back(element4);

            // Creation de la carte
            Tuile * carte = new Tuile(id, 19, bordure, elementTuile);
            id++;

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
    }
    }

    // Tuile 20 (x4)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_4 ; nb++){

            std::array<Bordure *, 4> bordure;
            std::vector<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
                bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(0, Noeud::VOID);
            bordure[0]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[0]->set_bordure_fils(2, Noeud::VOID);

            bordure[1]->set_bordure_fils(0, Noeud::VOID);
            bordure[1]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[1]->set_bordure_fils(2, Noeud::VOID);

            bordure[2]->set_bordure_fils(0, Noeud::VOID);
            bordure[2]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(2, Noeud::VOID);

            bordure[3]->set_bordure_fils(0, Noeud::VOID);
            bordure[3]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[3]->set_bordure_fils(2, Noeud::VOID);

            // init les elements
            std::vector<Element *> elementTuile;
            Element * element1 = new Element(Noeud::PLAINE,std::make_pair(0.9,0.9));
            Element * element2 = new Element(Noeud::ABBAYE,std::make_pair(0.5,0.5));

            // init les voisins
            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[1]->get_bordure_fils(1));
            element1->set_voisin(bordure[2]->get_bordure_fils(1));
            element1->set_voisin(bordure[3]->get_bordure_fils(1));

            // Ajout des liens additionelles
            // Aucun

            // ajoute nullptr vers voisin de la bordure non connecté
            bordure[0]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(2)->set_lien(nullptr);
           
            bordure[1]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[2]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[3]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(2)->set_lien(nullptr);


            // Ajout des Tuiles dans le vector
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);

            // Creation de la carte
            Tuile * carte = new Tuile(id, 20, bordure, elementTuile);
            id++;

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
    }
    }

    // Tuile 21 (x2)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_2 ; nb++){

            std::array<Bordure *, 4> bordure;
            std::vector<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
                bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(0, Noeud::VOID);
            bordure[0]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[0]->set_bordure_fils(2, Noeud::VOID);

            bordure[1]->set_bordure_fils(0, Noeud::VOID);
            bordure[1]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[1]->set_bordure_fils(2, Noeud::VOID);

            bordure[2]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[2]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(0, Noeud::VOID);
            bordure[3]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[3]->set_bordure_fils(2, Noeud::VOID);

            // init les elements
            std::vector<Element *> elementTuile;
            Element * element1 = new Element(Noeud::PLAINE,std::make_pair(0.9,0.9));
            Element * element2 = new Element(Noeud::ROUTE,std::make_pair(0.5,0.1));
            Element * element3 = new Element(Noeud::ABBAYE,std::make_pair(0.5,0.5));

            // init les voisins
            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[1]->get_bordure_fils(1));
            element1->set_voisin(bordure[2]->get_bordure_fils(0));
            element1->set_voisin(bordure[2]->get_bordure_fils(2));
            element1->set_voisin(bordure[3]->get_bordure_fils(1));

            element2->set_voisin(bordure[2]->get_bordure_fils(1));
            // Ajout des liens additionelles
            // Aucun

            // ajoute nullptr vers voisin de la bordure non connecté
            bordure[0]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(2)->set_lien(nullptr);
           
            bordure[1]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[2]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[3]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(2)->set_lien(nullptr);


            // Ajout element dans le vecteur
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);

            // Creation de la carte
            Tuile * carte = new Tuile(id, 21, bordure, elementTuile);
            id++;

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
    }
    }

    // Tuile 22 (x3)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_3 ; nb++){

            std::array<Bordure *, 4> bordure;
            std::vector<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(0, Noeud::VOID);
            bordure[0]->set_bordure_fils(1, Noeud::VILLE);
            bordure[0]->set_bordure_fils(2, Noeud::VOID);

            bordure[1]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[1]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[1]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[2]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[2]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[3]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[3]->set_bordure_fils(2, Noeud::PLAINE);

            // init les elements
            std::vector<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE,std::make_pair(0.5,0.9));
            Element * element2 = new Element(Noeud::ROUTE,std::make_pair(0.8,0.5));
            Element * element3 = new Element(Noeud::ROUTE,std::make_pair(0.5,0.2));
            Element * element4 = new Element(Noeud::ROUTE,std::make_pair(0.2,0.5));
            Element * element5 = new Element(Noeud::PLAINE,std::make_pair(0.5,0.6));
            Element * element6 = new Element(Noeud::PLAINE,std::make_pair(0.8,0.2));
            Element * element7 = new Element(Noeud::PLAINE,std::make_pair(0.2,0.2));

            // init les voisins
            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));

            element2->set_voisin(bordure[1]->get_bordure_fils(1));

            element3->set_voisin(bordure[2]->get_bordure_fils(1));

            element4->set_voisin(bordure[3]->get_bordure_fils(1));

            element5->set_voisin(bordure[1]->get_bordure_fils(0));
            element5->set_voisin(bordure[3]->get_bordure_fils(2));

            element6->set_voisin(bordure[1]->get_bordure_fils(2));
            element6->set_voisin(bordure[2]->get_bordure_fils(0));

            element7->set_voisin(bordure[2]->get_bordure_fils(2));
            element7->set_voisin(bordure[3]->get_bordure_fils(0));

            // Ajout des liens additionelles
            element5->set_lien(element1);

            // ajoute nullptr vers voisin de la bordure non connecté
            bordure[0]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(2)->set_lien(nullptr);
           
            bordure[1]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[2]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[3]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(2)->set_lien(nullptr);


            // Ajout element dans le vecteur
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);
            elementTuile.push_back(element4);
            elementTuile.push_back(element5);
            elementTuile.push_back(element6);
            elementTuile.push_back(element7);

            // Creation de la carte
            Tuile * carte = new Tuile(id, 22, bordure, elementTuile);
            id++;

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
    }
    }

    // Tuile 23 (x4)
    {
    for (int nb = 0 ; nb < NOMBRE_TUILES_4 ; nb++){

            std::array<Bordure *, 4> bordure;
            std::vector<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
            bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(0, Noeud::VOID);
            bordure[0]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[0]->set_bordure_fils(2, Noeud::VOID);

            bordure[1]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[1]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[1]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[2]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[2]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[3]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[3]->set_bordure_fils(2, Noeud::PLAINE);

            // init les elements
            std::vector<Element *> elementTuile;
            Element * element1 = new Element(Noeud::PLAINE,std::make_pair(0.5,0.8));
            Element * element2 = new Element(Noeud::ROUTE,std::make_pair(0.8,0.5));
            Element * element3 = new Element(Noeud::PLAINE,std::make_pair(0.8,0.2));
            Element * element4 = new Element(Noeud::ROUTE,std::make_pair(0.5,0.2));
            Element * element5 = new Element(Noeud::PLAINE,std::make_pair(0.2,0.2));
            Element * element6 = new Element(Noeud::ROUTE,std::make_pair(0.2,0.5));

            // init les voisins
            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[3]->get_bordure_fils(2));
            element1->set_voisin(bordure[1]->get_bordure_fils(0));
            
            element2->set_voisin(bordure[1]->get_bordure_fils(1));

            element3->set_voisin(bordure[1]->get_bordure_fils(2));
            element3->set_voisin(bordure[2]->get_bordure_fils(0));

            element4->set_voisin(bordure[2]->get_bordure_fils(1));

            element5->set_voisin(bordure[2]->get_bordure_fils(2));
            element5->set_voisin(bordure[3]->get_bordure_fils(0));

            element6->set_voisin(bordure[3]->get_bordure_fils(1));

            // Ajout des liens additionelles
            // Aucun

            // ajoute nullptr vers voisin de la bordure non connecté
            bordure[0]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(2)->set_lien(nullptr);
           
            bordure[1]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[2]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[3]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(2)->set_lien(nullptr);


            // Ajout element dans le vecteur
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);
            elementTuile.push_back(element4);
            elementTuile.push_back(element5);
            elementTuile.push_back(element6);

            // Creation de la carte
            Tuile * carte = new Tuile(id, 23, bordure, elementTuile);
            id++;

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
    }
    }

    // Tuile 24 (x1)
    {

            std::array<Bordure *, 4> bordure;
            std::vector<Element *> element;

            // init bordure
            for(int i = 0; i < 4; i++)
            {
                bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[0]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[0]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[1]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[1]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[1]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[2]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[2]->set_bordure_fils(2, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(0, Noeud::PLAINE);
            bordure[3]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[3]->set_bordure_fils(2, Noeud::PLAINE);

            // init les elements
            std::vector<Element *> elementTuile;
            Element * element1 = new Element(Noeud::ROUTE,std::make_pair(0.5,0.8));
            Element * element2 = new Element(Noeud::PLAINE,std::make_pair(0.8,0.8));
            Element * element3 = new Element(Noeud::ROUTE,std::make_pair(0.8,0.5));
            Element * element4 = new Element(Noeud::PLAINE,std::make_pair(0.8,0.2));
            Element * element5 = new Element(Noeud::ROUTE,std::make_pair(0.5,0.2));
            Element * element6 = new Element(Noeud::PLAINE,std::make_pair(0.2,0.2));
            Element * element7 = new Element(Noeud::ROUTE,std::make_pair(0.2,0.5));
            Element * element8 = new Element(Noeud::PLAINE,std::make_pair(0.2,0.8));

            // init les voisins
            // element:
            element1->set_voisin(bordure[1]->get_bordure_fils(1));

            element2->set_voisin(bordure[0]->get_bordure_fils(2));
            element2->set_voisin(bordure[1]->get_bordure_fils(0));

            element3->set_voisin(bordure[2]->get_bordure_fils(1));

            element4->set_voisin(bordure[1]->get_bordure_fils(2));
            element4->set_voisin(bordure[2]->get_bordure_fils(0));

            element5->set_voisin(bordure[2]->get_bordure_fils(1));

            element6->set_voisin(bordure[2]->get_bordure_fils(2));
            element6->set_voisin(bordure[3]->get_bordure_fils(0));

            element7->set_voisin(bordure[3]->get_bordure_fils(1));

            element8->set_voisin(bordure[3]->get_bordure_fils(2));
            element8->set_voisin(bordure[0]->get_bordure_fils(0));

            // Ajout des liens additionelles
                // Aucun

            // ajoute nullptr vers voisin de la bordure non connecté
            bordure[0]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[0]->get_bordure_fils(2)->set_lien(nullptr);
           
            bordure[1]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[1]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[2]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[2]->get_bordure_fils(2)->set_lien(nullptr);

            bordure[3]->get_bordure_fils(0)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(1)->set_lien(nullptr);
            bordure[3]->get_bordure_fils(2)->set_lien(nullptr);


            // Ajout element dans le vecteur
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);
            elementTuile.push_back(element4);
            elementTuile.push_back(element5);
            elementTuile.push_back(element6);
            elementTuile.push_back(element7);
            elementTuile.push_back(element8);

            // Creation de la carte
            Tuile * carte = new Tuile(id, 24, bordure, elementTuile);
            id++;

            // Ajout de la carte dans le pioche
            plateau->ajouter_tuile_pioche(carte); // front pour la première carte
    }
    return plateau;
}
