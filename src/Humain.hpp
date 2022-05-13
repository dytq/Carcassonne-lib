#ifndef HUMAIN_HPP
#define HUMAIN_HPP

#include <iostream>
#include <string>

#include "Joueur.hpp"

class Humain : public Joueur
{
    public:
        Humain();
        int choix_de_emplacement_libre() override;
        bool choix_si_poser_meeple() override;
        int choix_de_element_libre() override; 
};
#endif // HUMAIN_HPP
