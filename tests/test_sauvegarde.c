#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<assert.h>
#include"../src/sauvegarde.h"


void creerFichierTest();
void ajoutFichierTest();
void ecrireFichierTest();


int main(int argc, char *argv[])
{
  creerFichierTest();
  ajoutFichierTest();
  ecrireFichierTest();
  return EXIT_SUCCESS;
}





void creerFichierTest() {
  creerFichier("Texte", "./fichierA");
  assert(access("fichierA", F_OK) != -1);
  system("rm ./fichierA");
}





void ajoutFichierTest() {
  char *texte = "Texte";

  creerFichier(texte, "./fichierB");
  FILE *fichier = ajoutFichier("./fichierB");
  
  char *readText = (char*) malloc(100);
  fgets(readText, 100, fichier);

  assert(fichier != 0);
  assert(strcmp(readText, texte) == 0);

  system("rm ./fichierB");
}




void ecrireFichierTest() {
  creerFichier("", "./fichierC");
  FILE *fichier = ajoutFichier("./fichierC");
  ecrireFichier(fichier, "Texte");

  char *readText = (char*) malloc(100);
  fgets(readText, 100, fichier);

  assert(fichier != 0);
  assert(strcmp(readText, "Texte") == 0);

  free(readText);
  system("rm ./fichierC");
}