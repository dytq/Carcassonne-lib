// LIBRAIRIES
#include "IA.hpp"

// FONCTIONS
IA::IA()
{

}

IA::~IA()
{}

resultatIA IA::jouerCoupAleatoire(std::vector<std::array<int, 3>> liste_tuiles_emplacements_libres)
{
	resultatIA RIA;
	/*
	srand(time(0));

	RIA.coupOptimal = rand() % liste_tuiles_emplacements_libres.size();
	RIA.poserMeeple = rand() % 2;
	RIA.positionMeeple = rand() % /*nombre d'éléments dans la tuile choisie;
	*/
	return RIA;
}

resultatIA IA::jouerCoup(std::vector<std::array<int, 3>> liste_tuiles_emplacements_libres)
{

	resultatIA RIA;
	/*
	int scoreCoupOptimal;

	RIA.coupOptimal = 0;

	for(int i = 0; i < liste_tuiles_emplacements_libres.size(); i++)
	{
		if(/*calculer score avec et sans pose de meeple et positions > scoreCoupOptimal)
		{
			RIA.coupOptimal = i;
			scoreCoupOptimal = /*calculer scoreCoupOptimal;
		}
	}
	*/
	return RIA;
}