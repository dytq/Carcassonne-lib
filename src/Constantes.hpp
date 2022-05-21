// DIRECTIVES
#ifndef CONSTANTES_HPP
#define CONSTANTES_HPP

/* Constantes vanilla */
#define NBR_TUILES   72
#define NBR_TYPES_TUILES	24
#define NBR_ORIENTATIONS_TUILES	4
#define NBR_MEEPLE   7

// Points
// Evaluation des points en cours de jeu
#define POINTS_VILLE_COMPLET   2
#define POINTS_VILLE_BLASON_COMPLET   4
#define POINTS_ROUTE_COMPLET   1
#define POINTS_ABBAYE_COMPLET   9

// Evaluation des points en fin de jeu
#define POINTS_VILLE_INCOMPLET   1
#define POINTS_VILLE_BLASON_INCOMPLET   2
#define POINTS_ROUTE_INCOMPLET   1
#define POINTS_ABBAYE_INCOMPLET   1
#define POINTS_PAYSANS   3

/* ------------------ */

/* Constantes extentions */
#define NBR_TUILES_EXTENSIONS_RIVIERE   12
#define NBR_ABBES 5

/* --------------------- */

#define STATUS_EN_COURS 1
#define STATUS_FINAL 0

/* Debug: choisir le type de message à afficher */
#define ALL_MSG      // Tous les messages 

#ifdef ALL_MSG
#define CRITICAL_MSG // Permet de journaliser quand le programme échoue 
#define DEBUG_MSG    // Permet de journaliser quand il y a une erreur qui n'échoue pas le programme
#define TRACE_MSG    // Permet de tracer le déroulement de la partie
#endif // ALL_MSG

/* -------------------------------------------- */

#endif // CONSTANTES_HPP
