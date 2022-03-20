// LIBRAIRIES
#include "Plateau.hpp"

// FONCTIONS
Plateau::Plateau()
{
    #ifndef LOG
    Logging::log(Logging::TRACE, "Création du plateau");
    #endif // LOG
}

Plateau::~Plateau()
{}

void Plateau::init_plateau()
{
    for(int i = 0; i < (NBR_TUILES * 2); i++)
    {
        for(int j = 0; j < (NBR_TUILES * 2); j++)
        {
            grille[i][j] = NULL;
        }
    }

    // Tuile 1 (x4)
    {
	for (int nb = 0 ; nb < NOMBRE_TUILES_4 ; nb++){
		for(int i = 0; i < 4; i++){

		    std::array<Bordure *, 4> bordure;
		    std::list<Element *> element;

		    // init les cartes
		    for(int i = 0; i < 4; i++)
		    {
			carteVoisines[i] = nullptr;
		    }

		    // init bordure
		    for(int i = 0; i < 4; i++)
		    {
			bordure.at(i) = new Bordure();
		    }

		    // init les bordures
		    bordure[0]->set_bordure_fils(1, Noeud::VILLE);

		    bordure[1]->set_bordure_fils(0, Noeud::PLAINE);
		    bordure[1]->set_bordure_fils(1, Noeud::ROUTE);
		    bordure[1]->set_bordure_fils(2, Noeud::PLAINE);

		    bordure[2]->set_bordure_fils(1, Noeud::PLAINE);

		    bordure[3]->set_bordure_fils(0, Noeud::PLAINE);
		    bordure[3]->set_bordure_fils(1, Noeud::ROUTE);
		    bordure[3]->set_bordure_fils(2, Noeud::PLAINE);

		    // init les elements
		    std::list<Element *> elementTuile;
		    Element * element1 = new Element(Noeud::VILLE);
		    Element * element2 = new Element(Noeud::ROUTE);
		    Element * element3 = new Element(Noeud::PLAINE);
		    Element * element4 = new Element(Noeud::PLAINE);

		    // init les voisins
		    // bordure:
		    bordure[0]->get_bordure_fils(1)->set_voisin(element1);

		    bordure[1]->get_bordure_fils(0)->set_voisin(element3);
		    bordure[1]->get_bordure_fils(1)->set_voisin(element2);
		    bordure[1]->get_bordure_fils(2)->set_voisin(element4);

		    bordure[2]->get_bordure_fils(1)->set_voisin(element4);

		    bordure[3]->get_bordure_fils(0)->set_voisin(element4);
		    bordure[3]->get_bordure_fils(1)->set_voisin(element2);
		    bordure[3]->get_bordure_fils(2)->set_voisin(element3);

		    // element:
		    element1->set_voisin(bordure[0]->get_bordure_fils(1));

		    element2->set_voisin(bordure[1]->get_bordure_fils(1));
		    element2->set_voisin(bordure[3]->get_bordure_fils(1));

		    element3->set_voisin(bordure[1]->get_bordure_fils(0));
		    element3->set_voisin(bordure[3]->get_bordure_fils(0));

		    element4->set_voisin(bordure[1]->get_bordure_fils(2));
		    element4->set_voisin(bordure[2]->get_bordure_fils(1));
		    element4->set_voisin(bordure[3]->get_bordure_fils(0));

		    // Ajout des liens additionelles
		    element3->set_lien(element1);

		    // Ajout element dans la liste
		    elementTuile.push_back(element1);
		    elementTuile.push_back(element2);
		    elementTuile.push_back(element3);
		    elementTuile.push_back(element4);

		    // Creation de la carte
		    Tuile * carte = new Tuile(carteVoisines, bordure, elementTuile);

		    // Ajout de la carte dans le pioche
		    this->pioche.push_back(carte); // front pour la première carte
		}
	}
    }

    // Tuile 2 (x3)
    {
	for (int nb = 0 ; nb < NOMBRE_TUILES_3 ; nb++){
		for(int i = 0; i < 4; i++){

		    std::array<Bordure *, 4> bordure;
		    std::list<Element *> element;

		    // init les cartes
		    for(int i = 0; i < 4; i++)
		    {
			carteVoisines[i] = nullptr;
		    }

		    // init bordure
		    for(int i = 0; i < 4; i++)
		    {
			bordure.at(i) = new Bordure();
		    }

		    // init les bordures
		    bordure[0]->set_bordure_fils(1, Noeud::VILLE);

		    bordure[1]->set_bordure_fils(0, Noeud::PLAINE);
		    bordure[1]->set_bordure_fils(1, Noeud::ROUTE);
		    bordure[1]->set_bordure_fils(2, Noeud::PLAINE);

		    bordure[2]->set_bordure_fils(0, Noeud::PLAINE);
		    bordure[2]->set_bordure_fils(1, Noeud::ROUTE);
		    bordure[2]->set_bordure_fils(2, Noeud::PLAINE);

		    bordure[3]->set_bordure_fils(1, Noeud::PLAINE);

		    // init les elements
		    std::list<Element *> elementTuile;
		    Element * element1 = new Element(Noeud::VILLE);
		    Element * element2 = new Element(Noeud::ROUTE);
		    Element * element3 = new Element(Noeud::PLAINE);
		    Element * element4 = new Element(Noeud::PLAINE);

		    // init les voisins
		    // bordure:
		    bordure[0]->get_bordure_fils(1)->set_voisin(element1);

		    bordure[1]->get_bordure_fils(0)->set_voisin(element3);
		    bordure[1]->get_bordure_fils(1)->set_voisin(element2);
		    bordure[1]->get_bordure_fils(2)->set_voisin(element4);

		    bordure[2]->get_bordure_fils(0)->set_voisin(element4);
		    bordure[2]->get_bordure_fils(1)->set_voisin(element2);
		    bordure[2]->get_bordure_fils(2)->set_voisin(element3);

		    bordure[3]->get_bordure_fils(1)->set_voisin(element4);

		    // element:
		    element1->set_voisin(bordure[0]->get_bordure_fils(1));

		    element2->set_voisin(bordure[1]->get_bordure_fils(1));
		    element2->set_voisin(bordure[2]->get_bordure_fils(1));

		    element3->set_voisin(bordure[1]->get_bordure_fils(0));
		    element3->set_voisin(bordure[2]->get_bordure_fils(2));
		    element3->set_voisin(bordure[3]->get_bordure_fils(1));

		    element4->set_voisin(bordure[1]->get_bordure_fils(2));
		    element4->set_voisin(bordure[2]->get_bordure_fils(1));

		    // Ajout des liens additionelles
		    element3->set_lien(element1);

		    // Ajout element dans la liste
		    elementTuile.push_back(element1);
		    elementTuile.push_back(element2);
		    elementTuile.push_back(element3);
		    elementTuile.push_back(element4);

		    // Creation de la carte
		    Tuile * carte = new Tuile(carteVoisines, bordure, elementTuile);

		    // Ajout de la carte dans le pioche
		    this->pioche.push_back(carte); // front pour la première carte
		}
	}
    }

    // Tuile 3 (x3)
    {
	for (int nb = 0 ; nb < NOMBRE_TUILES_3 ; nb++){
		for(int i = 0; i < 4; i++){

		    std::array<Bordure *, 4> bordure;
		    std::list<Element *> element;

		    // init les cartes
		    for(int i = 0; i < 4; i++)
		    {
			carteVoisines[i] = nullptr;
		    }

		    // init bordure
		    for(int i = 0; i < 4; i++)
		    {
			bordure.at(i) = new Bordure();
		    }

		    // init les bordures
		    bordure[0]->set_bordure_fils(1, Noeud::VILLE);

		    bordure[1]->set_bordure_fils(1, Noeud::PLAINE);

		    bordure[2]->set_bordure_fils(0, Noeud::PLAINE);
		    bordure[2]->set_bordure_fils(1, Noeud::ROUTE);
		    bordure[2]->set_bordure_fils(2, Noeud::PLAINE);

		    bordure[3]->set_bordure_fils(0, Noeud::PLAINE);
		    bordure[3]->set_bordure_fils(1, Noeud::ROUTE);
		    bordure[3]->set_bordure_fils(2, Noeud::PLAINE);

		    // init les elements
		    std::list<Element *> elementTuile;
		    Element * element1 = new Element(Noeud::VILLE);
		    Element * element2 = new Element(Noeud::ROUTE);
		    Element * element3 = new Element(Noeud::PLAINE);
		    Element * element4 = new Element(Noeud::PLAINE);

		    // init les voisins
		    // bordure:
		    bordure[0]->get_bordure_fils(1)->set_voisin(element1);

		    bordure[1]->get_bordure_fils(1)->set_voisin(element3);

		    bordure[2]->get_bordure_fils(0)->set_voisin(element3);
		    bordure[2]->get_bordure_fils(1)->set_voisin(element2);
		    bordure[2]->get_bordure_fils(2)->set_voisin(element4);

		    bordure[3]->get_bordure_fils(0)->set_voisin(element4);
		    bordure[3]->get_bordure_fils(1)->set_voisin(element2);
		    bordure[3]->get_bordure_fils(2)->set_voisin(element3);

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

		    // Ajout element dans la liste
		    elementTuile.push_back(element1);
		    elementTuile.push_back(element2);
		    elementTuile.push_back(element3);
		    elementTuile.push_back(element4);

		    // Creation de la carte
		    Tuile * carte = new Tuile(carteVoisines, bordure, elementTuile);

		    // Ajout de la carte dans le pioche
		    this->pioche.push_back(carte); // front pour la première carte
		}
	}
    }

    // Tuile 4 (x5)
    {
	for (int nb = 0 ; nb < NOMBRE_TUILES_5 ; nb++){
		for(int i = 0; i < 4; i++){

		    std::array<Bordure *, 4> bordure;
		    std::list<Element *> element;

		    // init les cartes
		    for(int i = 0; i < 4; i++)
		    {
			carteVoisines[i] = nullptr;
		    }

		    // init bordure
		    for(int i = 0; i < 4; i++)
		    {
			bordure.at(i) = new Bordure();
		    }

		    // init les bordures
		    bordure[0]->set_bordure_fils(1, Noeud::VILLE);

		    bordure[1]->set_bordure_fils(1, Noeud::PLAINE);

		    bordure[2]->set_bordure_fils(1, Noeud::PLAINE);

		    bordure[3]->set_bordure_fils(1, Noeud::PLAINE);

		    // init les elements
		    std::list<Element *> elementTuile;
		    Element * element1 = new Element(Noeud::VILLE);
		    Element * element2 = new Element(Noeud::PLAINE);

		    // init les voisins
		    // bordure:
		    bordure[0]->get_bordure_fils(1)->set_voisin(element1);

		    bordure[1]->get_bordure_fils(1)->set_voisin(element2);

		    bordure[2]->get_bordure_fils(1)->set_voisin(element2);

		    bordure[3]->get_bordure_fils(1)->set_voisin(element2);

		    // element:
		    element1->set_voisin(bordure[0]->get_bordure_fils(1));

		    element2->set_voisin(bordure[1]->get_bordure_fils(1));
		    element2->set_voisin(bordure[2]->get_bordure_fils(1));
		    element2->set_voisin(bordure[3]->get_bordure_fils(1));

		    // Ajout des liens additionelles
		    element2->set_lien(element1);
		    // Ajout element dans la liste
		    elementTuile.push_back(element1);
		    elementTuile.push_back(element2);

		    // Creation de la carte
		    Tuile * carte = new Tuile(carteVoisines, bordure, elementTuile);

		    // Ajout de la carte dans le pioche
		    this->pioche.push_back(carte); // front pour la première carte
		}
	}
    }

    // Tuile 5 (x3)
    {
	for (int nb = 0 ; nb < NOMBRE_TUILES_3 ; nb++){
		for(int i = 0; i < 4; i++){

		    std::array<Bordure *, 4> bordure;
		    std::list<Element *> element;

		    // init les cartes
		    for(int i = 0; i < 4; i++)
		    {
			carteVoisines[i] = nullptr;
		    }

		    // init bordure
		    for(int i = 0; i < 4; i++)
		    {
			bordure.at(i) = new Bordure();
		    }

		    // init les bordures
		    bordure[0]->set_bordure_fils(1, Noeud::VILLE);

		    bordure[1]->set_bordure_fils(1, Noeud::PLAINE);

		    bordure[2]->set_bordure_fils(1, Noeud::VILLE);

		    bordure[3]->set_bordure_fils(1, Noeud::PLAINE);

		    // init les elements
		    std::list<Element *> elementTuile;
		    Element * element1 = new Element(Noeud::VILLE);
		    Element * element2 = new Element(Noeud::PLAINE);
		    Element * element3 = new Element(Noeud::VILLE);

		    // init les voisins
		    // bordure:
		    bordure[0]->get_bordure_fils(1)->set_voisin(element1);

		    bordure[1]->get_bordure_fils(1)->set_voisin(element2);

		    bordure[2]->get_bordure_fils(1)->set_voisin(element3);

		    bordure[3]->get_bordure_fils(1)->set_voisin(element2);

		    // element:
		    element1->set_voisin(bordure[0]->get_bordure_fils(1));

		    element2->set_voisin(bordure[1]->get_bordure_fils(1));
		    element2->set_voisin(bordure[3]->get_bordure_fils(1));

		    element3->set_voisin(bordure[2]->get_bordure_fils(1));

		    // Ajout des liens additionelles
		    element2->set_lien(element1);
		    element2->set_lien(element3);

		    // Ajout element dans la liste
		    elementTuile.push_back(element1);
		    elementTuile.push_back(element2);
		    elementTuile.push_back(element3);

		    // Creation de la carte
		    Tuile * carte = new Tuile(carteVoisines, bordure, elementTuile);

		    // Ajout de la carte dans le pioche
		    this->pioche.push_back(carte); // front pour la première carte
		}
	}
    }

    // Tuile 6 (x2)
    {
	for (int nb = 0 ; nb < NOMBRE_TUILES_2 ; nb++){
		for(int i = 0; i < 4; i++){

		    std::array<Bordure *, 4> bordure;
		    std::list<Element *> element;

		    // init les cartes
		    for(int i = 0; i < 4; i++)
		    {
			carteVoisines[i] = nullptr;
		    }

		    // init bordure
		    for(int i = 0; i < 4; i++)
		    {
			bordure.at(i) = new Bordure();
		    }

		    // init les bordures
		    bordure[0]->set_bordure_fils(1, Noeud::VILLE);

		    bordure[1]->set_bordure_fils(1, Noeud::VILLE);

		    bordure[2]->set_bordure_fils(1, Noeud::PLAINE);

		    bordure[3]->set_bordure_fils(1, Noeud::PLAINE);

		    // init les elements
		    std::list<Element *> elementTuile;
		    Element * element1 = new Element(Noeud::VILLE);
		    Element * element2 = new Element(Noeud::VILLE);
		    Element * element3 = new Element(Noeud::PLAINE);

		    // init les voisins
		    // bordure:
		    bordure[0]->get_bordure_fils(1)->set_voisin(element1);

		    bordure[1]->get_bordure_fils(1)->set_voisin(element2);

		    bordure[2]->get_bordure_fils(1)->set_voisin(element3);

		    bordure[3]->get_bordure_fils(1)->set_voisin(element3);

		    // element:
		    element1->set_voisin(bordure[0]->get_bordure_fils(1));

		    element2->set_voisin(bordure[1]->get_bordure_fils(1));

		    element3->set_voisin(bordure[2]->get_bordure_fils(1));
		    element3->set_voisin(bordure[3]->get_bordure_fils(1));

		    // Ajout des liens additionelles
		    element3->set_lien(element1);
		    element3->set_lien(element2);

		    // Ajout element dans la liste
		    elementTuile.push_back(element1);
		    elementTuile.push_back(element2);
		    elementTuile.push_back(element3);

		    // Creation de la carte
		    Tuile * carte = new Tuile(carteVoisines, bordure, elementTuile);

		    // Ajout de la carte dans le pioche
		    this->pioche.push_back(carte); // front pour la première carte
		}
	}
    }

    // Tuile 7 (x8)
    {
	for (int nb = 0 ; nb < NOMBRE_TUILES_8 ; nb++){
		for(int i = 0; i < 4; i++){

		    std::array<Bordure *, 4> bordure;
		    std::list<Element *> element;

		    // init les cartes
		    for(int i = 0; i < 4; i++)
		    {
			carteVoisines[i] = nullptr;
		    }

		    // init bordure
		    for(int i = 0; i < 4; i++)
		    {
			bordure.at(i) = new Bordure();
		    }

		    // init les bordures
		    bordure[0]->set_bordure_fils(1, Noeud::PLAINE);

		    bordure[1]->set_bordure_fils(1, Noeud::ROUTE);

		    bordure[2]->set_bordure_fils(1, Noeud::PLAINE);

		    bordure[3]->set_bordure_fils(1, Noeud::ROUTE);

		    // init les elements
		    std::list<Element *> elementTuile;
		    Element * element1 = new Element(Noeud::PLAINE);
		    Element * element2 = new Element(Noeud::ROUTE);
		    Element * element3 = new Element(Noeud::PLAINE);

		    // init les voisins
		    // bordure:
		    bordure[0]->get_bordure_fils(1)->set_voisin(element1);

		    bordure[1]->get_bordure_fils(0)->set_voisin(element1);
		    bordure[1]->get_bordure_fils(1)->set_voisin(element2);
		    bordure[1]->get_bordure_fils(2)->set_voisin(element3);

		    bordure[2]->get_bordure_fils(1)->set_voisin(element3);

		    bordure[3]->get_bordure_fils(0)->set_voisin(element3);
		    bordure[3]->get_bordure_fils(1)->set_voisin(element2);
		    bordure[3]->get_bordure_fils(2)->set_voisin(element1);

		    // element:
		    element1->set_voisin(bordure[0]->get_bordure_fils(1));
		    element1->set_voisin(bordure[1]->get_bordure_fils(0));
		    element1->set_voisin(bordure[3]->get_bordure_fils(2));

		    element2->set_voisin(bordure[1]->get_bordure_fils(1));
		    element2->set_voisin(bordure[3]->get_bordure_fils(1));

		    element3->set_voisin(bordure[1]->get_bordure_fils(2));
		    element3->set_voisin(bordure[2]->get_bordure_fils(1));
		    element3->set_voisin(bordure[3]->get_bordure_fils(0));

		    // Ajout des liens additionelles
			// Aucun

		    // Ajout element dans la liste
		    elementTuile.push_back(element1);
		    elementTuile.push_back(element2);
		    elementTuile.push_back(element3);

		    // Creation de la carte
		    Tuile * carte = new Tuile(carteVoisines, bordure, elementTuile);

		    // Ajout de la carte dans le pioche
		    this->pioche.push_back(carte); // front pour la première carte
		}
	}
    }

    // Tuile 8 (x9)
    {
	for (int nb = 0 ; nb < NOMBRE_TUILES_9 ; nb++){
		for(int i = 0; i < 4; i++){

		    std::array<Bordure *, 4> bordure;
		    std::list<Element *> element;

		    // init les cartes
		    for(int i = 0; i < 4; i++)
		    {
			carteVoisines[i] = nullptr;
		    }

		    // init bordure
		    for(int i = 0; i < 4; i++)
		    {
			bordure.at(i) = new Bordure();
		    }

		    // init les bordures
		    bordure[0]->set_bordure_fils(1, Noeud::PLAINE);

		    bordure[1]->set_bordure_fils(1, Noeud::ROUTE);

		    bordure[2]->set_bordure_fils(1, Noeud::ROUTE);

		    bordure[3]->set_bordure_fils(1, Noeud::PLAINE);

		    // init les elements
		    std::list<Element *> elementTuile;
		    Element * element1 = new Element(Noeud::PLAINE);
		    Element * element2 = new Element(Noeud::ROUTE);
		    Element * element3 = new Element(Noeud::PLAINE);

		    // init les voisins
		    // bordure:
		    bordure[0]->get_bordure_fils(1)->set_voisin(element1);

		    bordure[1]->get_bordure_fils(0)->set_voisin(element1);
		    bordure[1]->get_bordure_fils(1)->set_voisin(element2);
		    bordure[1]->get_bordure_fils(2)->set_voisin(element3);

		    bordure[2]->get_bordure_fils(0)->set_voisin(element3);
		    bordure[2]->get_bordure_fils(1)->set_voisin(element2);
		    bordure[2]->get_bordure_fils(2)->set_voisin(element1);

		    bordure[3]->get_bordure_fils(1)->set_voisin(element1);

		    // element:
		    element1->set_voisin(bordure[0]->get_bordure_fils(1));
		    element1->set_voisin(bordure[1]->get_bordure_fils(0));
		    element1->set_voisin(bordure[3]->get_bordure_fils(1));

		    element2->set_voisin(bordure[1]->get_bordure_fils(1));
		    element2->set_voisin(bordure[2]->get_bordure_fils(1));

		    element3->set_voisin(bordure[1]->get_bordure_fils(2));
		    element3->set_voisin(bordure[2]->get_bordure_fils(0));

		    // Ajout des liens additionelles
			// Aucun

		    // Ajout element dans la liste
		    elementTuile.push_back(element1);
		    elementTuile.push_back(element2);
		    elementTuile.push_back(element3);

		    // Creation de la carte
		    Tuile * carte = new Tuile(carteVoisines, bordure, elementTuile);

		    // Ajout de la carte dans le pioche
		    this->pioche.push_back(carte); // front pour la première carte
		}
	}
    }

    // Tuile 9 (x3)
    {
	for (int nb = 0 ; nb < NOMBRE_TUILES_3 ; nb++){
		for(int i = 0; i < 4; i++){

		    std::array<Bordure *, 4> bordure;
		    std::list<Element *> element;

		    // init les cartes
		    for(int i = 0; i < 4; i++)
		    {
			carteVoisines[i] = nullptr;
		    }

		    // init bordure
		    for(int i = 0; i < 4; i++)
		    {
			bordure.at(i) = new Bordure();
		    }

		    // init les bordures
		    bordure[0]->set_bordure_fils(1, Noeud::VILLE);

		    bordure[1]->set_bordure_fils(1, Noeud::VILLE);

		    bordure[2]->set_bordure_fils(1, Noeud::PLAINE);

		    bordure[3]->set_bordure_fils(1, Noeud::PLAINE);

		    // init les elements
		    std::list<Element *> elementTuile;
		    Element * element1 = new Element(Noeud::VILLE);
		    Element * element2 = new Element(Noeud::PLAINE);

		    // init les voisins
		    // bordure:
		    bordure[0]->get_bordure_fils(1)->set_voisin(element1);

		    bordure[1]->get_bordure_fils(1)->set_voisin(element1);

		    bordure[2]->get_bordure_fils(1)->set_voisin(element2);

		    bordure[3]->get_bordure_fils(1)->set_voisin(element2);

		    // element:
		    element1->set_voisin(bordure[0]->get_bordure_fils(1));

		    element2->set_voisin(bordure[1]->get_bordure_fils(1));

		    element2->set_voisin(bordure[2]->get_bordure_fils(1));
		    element2->set_voisin(bordure[3]->get_bordure_fils(1));

		    // Ajout des liens additionelles
		    element2->set_lien(element1);

		    // Ajout element dans la liste
		    elementTuile.push_back(element1);
		    elementTuile.push_back(element2);

		    // Creation de la carte
		    Tuile * carte = new Tuile(carteVoisines, bordure, elementTuile);

		    // Ajout de la carte dans le pioche
		    this->pioche.push_back(carte); // front pour la première carte
		}
	}
    }

    // Tuile 10 (x2)
    {
	for (int nb = 0 ; nb < NOMBRE_TUILES_2 ; nb++){
		for(int i = 0; i < 4; i++){

		    std::array<Bordure *, 4> bordure;
		    std::list<Element *> element;

		    // init les cartes
		    for(int i = 0; i < 4; i++)
		    {
			carteVoisines[i] = nullptr;
		    }

		    // init bordure
		    for(int i = 0; i < 4; i++)
		    {
			bordure.at(i) = new Bordure();
		    }

		    // init les bordures
		    bordure[0]->set_bordure_fils(1, Noeud::VILLE_BLASON);

		    bordure[1]->set_bordure_fils(1, Noeud::VILLE_BLASON);

		    bordure[2]->set_bordure_fils(1, Noeud::PLAINE);

		    bordure[3]->set_bordure_fils(1, Noeud::PLAINE);

		    // init les elements
		    std::list<Element *> elementTuile;
		    Element * element1 = new Element(Noeud::VILLE_BLASON);
		    Element * element2 = new Element(Noeud::PLAINE);

		    // init les voisins
		    // bordure:
		    bordure[0]->get_bordure_fils(1)->set_voisin(element1);

		    bordure[1]->get_bordure_fils(1)->set_voisin(element1);

		    bordure[2]->get_bordure_fils(1)->set_voisin(element2);

		    bordure[3]->get_bordure_fils(1)->set_voisin(element2);

		    // element:
		    element1->set_voisin(bordure[0]->get_bordure_fils(1));

		    element2->set_voisin(bordure[1]->get_bordure_fils(1));

		    element2->set_voisin(bordure[2]->get_bordure_fils(1));
		    element2->set_voisin(bordure[3]->get_bordure_fils(1));

		    // Ajout des liens additionelles
		    element2->set_lien(element1);

		    // Ajout element dans la liste
		    elementTuile.push_back(element1);
		    elementTuile.push_back(element2);

		    // Creation de la carte
		    Tuile * carte = new Tuile(carteVoisines, bordure, elementTuile);

		    // Ajout de la carte dans le pioche
		    this->pioche.push_back(carte); // front pour la première carte
		}
	}
    }

    // Tuile 11 (x3)
    {
	for (int nb = 0 ; nb < NOMBRE_TUILES_3 ; nb++){
		for(int i = 0; i < 4; i++){

		    std::array<Bordure *, 4> bordure;
		    std::list<Element *> element;

		    // init les cartes
		    for(int i = 0; i < 4; i++)
		    {
			carteVoisines[i] = nullptr;
		    }

		    // init bordure
		    for(int i = 0; i < 4; i++)
		    {
			bordure.at(i) = new Bordure();
		    }

		    // init les bordures
		    bordure[0]->set_bordure_fils(1, Noeud::VILLE);

		    bordure[1]->set_bordure_fils(0, Noeud::PLAINE);
		    bordure[1]->set_bordure_fils(1, Noeud::ROUTE);
		    bordure[1]->set_bordure_fils(2, Noeud::PLAINE);

		    bordure[2]->set_bordure_fils(0, Noeud::PLAINE);
		    bordure[2]->set_bordure_fils(1, Noeud::ROUTE);
		    bordure[2]->set_bordure_fils(2, Noeud::PLAINE);

		    bordure[3]->set_bordure_fils(1, Noeud::VILLE);

		    // init les elements
		    std::list<Element *> elementTuile;
		    Element * element1 = new Element(Noeud::VILLE);
		    Element * element2 = new Element(Noeud::ROUTE);
		    Element * element3 = new Element(Noeud::PLAINE);
		    Element * element4 = new Element(Noeud::PLAINE);

		    // init les voisins
		    // bordure:
		    bordure[0]->get_bordure_fils(1)->set_voisin(element1);

		    bordure[1]->get_bordure_fils(0)->set_voisin(element3);
		    bordure[1]->get_bordure_fils(1)->set_voisin(element2);
		    bordure[1]->get_bordure_fils(2)->set_voisin(element4);

		    bordure[2]->get_bordure_fils(0)->set_voisin(element4);
		    bordure[2]->get_bordure_fils(1)->set_voisin(element2);
		    bordure[2]->get_bordure_fils(2)->set_voisin(element3);

		    bordure[3]->get_bordure_fils(1)->set_voisin(element1);

		    // element:
		    element1->set_voisin(bordure[0]->get_bordure_fils(1));
		    element1->set_voisin(bordure[3
		    ]->get_bordure_fils(1));

		    element2->set_voisin(bordure[1]->get_bordure_fils(1));
		    element2->set_voisin(bordure[2]->get_bordure_fils(1));

		    element3->set_voisin(bordure[1]->get_bordure_fils(0));
		    element3->set_voisin(bordure[2]->get_bordure_fils(2));

		    // Ajout des liens additionelles
		    element3->set_lien(element1);

		    // Ajout element dans la liste
		    elementTuile.push_back(element1);
		    elementTuile.push_back(element2);
		    elementTuile.push_back(element3);
		    elementTuile.push_back(element4);


		    // Creation de la carte
		    Tuile * carte = new Tuile(carteVoisines, bordure, elementTuile);

		    // Ajout de la carte dans le pioche
		    this->pioche.push_back(carte); // front pour la première carte
		}
	}
    }

    // Tuile 12 (x2)
    {
	for (int nb = 0 ; nb < NOMBRE_TUILES_2 ; nb++){
		for(int i = 0; i < 4; i++){

		    std::array<Bordure *, 4> bordure;
		    std::list<Element *> element;

		    // init les cartes
		    for(int i = 0; i < 4; i++)
		    {
			carteVoisines[i] = nullptr;
		    }

		    // init bordure
		    for(int i = 0; i < 4; i++)
		    {
			bordure.at(i) = new Bordure();
		    }

		    // init les bordures
		    bordure[0]->set_bordure_fils(1, Noeud::VILLE_BLASON);

		    bordure[1]->set_bordure_fils(0, Noeud::PLAINE);
		    bordure[1]->set_bordure_fils(1, Noeud::ROUTE);
		    bordure[1]->set_bordure_fils(2, Noeud::PLAINE);

		    bordure[2]->set_bordure_fils(0, Noeud::PLAINE);
		    bordure[2]->set_bordure_fils(1, Noeud::ROUTE);
		    bordure[2]->set_bordure_fils(2, Noeud::PLAINE);

		    bordure[3]->set_bordure_fils(1, Noeud::VILLE_BLASON);

		    // init les elements
		    std::list<Element *> elementTuile;
		    Element * element1 = new Element(Noeud::VILLE_BLASON);
		    Element * element2 = new Element(Noeud::ROUTE);
		    Element * element3 = new Element(Noeud::PLAINE);
		    Element * element4 = new Element(Noeud::PLAINE);

		    // init les voisins
		    // bordure:
		    bordure[0]->get_bordure_fils(1)->set_voisin(element1);

		    bordure[1]->get_bordure_fils(0)->set_voisin(element3);
		    bordure[1]->get_bordure_fils(1)->set_voisin(element2);
		    bordure[1]->get_bordure_fils(2)->set_voisin(element4);

		    bordure[2]->get_bordure_fils(0)->set_voisin(element4);
		    bordure[2]->get_bordure_fils(1)->set_voisin(element2);
		    bordure[2]->get_bordure_fils(2)->set_voisin(element3);

		    bordure[3]->get_bordure_fils(1)->set_voisin(element1);

		    // element:
		    element1->set_voisin(bordure[0]->get_bordure_fils(1));
		    element1->set_voisin(bordure[3
		    ]->get_bordure_fils(1));

		    element2->set_voisin(bordure[1]->get_bordure_fils(1));
		    element2->set_voisin(bordure[2]->get_bordure_fils(1));

		    element3->set_voisin(bordure[1]->get_bordure_fils(0));
		    element3->set_voisin(bordure[2]->get_bordure_fils(2));

		    // Ajout des liens additionelles
		    element3->set_lien(element1);

		    // Ajout element dans la liste
		    elementTuile.push_back(element1);
		    elementTuile.push_back(element2);
		    elementTuile.push_back(element3);
		    elementTuile.push_back(element4);

		    // Creation de la carte
		    Tuile * carte = new Tuile(carteVoisines, bordure, elementTuile);

		    // Ajout de la carte dans le pioche
		    this->pioche.push_back(carte); // front pour la première carte
		}
	}
    }

    // Tuile 13 (x1)
    {
        for(int i = 0; i < 4; i++){
            
            std::array<Bordure *, 4> bordure;
            std::list<Element *> element;

            // init les cartes
            for(int i = 0; i < 4; i++)
            {
                carteVoisines[i] = nullptr;
            }

            // init bordure
            for(int i = 0; i < 4; i++)
            {
                bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(1, Noeud::VILLE);

            bordure[1]->set_bordure_fils(1, Noeud::PLAINE);

            bordure[2]->set_bordure_fils(1, Noeud::VILLE);

            bordure[3]->set_bordure_fils(1, Noeud::PLAINE);

            // init les elements
            std::list<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE);
            Element * element2 = new Element(Noeud::PLAINE);
            Element * element3 = new Element(Noeud::PLAINE);

            // init les voisins
            // bordure:
            bordure[0]->get_bordure_fils(1)->set_voisin(element1);

            bordure[1]->get_bordure_fils(1)->set_voisin(element2);

            bordure[2]->get_bordure_fils(1)->set_voisin(element1);

            bordure[3]->get_bordure_fils(1)->set_voisin(element3);

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[2]->get_bordure_fils(1));

            element2->set_voisin(bordure[1]->get_bordure_fils(1));

            element3->set_voisin(bordure[3]->get_bordure_fils(1));

            // Ajout des liens additionelles
            element2->set_lien(element1);
            element3->set_lien(element1);


	    // Ajout element dans la liste
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);

            // Creation de la carte
            Tuile * carte = new Tuile(carteVoisines, bordure, elementTuile);

            // Ajout de la carte dans le pioche
            this->pioche.push_back(carte); // front pour la première carte
        }
    }

    // Tuile 14 (x2)
    {
	for (int nb = 0 ; nb < NOMBRE_TUILES_2 ; nb++){
		for(int i = 0; i < 4; i++){

		    std::array<Bordure *, 4> bordure;
		    std::list<Element *> element;

		    // init les cartes
		    for(int i = 0; i < 4; i++)
		    {
			carteVoisines[i] = nullptr;
		    }

		    // init bordure
		    for(int i = 0; i < 4; i++)
		    {
			bordure.at(i) = new Bordure();
		    }

		    // init les bordures
		    bordure[0]->set_bordure_fils(1, Noeud::VILLE_BLASON);

		    bordure[1]->set_bordure_fils(1, Noeud::PLAINE);

		    bordure[2]->set_bordure_fils(1, Noeud::VILLE_BLASON);

		    bordure[3]->set_bordure_fils(1, Noeud::PLAINE);

		    // init les elements
		    std::list<Element *> elementTuile;
		    Element * element1 = new Element(Noeud::VILLE_BLASON);
		    Element * element2 = new Element(Noeud::PLAINE);
		    Element * element3 = new Element(Noeud::PLAINE);

		    // init les voisins
		    // bordure:
		    bordure[0]->get_bordure_fils(1)->set_voisin(element1);

		    bordure[1]->get_bordure_fils(1)->set_voisin(element2);

		    bordure[2]->get_bordure_fils(1)->set_voisin(element1);

		    bordure[3]->get_bordure_fils(1)->set_voisin(element3);

		    // element:
		    element1->set_voisin(bordure[0]->get_bordure_fils(1));
		    element1->set_voisin(bordure[2]->get_bordure_fils(1));

		    element2->set_voisin(bordure[1]->get_bordure_fils(1));

		    element3->set_voisin(bordure[3]->get_bordure_fils(1));

		    // Ajout des liens additionelles
		    element2->set_lien(element1);
		    element3->set_lien(element1);

		    // Ajout element dans la liste
		    elementTuile.push_back(element1);
		    elementTuile.push_back(element2);
		    elementTuile.push_back(element3);

		    // Creation de la carte
		    Tuile * carte = new Tuile(carteVoisines, bordure, elementTuile);

		    // Ajout de la carte dans le pioche
		    this->pioche.push_back(carte); // front pour la première carte
		}
	}
    }

    // Tuile 15 (x3)
    {
	for (int nb = 0 ; nb < NOMBRE_TUILES_3 ; nb++){
		for(int i = 0; i < 4; i++){

		    std::array<Bordure *, 4> bordure;
		    std::list<Element *> element;

		    // init les cartes
		    for(int i = 0; i < 4; i++)
		    {
			carteVoisines[i] = nullptr;
		    }

		    // init bordure
		    for(int i = 0; i < 4; i++)
		    {
			bordure.at(i) = new Bordure();
		    }

		    // init les bordures
		    bordure[0]->set_bordure_fils(1, Noeud::VILLE);

		    bordure[1]->set_bordure_fils(1, Noeud::VILLE);

		    bordure[2]->set_bordure_fils(1, Noeud::PLAINE);

		    bordure[3]->set_bordure_fils(1, Noeud::VILLE);

		    // init les elements
		    std::list<Element *> elementTuile;
		    Element * element1 = new Element(Noeud::VILLE);
		    Element * element2 = new Element(Noeud::PLAINE);

		    // init les voisins
		    // bordure:
		    bordure[0]->get_bordure_fils(1)->set_voisin(element1);

		    bordure[1]->get_bordure_fils(1)->set_voisin(element1);

		    bordure[2]->get_bordure_fils(1)->set_voisin(element2);

		    bordure[3]->get_bordure_fils(1)->set_voisin(element1);

		    // element:
		    element1->set_voisin(bordure[0]->get_bordure_fils(1));
		    element1->set_voisin(bordure[1]->get_bordure_fils(1));
		    element1->set_voisin(bordure[3]->get_bordure_fils(1));

		    element2->set_voisin(bordure[2]->get_bordure_fils(1));

		    // Ajout des liens additionelles
		    element2->set_lien(element1);

		    // Ajout element dans la liste
		    elementTuile.push_back(element1);
		    elementTuile.push_back(element2);

		    // Creation de la carte
		    Tuile * carte = new Tuile(carteVoisines, bordure, elementTuile);

		    // Ajout de la carte dans le pioche
		    this->pioche.push_back(carte); // front pour la première carte
		}
	}
    }

    // Tuile 16 (x1)
    {
        for(int i = 0; i < 4; i++){
            
            std::array<Bordure *, 4> bordure;
            std::list<Element *> element;

            // init les cartes
            for(int i = 0; i < 4; i++)
            {
                carteVoisines[i] = nullptr;
            }

            // init bordure
            for(int i = 0; i < 4; i++)
            {
                bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(1, Noeud::VILLE_BLASON);

            bordure[1]->set_bordure_fils(1, Noeud::VILLE_BLASON);

            bordure[2]->set_bordure_fils(1, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(1, Noeud::VILLE_BLASON);

            // init les elements
            std::list<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE_BLASON);
            Element * element2 = new Element(Noeud::PLAINE);

            // init les voisins
            // bordure:
            bordure[0]->get_bordure_fils(1)->set_voisin(element1);

            bordure[1]->get_bordure_fils(1)->set_voisin(element1);

            bordure[2]->get_bordure_fils(1)->set_voisin(element2);

            bordure[3]->get_bordure_fils(1)->set_voisin(element1);

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[1]->get_bordure_fils(1));
            element1->set_voisin(bordure[3]->get_bordure_fils(1));

            element2->set_voisin(bordure[2]->get_bordure_fils(1));

            // Ajout des liens additionelles
            element2->set_lien(element1);
	   
	    // Ajout element dans la liste
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);

            // Creation de la carte
            Tuile * carte = new Tuile(carteVoisines, bordure, elementTuile);

            // Ajout de la carte dans le pioche
            this->pioche.push_back(carte); // front pour la première carte
        }
    }

    // Tuile 17 (x1)
    {
        for(int i = 0; i < 4; i++){
            
            std::array<Bordure *, 4> bordure;
            std::list<Element *> element;

            // init les cartes
            for(int i = 0; i < 4; i++)
            {
                carteVoisines[i] = nullptr;
            }

            // init bordure
            for(int i = 0; i < 4; i++)
            {
                bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(1, Noeud::VILLE_BLASON);

            bordure[1]->set_bordure_fils(1, Noeud::VILLE_BLASON);

            bordure[2]->set_bordure_fils(1, Noeud::VILLE_BLASON);

            bordure[3]->set_bordure_fils(1, Noeud::VILLE_BLASON);

            // init les elements
            std::list<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE_BLASON);

            // init les voisins
            // bordure:
            bordure[0]->get_bordure_fils(1)->set_voisin(element1);

            bordure[1]->get_bordure_fils(1)->set_voisin(element1);

            bordure[2]->get_bordure_fils(1)->set_voisin(element1);

            bordure[3]->get_bordure_fils(1)->set_voisin(element1);

            // element:
            element1->set_voisin(bordure[0]->get_bordure_fils(1));
            element1->set_voisin(bordure[1]->get_bordure_fils(1));
            element1->set_voisin(bordure[2]->get_bordure_fils(1));
            element1->set_voisin(bordure[3]->get_bordure_fils(1));

            // Ajout des liens additionelles
                // Aucun
	   
	    // Ajout element dans la liste
            elementTuile.push_back(element1);
         
            // Creation de la carte
            Tuile * carte = new Tuile(carteVoisines, bordure, elementTuile);

            // Ajout de la carte dans le pioche
            this->pioche.push_back(carte); // front pour la première carte
        }
    }

    // Tuile 18 (x1)
    {
        for(int i = 0; i < 4; i++){
            
            std::array<Bordure *, 4> bordure;
            std::list<Element *> element;

            // init les cartes
            for(int i = 0; i < 4; i++)
            {
                carteVoisines[i] = nullptr;
            }

            // init bordure
            for(int i = 0; i < 4; i++)
            {
                bordure.at(i) = new Bordure();
            }

            // init les bordures
            bordure[0]->set_bordure_fils(1, Noeud::VILLE);

            bordure[1]->set_bordure_fils(1, Noeud::VILLE);

            bordure[2]->set_bordure_fils(1, Noeud::PLAINE);
            bordure[2]->set_bordure_fils(1, Noeud::ROUTE);
            bordure[2]->set_bordure_fils(1, Noeud::PLAINE);

            bordure[3]->set_bordure_fils(1, Noeud::VILLE);

            // init les elements
            std::list<Element *> elementTuile;
            Element * element1 = new Element(Noeud::VILLE);
            Element * element2 = new Element(Noeud::ROUTE);
            Element * element3 = new Element(Noeud::PLAINE);
            Element * element4 = new Element(Noeud::PLAINE);

            // init les voisins
            // bordure:
            bordure[0]->get_bordure_fils(1)->set_voisin(element1);

            bordure[1]->get_bordure_fils(1)->set_voisin(element1);

            bordure[2]->get_bordure_fils(0)->set_voisin(element3);
            bordure[2]->get_bordure_fils(1)->set_voisin(element2);
            bordure[2]->get_bordure_fils(2)->set_voisin(element4);

            bordure[3]->get_bordure_fils(1)->set_voisin(element1);

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
            
	    // Ajout element dans la liste
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);
            elementTuile.push_back(element4);

            // Creation de la carte
            Tuile * carte = new Tuile(carteVoisines, bordure, elementTuile);

            // Ajout de la carte dans le pioche
            this->pioche.push_back(carte); // front pour la première carte
        }
    }

    // Tuile 19 (x2)
    {
	for (int nb = 0 ; nb < NOMBRE_TUILES_2 ; nb++){
		for(int i = 0; i < 4; i++){

		    std::array<Bordure *, 4> bordure;
		    std::list<Element *> element;

		    // init les cartes
		    for(int i = 0; i < 4; i++)
		    {
			carteVoisines[i] = nullptr;
		    }

		    // init bordure
		    for(int i = 0; i < 4; i++)
		    {
			bordure.at(i) = new Bordure();
		    }

		    // init les bordures
		    bordure[0]->set_bordure_fils(1, Noeud::VILLE_BLASON);

		    bordure[1]->set_bordure_fils(1, Noeud::VILLE_BLASON);

          	    bordure[2]->set_bordure_fils(1, Noeud::PLAINE);
            	    bordure[2]->set_bordure_fils(1, Noeud::ROUTE);
          	    bordure[2]->set_bordure_fils(1, Noeud::PLAINE);
			
		    bordure[3]->set_bordure_fils(1, Noeud::VILLE_BLASON);

		    // init les elements
		    std::list<Element *> elementTuile;
		    Element * element1 = new Element(Noeud::VILLE_BLASON);
		    Element * element2 = new Element(Noeud::ROUTE);
		    Element * element3 = new Element(Noeud::PLAINE);
		    Element * element4 = new Element(Noeud::PLAINE);

		    // init les voisins
		    // bordure:
		    bordure[0]->get_bordure_fils(1)->set_voisin(element1);

		    bordure[1]->get_bordure_fils(1)->set_voisin(element1);

		    bordure[2]->get_bordure_fils(0)->set_voisin(element3);
		    bordure[2]->get_bordure_fils(1)->set_voisin(element2);
		    bordure[2]->get_bordure_fils(2)->set_voisin(element4);

		    bordure[3]->get_bordure_fils(1)->set_voisin(element1);

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

		    // Ajout element dans la liste
		    elementTuile.push_back(element1);
		    elementTuile.push_back(element2);
		    elementTuile.push_back(element3);
		    elementTuile.push_back(element4);

		    // Creation de la carte
		    Tuile * carte = new Tuile(carteVoisines, bordure, elementTuile);

		    // Ajout de la carte dans le pioche
		    this->pioche.push_back(carte); // front pour la première carte
		}
	}
    }

    // Tuile 20 (x4)
    {
	for (int nb = 0 ; nb < NOMBRE_TUILES_4 ; nb++){
		for(int i = 0; i < 4; i++){

		    std::array<Bordure *, 4> bordure;
		    std::list<Element *> element;

		    // init les cartes
		    for(int i = 0; i < 4; i++)
		    {
			carteVoisines[i] = nullptr;
		    }

		    // init bordure
		    for(int i = 0; i < 4; i++)
		    {
			bordure.at(i) = new Bordure();
		    }

		    // init les bordures
		    bordure[0]->set_bordure_fils(1, Noeud::PLAINE);

		    bordure[1]->set_bordure_fils(1, Noeud::PLAINE);

		    bordure[2]->set_bordure_fils(1, Noeud::PLAINE);

		    bordure[3]->set_bordure_fils(1, Noeud::PLAINE);

		    // init les elements
		    std::list<Element *> elementTuile;
		    Element * element1 = new Element(Noeud::PLAINE);
		    Element * element2 = new Element(Noeud::ABBAYE);

		    // init les voisins
		    // bordure:
		    bordure[0]->get_bordure_fils(1)->set_voisin(element1);

		    bordure[1]->get_bordure_fils(1)->set_voisin(element1);

		    bordure[2]->get_bordure_fils(1)->set_voisin(element1);

		    bordure[3]->get_bordure_fils(1)->set_voisin(element1);

		    // element:
		    element1->set_voisin(bordure[0]->get_bordure_fils(1));
		    element1->set_voisin(bordure[1]->get_bordure_fils(1));
		    element1->set_voisin(bordure[2]->get_bordure_fils(1));
		    element1->set_voisin(bordure[3]->get_bordure_fils(1));

		    // Ajout des liens additionelles
			// Aucun

		    // Ajout des Tuiles dans la liste
		    elementTuile.push_back(element1);
		    elementTuile.push_back(element2);

		    // Ajout element dans la liste
		    elementTuile.push_back(element1);
		    elementTuile.push_back(element2);

		    // Creation de la carte
		    Tuile * carte = new Tuile(carteVoisines, bordure, elementTuile);

		    // Ajout de la carte dans le pioche
		    this->pioche.push_back(carte); // front pour la première carte
		}
	}
    }

    // Tuile 21 (x2)
    {
	for (int nb = 0 ; nb < NOMBRE_TUILES_2 ; nb++){
		for(int i = 0; i < 4; i++){

		    std::array<Bordure *, 4> bordure;
		    std::list<Element *> element;

		    // init les cartes
		    for(int i = 0; i < 4; i++)
		    {
			carteVoisines[i] = nullptr;
		    }

		    // init bordure
		    for(int i = 0; i < 4; i++)
		    {
			bordure.at(i) = new Bordure();
		    }

		    // init les bordures
		    bordure[0]->set_bordure_fils(1, Noeud::PLAINE);

		    bordure[1]->set_bordure_fils(1, Noeud::PLAINE);

		    bordure[2]->set_bordure_fils(1, Noeud::ROUTE);

		    bordure[3]->set_bordure_fils(1, Noeud::PLAINE);

		    // init les elements
		    std::list<Element *> elementTuile;
		    Element * element1 = new Element(Noeud::PLAINE);
		    Element * element2 = new Element(Noeud::ROUTE);
		    Element * element3 = new Element(Noeud::ABBAYE);

		    // init les voisins
		    // bordure:
		    bordure[0]->get_bordure_fils(1)->set_voisin(element1);

		    bordure[1]->get_bordure_fils(1)->set_voisin(element1);

		    bordure[2]->get_bordure_fils(0)->set_voisin(element1);
		    bordure[2]->get_bordure_fils(1)->set_voisin(element2);
		    bordure[2]->get_bordure_fils(2)->set_voisin(element1);

		    bordure[3]->get_bordure_fils(1)->set_voisin(element1);

		    // element:
		    element1->set_voisin(bordure[0]->get_bordure_fils(1));
		    element1->set_voisin(bordure[1]->get_bordure_fils(1));
		    element1->set_voisin(bordure[2]->get_bordure_fils(0));
		    element1->set_voisin(bordure[2]->get_bordure_fils(2));
		    element1->set_voisin(bordure[3]->get_bordure_fils(1));

		    element2->set_voisin(bordure[2]->get_bordure_fils(1));
		    // Ajout des liens additionelles
			// Aucun

		    // Ajout element dans la liste
		    elementTuile.push_back(element1);
		    elementTuile.push_back(element2);
		    elementTuile.push_back(element3);

		    // Creation de la carte
		    Tuile * carte = new Tuile(carteVoisines, bordure, elementTuile);

		    // Ajout de la carte dans le pioche
		    this->pioche.push_back(carte); // front pour la première carte
		}
	}
    }

    // Tuile 22 (x3)
    {
	for (int nb = 0 ; nb < NOMBRE_TUILES_3 ; nb++){
		for(int i = 0; i < 4; i++){

		    std::array<Bordure *, 4> bordure;
		    std::list<Element *> element;

		    // init les cartes
		    for(int i = 0; i < 4; i++)
		    {
			carteVoisines[i] = nullptr;
		    }

		    // init bordure
		    for(int i = 0; i < 4; i++)
		    {
			bordure.at(i) = new Bordure();
		    }

		    // init les bordures
		    bordure[0]->set_bordure_fils(1, Noeud::VILLE);

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
		    std::list<Element *> elementTuile;
		    Element * element1 = new Element(Noeud::VILLE);
		    Element * element2 = new Element(Noeud::ROUTE);
		    Element * element3 = new Element(Noeud::ROUTE);
		    Element * element4 = new Element(Noeud::ROUTE);
		    Element * element5 = new Element(Noeud::PLAINE);
		    Element * element6 = new Element(Noeud::PLAINE);
		    Element * element7 = new Element(Noeud::PLAINE);

		    // init les voisins
		    // bordure:
		    bordure[0]->get_bordure_fils(1)->set_voisin(element1);

		    bordure[1]->get_bordure_fils(0)->set_voisin(element5);
		    bordure[1]->get_bordure_fils(1)->set_voisin(element2);
		    bordure[1]->get_bordure_fils(2)->set_voisin(element6);

		    bordure[2]->get_bordure_fils(0)->set_voisin(element6);
		    bordure[2]->get_bordure_fils(1)->set_voisin(element3);
		    bordure[2]->get_bordure_fils(2)->set_voisin(element7);

		    bordure[3]->get_bordure_fils(0)->set_voisin(element7);
		    bordure[3]->get_bordure_fils(1)->set_voisin(element4);
		    bordure[3]->get_bordure_fils(2)->set_voisin(element5);

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

		    // Ajout element dans la liste
		    elementTuile.push_back(element1);
		    elementTuile.push_back(element2);
		    elementTuile.push_back(element3);
		    elementTuile.push_back(element4);
		    elementTuile.push_back(element5);
		    elementTuile.push_back(element6);
		    elementTuile.push_back(element7);

		    // Creation de la carte
		    Tuile * carte = new Tuile(carteVoisines, bordure, elementTuile);

		    // Ajout de la carte dans le pioche
		    this->pioche.push_back(carte); // front pour la première carte
		}
	}
    }

    // Tuile 23 (x4)
    {
	for (int nb = 0 ; nb < NOMBRE_TUILES_4 ; nb++){
		for(int i = 0; i < 4; i++){

		    std::array<Bordure *, 4> bordure;
		    std::list<Element *> element;

		    // init les cartes
		    for(int i = 0; i < 4; i++)
		    {
			carteVoisines[i] = nullptr;
		    }

		    // init bordure
		    for(int i = 0; i < 4; i++)
		    {
			bordure.at(i) = new Bordure();
		    }

		    // init les bordures
		    bordure[0]->set_bordure_fils(1, Noeud::PLAINE);

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
		    std::list<Element *> elementTuile;
		    Element * element1 = new Element(Noeud::PLAINE);
		    Element * element2 = new Element(Noeud::ROUTE);
		    Element * element3 = new Element(Noeud::PLAINE);
		    Element * element4 = new Element(Noeud::ROUTE);
		    Element * element5 = new Element(Noeud::PLAINE);
		    Element * element6 = new Element(Noeud::ROUTE);

		    // init les voisins
		    // bordure:
		    bordure[0]->get_bordure_fils(1)->set_voisin(element1);

		    bordure[1]->get_bordure_fils(0)->set_voisin(element1);
		    bordure[1]->get_bordure_fils(1)->set_voisin(element2);
		    bordure[1]->get_bordure_fils(2)->set_voisin(element3);

		    bordure[2]->get_bordure_fils(0)->set_voisin(element3);
		    bordure[2]->get_bordure_fils(1)->set_voisin(element4);
		    bordure[2]->get_bordure_fils(2)->set_voisin(element5);

		    bordure[3]->get_bordure_fils(0)->set_voisin(element5);
		    bordure[3]->get_bordure_fils(1)->set_voisin(element6);
		    bordure[3]->get_bordure_fils(2)->set_voisin(element1);

		    // element:
		    element1->set_voisin(bordure[0]->get_bordure_fils(1));
		    element1->set_voisin(bordure[1]->get_bordure_fils(0));
		    element1->set_voisin(bordure[3]->get_bordure_fils(2));

		    element2->set_voisin(bordure[1]->get_bordure_fils(1));

		    element3->set_voisin(bordure[1]->get_bordure_fils(2));
		    element3->set_voisin(bordure[2]->get_bordure_fils(1));

		    element4->set_voisin(bordure[2]->get_bordure_fils(1));

		    element5->set_voisin(bordure[2]->get_bordure_fils(2));
		    element5->set_voisin(bordure[3]->get_bordure_fils(0));

		    element6->set_voisin(bordure[1]->get_bordure_fils(1));

		    // Ajout des liens additionelles
			// Aucun

		    // Ajout element dans la liste
		    elementTuile.push_back(element1);
		    elementTuile.push_back(element2);
		    elementTuile.push_back(element3);
		    elementTuile.push_back(element4);
		    elementTuile.push_back(element5);
		    elementTuile.push_back(element6);

		    // Creation de la carte
		    Tuile * carte = new Tuile(carteVoisines, bordure, elementTuile);

		    // Ajout de la carte dans le pioche
		    this->pioche.push_back(carte); // front pour la première carte
		}
	}
    }

    // Tuile 24 (x1)
    {
        for(int i = 0; i < 4; i++){
            
            std::array<Bordure *, 4> bordure;
            std::list<Element *> element;

            // init les cartes
            for(int i = 0; i < 4; i++)
            {
                carteVoisines[i] = nullptr;
            }

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
            std::list<Element *> elementTuile;
            Element * element1 = new Element(Noeud::ROUTE);
            Element * element2 = new Element(Noeud::PLAINE);
            Element * element3 = new Element(Noeud::ROUTE);
            Element * element4 = new Element(Noeud::PLAINE);
            Element * element5 = new Element(Noeud::ROUTE);
            Element * element6 = new Element(Noeud::PLAINE);
            Element * element7 = new Element(Noeud::ROUTE);
            Element * element8 = new Element(Noeud::PLAINE);

            // init les voisins
            // bordure:
            bordure[0]->get_bordure_fils(0)->set_voisin(element8);
            bordure[0]->get_bordure_fils(1)->set_voisin(element1);
            bordure[0]->get_bordure_fils(2)->set_voisin(element2);

            bordure[1]->get_bordure_fils(0)->set_voisin(element2);
            bordure[1]->get_bordure_fils(1)->set_voisin(element3);
            bordure[1]->get_bordure_fils(2)->set_voisin(element4);

            bordure[2]->get_bordure_fils(0)->set_voisin(element4);
            bordure[2]->get_bordure_fils(1)->set_voisin(element5);
            bordure[2]->get_bordure_fils(2)->set_voisin(element6);

            bordure[3]->get_bordure_fils(0)->set_voisin(element6);
            bordure[3]->get_bordure_fils(1)->set_voisin(element7);
            bordure[3]->get_bordure_fils(2)->set_voisin(element8);

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
	    
	    // Ajout element dans la liste
            elementTuile.push_back(element1);
            elementTuile.push_back(element2);
            elementTuile.push_back(element3);
            elementTuile.push_back(element4);
            elementTuile.push_back(element5);
            elementTuile.push_back(element6);
            elementTuile.push_back(element7);
            elementTuile.push_back(element8);

            // Creation de la carte
            Tuile * carte = new Tuile(carteVoisines, bordure, elementTuile);

            // Ajout de la carte dans le pioche
            this->pioche.push_back(carte); // front pour la première carte
        }
    }

    grille[NBR_TUILES-1][NBR_TUILES-1] = pioche[0];
    pioche.erase(0);
}

void Plateau::ajouter_joueur(Joueur * joueur, Pion * pion)
{
    this->mapJoueursPions.insert(std::pair<Joueur *, Pion *>(joueur, pion));
}

Joueur * Plateau::get_joueur()
{
    return NULL;
}

std::list<Tuile *> Plateau::get_pioche()
{
    return this->pioche;
}

Tuile *Plateau::piocher_tuile()
{
	int random = rand() % pioche.size();
	Tuile tmp = pioche[random];

	pioche.erase(random);

    return tmp;
}

void Plateau::clear_liste_tuiles_emplacements_libres()
{
    this->liste_tuiles_emplacements_libres.clear();
}

std::vector<Tuile> Plateau::calcul_emplacement_libre(Tuile *tuile)
{
	// Calcul des emplacements libres

    for(int i = 0; i < NBR_TUILES; i++)
	{
		for(int j = 0; i < NBR_TUILES; i++)
		{
			if(grille[i][j] != NULL)
			{
				if()
				{

				}

				if()
				{
					
				}

				if()
				{
					
				}

				if()
				{
					
				}
			}
		}
	}

	// Calcul des orientations
}

void Plateau::poser_tuile(Tuile *tuile_pioche, Tuile *tuile_emplacement, std::list<Bordure *> bordure)
{

}

Joueur * Plateau::joueur_suivant()
{
    return NULL;
}

/**
 * Recherche le Joueur qui à obtenue le plus de pions.
 *
 * @param mapJoueurListeMeeple Joueur associé à une liste de Meeple
 * */
Joueur * Plateau::rechercher_Joueur_plus_de_Pions(std::map<Joueur*, std::list<Meeple *>> mapJoueurListeMeeple)
{
    return NULL;
}

/**
 * Désindexe les Meeples du plateau.
 *
 * @param mapJoueurListeMeeple Joueur associé à une liste de Meeple */
void Plateau::desindexer_Meeple_dans_la_map(std::map<Joueur*, std::list<Meeple *>> mapJoueurListeMeeple)
{

}


/**
 * Evaluation des Meeples pour chaque Joueurs
 *
 * Cette méthode permet d'à partir de chaque Meeple des Joueurs d'évaluer s'il y a possibilité d'attribuer des points aux Joueurs
 * L'évaluation s'effectue sur tous les Meeples et les points sont distribuée selon la quantité de Meeple obtenu (pour l'évalation concurrencielle, ce n'est pas le cas pour les abbayes par exemple)
 *
 * @param status_du_jeu permet de faire une évaluation soit final soit en cours du jeu
 * */
void Plateau::evaluer_meeple(int status_du_jeu)
{
    for(auto const &itMap : this->mapJoueursPions)
    {
        const std::list<Meeple *> listMeeple = itMap.second->get_stack_meeple();

        for(auto const &itMeeple : listMeeple)
        {
            int score = 0;
            std::map<Joueur *, std::list<Meeple *>> mapJoueurListeMeeple;
            int est_complet = itMeeple->compter_points(status_du_jeu, mapJoueurListeMeeple, &score);

            if(est_complet == true || status_du_jeu )
            {
                Joueur * joueur = this->rechercher_Joueur_plus_de_Pions(mapJoueurListeMeeple);
                joueur->ajouter_points(score);
                this->desindexer_Meeple_dans_la_map(mapJoueurListeMeeple);
            }
        }
    }
}

std::list<Joueur *> Plateau::get_joueur_liste()
{
    return this->list_joueur;
}

std::vector<Tuile *> Plateau::get_liste_tuiles_emplacements_libres()
{
    return this->liste_tuiles_emplacements_libres;
}

std::vector<std::list<Bordure *>> Plateau::get_orientation_possible(Tuile *tuile)
{
    std::vector<std::list<Bordure *>> list_vide;

    return list_vide;
}


bool Plateau::stack_meeple_vide(Joueur * joueur)
{
    return true;
}

void Plateau::poser_meeple(Joueur * joueur, Element * element, Tuile * tuile)
{
    Meeple * meeple = Pion::generate_meeple(joueur, element, tuile);
    element->ajouter_meeple(meeple);
    Pion * pion = this->mapJoueursPions.find(joueur)->second;
    pion->ajouter_meeple(meeple);
}
