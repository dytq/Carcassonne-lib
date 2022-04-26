// LIBRAIRIES
#include "Chevalier.hpp"

// FONCTIONS
Chevalier::Chevalier(Joueur * joueur, Noeud * noeud)
{
    Meeple::joueur = joueur;
    Meeple::noeud = noeud;
}

Chevalier::~Chevalier()
{}

/**
 * Algorithme du comptage des points pour le Chevalier.
 *
 * Parcours du réseau de noeuds en profondeur.
 **/
bool Chevalier::compter_points(int status_du_jeu, std::map<Joueur *, std::list<Meeple *>> * mapJoueurListeMeeple, int * score)
{
    std::list<Noeud*> pileNoeud;   // pile pour le parcours des fils
    std::list<Noeud*> noeudMarque; // marque tous les noeuds rencontrés

    bool isComplete = true;

    *score = this->noeud->get_points(status_du_jeu);
    pileNoeud.push_back(this->noeud);
    noeudMarque.push_back(this->noeud);
   
    while(!pileNoeud.empty())
    {
        std::list<Noeud*>::iterator iterNoeud = pileNoeud.begin();

        Noeud * noeudCentrale = *iterNoeud;
       
        Element * element = dynamic_cast<Element *>(noeudCentrale);
        if(element != nullptr)
        {
            if(noeudCentrale != noeud)
            {
                Meeple * meeple = element->get_meeple();
                if(meeple != nullptr) 
                {
                    Logging::log(Logging::TRACE, "Meeple trouvé");
                    Joueur * joueur = meeple->get_joueur();
                    mapJoueurListeMeeple->at(joueur).push_back(meeple);
                    break;
                }
            }
            
        }
        
        Logging::log(Logging::TRACE, "Evaluation d'un noeud %d", noeudCentrale);
        
        pileNoeud.pop_front();

        int i;
    
        for(i = 0; i < noeudCentrale->get_nbr_voisins(); i++)
        {
            Noeud * noeud_fils = noeudCentrale->get_voisin(i);
            Logging::log(Logging::TRACE, "Noeud fils %d %d", i, noeud_fils);
            
            if(noeud_fils == nullptr) 
            {
                Logging::log(Logging::TRACE, "Noeud fils %d est null", i);
                isComplete = false;
            } 
            else 
            {
                Logging::log(Logging::TRACE, "Noeud fils %d est non null", i);
                if(noeudMarque.end() == std::find(noeudMarque.begin(), noeudMarque.end(), noeud_fils))
                {
                    Logging::log(Logging::TRACE, "Noeud fils %d n'est pas marqué", i);
                    *score += noeud_fils->get_points(status_du_jeu);
                    pileNoeud.push_back(noeud_fils);
                    noeudMarque.push_back(noeud_fils);
                } else {
                    Logging::log(Logging::TRACE, "Noeud fils %d est déjà marqué", i);
                }
            }
        }
    }
    
    return isComplete;
}
