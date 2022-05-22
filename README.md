# Carcassonne-lib
Programmation du jeu "Carcassonnne" à deux et d'une IA capable d'y jouer

Contributeurs :
- BARBIER Yann 21800844
- DEDARALLY Taariq
- CONOR Marine


Concernant les commandes ci-dessous, il faut d'abord ouvrir une console dans le répertoire de ce README.
Malheureusement, certaines manipulations sont nécessaires pour lancer l'interface graphique du jeu sous Godot. Nous présentons ici des étapes pour lancer le jeu par ligne de commande.

Pour modifier les types de joueurs, se situer dans le main et choisir lors de la sélection des joueurs au choix :
::HUMAIN
::ALEAT
::MINIMAX

Pour compiler et exécuter le programme :
```bash
	make
```

Pour nettoyer le projet des fichiers temporaires :
```bash
	make clean
```

Pour générer l'étude de performance à la fin d'une partie :
R CMD BATCH study.R
