#ifndef NOEUDVOISIN_HPP
#define NOEUDVOISIN_HPP

#include <map>
#include <vector>

class NoeudVoisin
{
    private: 
          static std::map<NoeudVoisin*, std::vector<NoeudVoisin *>> noeuds_plateau; 
    public: 
      
        static void ajouter_noeud(NoeudVoisin * noeud) 
        {
            noeuds_plateau.insert({noeud, std::vector<NoeudVoisin *> ()});
        }
        static std::map<NoeudVoisin *, std::vector<NoeudVoisin *>> * get_noeud_plateau()
        {
            return &noeuds_plateau;
        }
};

#endif