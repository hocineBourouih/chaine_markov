#include "uthash.h" //  bibliothèque open source en C pour la manipulation de tables de hachage (dispo sur git)

/**
Fichier markov.h
Auteur(s): Hocine Bourouih 22111414   
*/
#ifndef __MARKOV_H__
#define __MARKOV_H__

// Vous travaillerez ici

// type markov_t
typedef struct markov_t markov_t;


/*
// Crée une nouvelle chaîne de Markov 
//initialise le générateur de nombres aléa avec la valeurinitiale donnée
// @param valeur_initiale: graine pour le générateur de nombres aléatoires
// @return: un pointeur vers la nouvelle chaine de Markov
// @ensures : le resultat ne sera pas NULl
*/
markov_t *markovCreation(unsigned int valeur_initiale);


/*
// Detruis la chain de Markov et libre la mémoire alloué
// @param chain: un pointeur vers la chaîne de Markov à effacer
// @requires: une chaine de markov non null (chain != NULL)
*/
void markovDetruire(markov_t *chain);


/*
// Ajoute un nouvel etat à la chane de Markov
// @param chain: un pointeur vers la chaîne de Markov
// @param etat: l'état à ajouter
// @requires: une chaine non vide (chain != NULL)
*/
void markovAjoutEtat(markov_t *chain, int etat);


/*
// Incrmente le poids de la transition entre deux etats dans la chaîne
// @param chain: un pointeur vers la chaîne de Markov
// @param etat1 : l'état de départ
// @param etat2: l'état d'arrivé
// @requires: une chaine non vide (chain != NULL)
*/
void markovIncrementPoid(markov_t *chain, int etat1, int etat2);


/*
// Calcule la probabilite de transition entre deux etats 
// @param chain: un pointeur vers la chaine
// @param etat1: l'état de départ
// @param etat2: l'état d'arrive
// @return: la probabilité de transition entre les deux etat
// @requires: chain != NULL
// @ensures: la probabilité égale entre 0 et 1 (0 <= resultat <= 1.0)
*/
double markovTransitionProba(markov_t *chain, int etat1, int etat2);


/*
// Sélectionne aléatoirement un état suivant en fonction des probabilités de transition à partir de l'état actuel
// @param chain: un pointeur vers la chaîne de Markov
// @param etat_actuel: l'état actuel
// @return: l'état suivant sélectionné aléatoirement
// @requires: chain != NULL
*/
int markovAleaEtatSuivant(markov_t *chain, int etat_actuel);



#endif
