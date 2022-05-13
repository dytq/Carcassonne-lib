// LIBRAIRIES
#include "Paysan.hpp"

// FONCTIONS
/**
 * @title: Constructeur Payson 
 *
 * @param Joueur
 * @param Noeud
 * */
Paysan::Paysan(Joueur * joueur, Noeud * noeud)
{
    Meeple::joueur = joueur;
    Meeple::noeud = noeud;
}

/**
 * @title: Algorithme qui permet de vérifié si une ville marqué est complète.
 * 
 * @description: 
 * On execute ce code quand on arrive à un noeud ville.
 * Une fois entrée on ne peut plus resortir, on peut donc évalué est chercher si il y a des valeurs nulle.
 * - Si ce n'est pas le cas  on retourne le nombre de points obtenu.
 *
 * @param la liste des villes marqué
 * @param le noeuds courant
 * */
bool est_complet_ville(std::list<Noeud*> * ville_marque, Noeud * noeud_courant, bool etat_complet)
{
    if(noeud_courant == nullptr) 
    {
        return false;
    }

    int i;
    for(i = 0; i <  noeud_courant->get_nbr_voisins(); i++)
    {
        Noeud * noeud_voisin = noeud_courant->get_voisin(i);
        if(noeud_voisin == nullptr) 
        {
            etat_complet = false;
        }
        Logging::log(Logging::TRACE, "parcours ville %d", noeud_voisin);
        if(std::find(ville_marque->begin(), ville_marque->end(), noeud_voisin) == ville_marque->end())
        {
            ville_marque->push_back(noeud_voisin);
            etat_complet = est_complet_ville(ville_marque, noeud_voisin, etat_complet);
        }
    }
    return etat_complet;
}

/**
 * @title: Algorithme de comptage pour un Paysan
 *
 * @description: 
 * On fait un parcours en profondeur du réseau:
 * - Si on a un près alors on fait les vérifications necessaire (si il y un meeple on l'ajoute dans la map Joueur/Meeple)
 * - Si on a une ville:
 *  - On regarde si elle a été traité,
 *  - Si oui on passe au noeud suivant
 *  - Sinon on regarde si c'est une ville complète et on ajoute les points
 *
 * @param: status_du_jeu est pour déterminer le nombre de points de chaque noeud
 * @param: mapJoueurListeMeeple pour savoir combien de meeple à t'on récolté pour chaque joueur
 * @param: *score est le score de chaque ville complète rencontré
 * */
bool Paysan::compter_points(int status_du_jeu, std::map<Joueur *, std::list<Meeple *>> * mapJoueurListeMeeple, int *score)
{
    bool est_complete = true;
    
    if(status_du_jeu == STATUS_EN_COURS)
    {
        est_complete = false;
    }

    std::list<Noeud*> pileNoeud;            // pile pour le parcours des fils
    std::list<Noeud*> noeudMarque;          // marque tous les noeuds rencontrés
    std::list<Noeud *> noeud_ville_marque;  // ville marque 

    *score = this->noeud->get_points(status_du_jeu);
    Element * element_noeud = dynamic_cast<Element *>(this->noeud);
    mapJoueurListeMeeple->insert(std::pair<Joueur *, std::list<Meeple *>>(this->joueur, {element_noeud->get_meeple()}));

    
    pileNoeud.push_back(this->noeud);
    noeudMarque.push_back(this->noeud);
        
    while(!pileNoeud.empty())
    {
        std::list<Noeud*>::iterator iterNoeud = pileNoeud.begin();

        Noeud * noeudCentrale = *iterNoeud;

        //Logging::log(Logging::TRACE, "Evaluation d'un noeud %d", noeudCentrale);
        
        Element * element = dynamic_cast<Element *>(noeudCentrale);
        if(element != nullptr)
        {
            if(noeudCentrale != noeud)
            {
                Meeple * meeple = element->get_meeple();
                if(meeple != nullptr) 
                {
                    Logging::log(Logging::DEBUG, "meeple paysan trouvé %d %d", meeple->get_noeud()->get_type_element());
                    Joueur * joueur = meeple->get_joueur();
                    if(!mapJoueurListeMeeple->count(joueur)) 
                    {
                        mapJoueurListeMeeple->insert(std::pair<Joueur *, std::list<Meeple *>>(joueur, {meeple}));
                    }
                    else 
                    {
                        mapJoueurListeMeeple->at(joueur).push_back(meeple);
                    }
                    break;
                }
            }
        } 


        pileNoeud.pop_front();

        int i;
    
        for(i = 0; i < noeudCentrale->get_nbr_voisins(); i++)
        {
            Noeud * noeud_fils = noeudCentrale->get_voisin(i);
            //Logging::log(Logging::TRACE, "Noeud fils %d %d", i, noeud_fils);           

            if(noeud_fils != nullptr) 
            {
                if(noeud_fils->get_type_element() == Noeud::VILLE || noeud_fils->get_type_element() == Noeud::VILLE_BLASON)
                {
                    if(noeud_ville_marque.end() == std::find(noeud_ville_marque.begin(), noeud_ville_marque.end(), noeud_fils))
                    {
                        Logging::log(Logging::TRACE, "noeud ville");
                        noeud_ville_marque.push_back(noeud_fils);
                        noeudMarque.push_back(noeud_fils);
                        if(est_complet_ville(&noeud_ville_marque, noeud_fils,true))
                        {
                            Logging::log(Logging::TRACE, "Ville complète trouvée");
                            *score = *score + POINTS_PAYSANS;
                        } 
                        else
                        {
                            Logging::log(Logging::TRACE, "Ville non complète");
                        }
                    }
                } 
                else 
                {
                    Logging::log(Logging::TRACE, "Noeud fils %d est non null", i);
                    if(noeudMarque.end() == std::find(noeudMarque.begin(), noeudMarque.end(), noeud_fils))
                    {
                        Logging::log(Logging::TRACE, "Noeud fils %d n'est pas marqué", i);
                        pileNoeud.push_back(noeud_fils);
                        noeudMarque.push_back(noeud_fils);
                    } else {
                        Logging::log(Logging::TRACE, "Noeud fils %d est déjà marqué", i);
                    }
                }
            }
        }
    }
    return est_complete;
}
