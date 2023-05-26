#include"repertoire.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


iterateurRepertoire_t *iterateurRepertoire(char *nomFichier){
    
    iterateurRepertoire_t* it = malloc(sizeof(iterateurRepertoire_t));
    it->fichier = fopen(nomFichier, "r");
    it->mot = malloc(sizeof(char)*100);
    it->finPhrase = 0;
    
    return it;
    
}


char* motSuivant(iterateurRepertoire_t* it) {
    int i = 0;
    char c;
    while ((c = fgetc(it->fichier)) != EOF) {
        if (isalpha(c)) {
            it->mot[i] = tolower(c);
            i++;
        } else if (c == '.' || c == '?' || c == '!') {
            it->finPhrase = 1;
            if (i > 0) { 
                it->mot[i] = '\0'; 
                return it->mot;
            }

        } else if (i > 0) { 
            it->mot[i] = '\0';
            it->finPhrase = 0;
            return it->mot;
        }
        if(c == '.' || c == '?'|| c == '!') {
            printf("\n");
        }
    }

    return NULL;
}



