// LIBRAIRIES
#include "Chevalier.hpp"

// FONCTIONS
/**
 * @title: Constructeur du Chevalier
 *
 * @param: Joueur est le joueur
 * @param: Noeud est le noeud ou se trouve le chevalier
 * */
Chevalier::Chevalier(Joueur * joueur, Noeud * noeud)
{
    Meeple::joueur = joueur;
    Meeple::noeud = noeud;
}

Chevalier::~Chevalier()
{}

/**
 * @title: Algorithme du comptage des points pour le Chevalier.
 *
 * @description: Parcours du réseau de noeuds en profondeur.
 * 
 * @param: status_du_jeu est l'état du jeu (si fin ou en cour de jeu.
 * @param: mapJoueurListeMeeple permet de savoir combien de meeple à récolté chaque joueur.
 * @param: *score est le score obtenu dans l'évalutation de la zone.
 **/
bool Chevalier::compter_points(int status_du_jeu, std::map<Joueur *, std::list<Meeple *>> * mapJoueurListeMeeple, int * score)
{
    std::list<Noeud*> pileNoeud;   // pile pour le parcours des fils
    std::list<Noeud*> noeudMarque; // marque tous les noeuds rencontrés

    bool isComplete = true;

    *score = this->noeud->get_points(status_du_jeu);
    Element * element_noeud = dynamic_cast<Element *>(this->noeud);
    mapJoueurListeMeeple->insert(std::pair<Joueur *, std::list<Meeple *>>(this->joueur, {element_noeud->get_meeple()}));
    //mapJoueurListeMeeple->at(this->joueur).push_back(element_noeud->get_meeple());
    
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
                    Logging::log(Logging::DEBUG, "meeple brigand trouvé %d %d", meeple->get_noeud()->get_type_element());
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
