# chaine_markov
manipulation de chaine de Markov

# Projet de Chaîne de Markov et Manipulation de Table de Hachage

Ce projet met en avant la manipulation de chaînes de Markov en utilisant efficacement des tables de hachage pour le stockage des états et la gestion de l'espace mémoire. 

## Détails du Projet

### Utilisation de la table de hachage

L'utilisation d'une table de hachage permet de stocker et de manipuler les états de manière très efficace. La complexité temporelle des opérations de recherche, d'ajout et de suppression est généralement en O(1), ce qui rend l'implémentation très rapide. De plus, la table de hachage permet de gérer facilement un grand nombre d'états sans utiliser beaucoup de mémoire.

### Efficacité en termes d'espace mémoire

La solution utilise des structures de données appropriées pour minimiser l'utilisation de la mémoire. Les poids entre les états sont stockés sous forme de table de hachage, ce qui permet d'éviter de stocker des poids nuls et de gérer efficacement les chaînes de Markov de grande taille.

## Utilisation de la bibliothèque uthash

La bibliothèque uthash est une bibliothèque open source en C pour la manipulation de tables de hachage. Elle est très légère et facile à intégrer dans votre projet. Vous pouvez la trouver sur le dépôt GitHub officiel : [https://github.com/troydhanson/uthash](https://github.com/troydhanson/uthash)

Pour l'utiliser, il vous suffit de télécharger le fichier "uthash.h" à partir du dépôt et de l'inclure dans votre projet en ajoutant `#include "uthash.h"` en haut de votre fichier source. La bibliothèque uthash offre des fonctions pour ajouter, supprimer, mettre à jour et rechercher des éléments dans une table de hachage.

Dans la solution proposée, uthash est utilisé pour stocker les poids entre les états de la chaîne de Markov.

### Fonctions de la bibliothèque uthash utilisées

1. **`HASH_FIND_INT(head, findint, out)`**: Cette fonction recherche un élément dans une table de hachage avec une clé entière. `head` est le pointeur vers la table de hachage, `findint` est l'entier à rechercher et `out` est un pointeur vers l'élément trouvé (s'il existe). Si aucun élément n'est trouvé, `out` sera `NULL`.
2. **`HASH_ADD_INT(head, intfield, add)`**: Cette fonction ajoute un élément à une table de hachage avec une clé entière. `head` est le pointeur vers la table de hachage, `intfield` est le nom du champ entier dans la structure utilisée comme clé, et `add` est le pointeur vers l'élément à ajouter.
3. **`HASH_DEL(head, deletee)`**: Cette fonction supprime un élément d'une table de hachage. `head` est le pointeur vers la table de hachage et `deletee` est le pointeur vers l'élément à supprimer.
4. **`HASH_ITER(hh, head, elt, tmp)`**: Cette macro permet d'itérer sur tous les éléments d'une table de hachage. `hh` est le nom du champ `UT_hash_handle` dans la structure, `head` est le pointeur vers la table de hachage, `elt` est un pointeur vers l'élément courant de l'itération et `tmp` est un pointeur temporaire utilisé pour l'itération.

Ces fonctions sont utilisées pour gérer les tables de hachage qui stockent les poids des transitions entre les états dans la chaîne de Markov.

## Execution

Pour compiler et exécuter le projet, utilisez la commande suivante :

```bash
gcc -Wall -o markov_test src/markov.c main.c
