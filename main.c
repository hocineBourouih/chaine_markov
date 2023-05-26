#include<stdio.h>
#include<stdlib.h>
#include"src/hachage.h"
#include"src/markov.h"
#include"src/repertoire.h"

int main(int argc, char *argv[])
{
    // pour executer : gcc -Wall -o markov_test src/markov.c main.c

    // Création de la chaîne de Markov
    markov_t *chaine = markovCreation(42);

    // Ajout des états
    markovAjoutEtat(chaine, 0);
    markovAjoutEtat(chaine, 1);
    markovAjoutEtat(chaine, 2);

    // Incrémentation des poids
    markovIncrementPoid(chaine, 0, 1);
    markovIncrementPoid(chaine, 0, 2);
    markovIncrementPoid(chaine, 1, 0);
    markovIncrementPoid(chaine, 1, 2);
    markovIncrementPoid(chaine, 2, 0);
    markovIncrementPoid(chaine, 2, 1);

    // Affichage des probabilités de transition
    printf("P(0 -> 1) = %f\n", markovTransitionProba(chaine, 0, 1));
    printf("P(0 -> 2) = %f\n", markovTransitionProba(chaine, 0, 2));
    printf("P(1 -> 0) = %f\n", markovTransitionProba(chaine, 1, 0));
    printf("P(1 -> 2) = %f\n", markovTransitionProba(chaine, 1, 2));
    printf("P(2 -> 0) = %f\n", markovTransitionProba(chaine, 2, 0));
    printf("P(2 -> 1) = %f\n", markovTransitionProba(chaine, 2, 1));

    // Simulation d'une séquence d'états
    int etat_actuel = 0;
    printf("Séquence d'états : ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", etat_actuel);
        etat_actuel = markovAleaEtatSuivant(chaine, etat_actuel);
    }
    printf("\n");

    // Destruction de la chaîne de Markov
    markovDetruire(chaine);

    printf("C'est tout???\n");

    return EXIT_SUCCESS;
}