#include <stdio.h>

#ifndef __SAUVEGARDE_H__
#define __SAUVEGARDE_H__

// Vous travaillerez ici


/**
 * Creer un fichier au chemin donné, contenant le texte passé en entrée.
 * @param texte : Le texte à ecrire en entrée.
 * @param chemin : Le chemin du fichier à créer.
 * @requires fichier != NULL
 * @ensures un fichier est créé au chemin donné, contenant le texte passé en entrée.
*/

void creerFichier(char* texte, char* chemin);

/**
 * Ouvre un fichier en mode "ajout" ou concatenation et renvoie le descripteur de fichier
 * @param chemin : Le chemin du fichier à créer.
 * @requires fichier != NULL
 * @ensures un fichier en mode "ajout" ou concatenation et renvoie le descripteur de fichier
*/

FILE* ajoutFichier(char* chemin);


/**
 * écrit la chaine de caractère dans le fichier
 * @param fichier : Le fichier en entrée
 * @param texte : Le texte à ecrire en entrée.
 * @requires fichier != NULL
 * @ensures écrit la chaine de caractère dans le fichier
*/

void ecrireFichier(FILE* fichier, char* texte);

#endif

