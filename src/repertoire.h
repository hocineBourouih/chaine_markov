#include <stdio.h>

#ifndef __REPERTOIRE_H__
#define __REPERTOIRE_H__

#include <stdbool.h>
#include <stdio.h>
// Vous travaillerez ici

/**
* Structure de données permettant de parcourir un fichier texte
* @param fichier : pointeur vers le fichier à parcourir
* @param mot : pointeur vers le mot courant
* @param finPhrase : 1 si le mot courant est le dernier d'une phrase, 0 sinon
*/

typedef struct {
  FILE *fichier;
  char *mot;
  int finPhrase;
} iterateurRepertoire_t;


/**
 * Crée un itérateur permettant de parcourir un fichier texte
 * @param nomFichier : le nom du fichier à parcourir
 * @requires nomFichier != NULL
 * @ensures un itérateur est créé permettant de parcourir le fichier texte
 */

iterateurRepertoire_t *iterateurRepertoire(char *nomFichier);

/**
 * Renvoie le mot suivant du fichier texte
 * @param it : l'itérateur permettant de parcourir le fichier texte
 * @requires it != NULL
 * @ensures le mot suivant du fichier texte est renvoyé
 * @return le mot suivant du fichier texte
*/

char *motSuivant(iterateurRepertoire_t *it);



#endif
