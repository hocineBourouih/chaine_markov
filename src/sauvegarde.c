#include"sauvegarde.h"
#include <stdio.h>

void creerFichier(char* texte, char* chemin){

    FILE* fichier = NULL;
    fichier = fopen(chemin, "w");

    if (fichier != NULL){
        fputs(texte, fichier);
        fclose(fichier);
    }

    else{
        printf("Impossible de creer le fichier");
    }
}


FILE* ajoutFichier(char* chemin){
    
    FILE* fichier = NULL;
    fichier = fopen(chemin,"a");
    
    if (fichier != NULL){
        return fichier;
    }
    else{
        printf("Impossible de lire ou d'ouvrir le fichier");
    }
    
    return 0;
    
}


void ecrireFichier(FILE* fichier, char* texte){

    if (fichier != NULL){
        fputs(texte, fichier);
        fclose(fichier);
    }

    else{
        printf("Impossible d'ecrire le texte sur le fichier");
    }
}