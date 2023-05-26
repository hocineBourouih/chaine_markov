#include<stdlib.h>
#include<assert.h>
#include"../src/repertoire.h"

void iterateurRepertoireTest();
void motSuivantTest();

iterateurRepertoire_t* save;

int main(int argc, char *argv[])
{
  iterateurRepertoireTest();
  motSuivantTest();
  return EXIT_SUCCESS;
}

void iterateurRepertoireTest() {
  iterateurRepertoire_t *iter;
  iter = iterateurRepertoire("dataset/stendhal.txt");
  assert(iter != NULL);

  save = iter;
}

void motSuivantTest() {
  assert(strcmp(motSuivant(save), "chapitre") == 0);
}