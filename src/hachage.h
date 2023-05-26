#ifndef __HACHAGE_H__
#define __HACHAGE_H__

// Vous travaillerez ici



/**
 * Une table de hachage est une structure de donnée associant à chaque clé une valeur
 * stocké.
 * La clé permet de calculer l'adresse de la valeur stocké grâce à son hachage.
 * Ex: soit M un tableau associatif avec les clés et valeurs des chaines de caractère,
 * alors hash(clé)%(taille des cases alloués par M) donnera l'adresse de la valeur associé
 * à celle-ci.
 * 
 * Il est très peu probable que deux clés différentes aient le même hash, mais il
 * est courant que leur modulo soit de le même nombre, et donc qu'elles pointes sur la
 * même adresse.
 * C'est pour cela qu'en pratique, on utilise des listes chainées pour gérer les collisions
 * (appelés buckets)
*/

// MANIPULATION DES BUCKETS

/**
 * Valeurs contenues dans les buckets;
*/
typedef char* cle_t;
typedef int valeur_t;

/**
 * La structure pair_t sera stocké directement par les buckets.
*/
typedef struct pair_s {
    cle_t key;
    valeur_t value;
} pair_t;

/**
 * Le type bucket_t est une liste simplement chainée contenant une paire clé-valeur.
*/
struct bucket_s {
    pair_t pair;
    struct bucket_s* next;
};
typedef struct bucket_s bucket_t;

/**
 * Permet de crée, de modifier ou d'étendre un bucket par la fin.
 * Complexité : O(n)
 * @requires bucket == NULL || bucket == (bucket existant)
 * @requires key != NULL
 * @requires value != -1
 * @ensures paire (key, value) élément du bucket
 * @ensures paire (key, old_value) n'est plus élément du bucket
 * @return un nouveau bucket avec (key, value) à l'intérieur
*/
bucket_t* append_bucket(bucket_t* bucket, cle_t key, valeur_t value);


/**
 * Permet d'ajouter un élément au début, sans aucun tests (veillez à ce que la table reste bijective !!!)
 * Complexité : O(1)
 * @requires bucket == NULL || bucket == (bucket existant)
 * @requires key != NULL && key pas dans bucket
 * @requires value != -1
 * @return un nouveau bucket ayant pour suite [bucket]
*/
bucket_t* append_bucket_fast(bucket_t* bucket, cle_t key, valeur_t value);


/**
 * Permet de supprimer un bucket. Elle permet d'appeler récursivement.
 * Complexité : O(n)
 * la fonction free définie dans stdlib.
 * @requires bucket un pointeur vers une structure bucket_t
 * @ensures bucket* et toute ses maillons sont supprimés
*/
void delete_bucket(bucket_t* bucket);

/**
 * Retourne une valeur dans un bucket.
 * Complexité : O(n)
 * @requires key != NULL
 * @return -1 si aucun élément de [bucket] a pour clé [key], sinon la valeur associé à la clé
*/
valeur_t search_bucket(bucket_t* bucket, cle_t key);


/**
 * Retourne la clé assosié à une valeur, si elle existe.
 * Complexité : O(n)
 * @requires value != -1
 * @return NULL si [value] n'est pas dans le bucket, [clé] si la pair ([clé], [value]) est dans le bucket
*/
cle_t search_key_bucket(bucket_t* bucket, valeur_t value);


/**
 * Permet d'affiché un bucket récursivement.
 * Complexité : O(n)
*/
void show_bucket(bucket_t* bucket);

/**
 * Permet d'affiché un bucket en affichant le hash de la clé entre parenthèses.
 * Complexité : O(n)
*/
void show_bucket_with_hash(bucket_t* bucket);



// MANIPULATION DES TABLES DE HACHAGE

/**
 * La table de hachage est une structure contenant une liste contigue de pointeur vers
 * des listes chainées. On stocke également la taille de cette liste afin de pouvoir calculer
 * le modulo.
*/
typedef struct hachage_s {
    int size;
    bucket_t** bucket_array;
} hachage_t;


/**
 * Permet de crée une hashmap tel que la taille de la liste contigue de pointeur de bucket
 * est de [size].
 * Complexité : probablement O(1)
 * @requires size > 0
 * @ensures table de hachage crée en mémoire
 * @return nouvelle table de hachage pouvant contenir [size] buckets.
*/
hachage_t* create_hashmap(int size);

/**
 * Permet de supprimer un hashmap, ainsi que tout les buckets.
 * Complexité : O(n) avec n le nombre de paires dans la table
 * @requires objet de type hachage_t*
 * @ensure table de hachage libéré de la mémoire.
*/
void delete_hashmap(hachage_t* map);

/**
 * Permet d'ajouter un élément dans la structure.
 * Complexité : O(n) (c'est la complexité pour ajouter un objet dans un bucket avec append_bucket)
 * @requires map != NULL
 * @requires key != NULL
 * @requires value != -1
 * @ensure (key, value) dans la table passée en paramètre
*/
void add_element(hachage_t* map, cle_t key, valeur_t value);

/**
 * Permet d'ajouter un élément rapidement, sans modifier les éléments actuels (à manipuler avec précautions !
 * il ne faut pas de doublons et il faut veiller à ce que la structure reste bijective).
 * Complexité : O(1)
 * @requires map != NULL
 * @requires key != NULL && key pas dans map
 * @requires value != -1 && value pas dans map ()
 * @endure (key, value) dans la table passée en paramètre
*/
void add_element_fast(hachage_t* map, cle_t key, valeur_t value);

/**
 * Permet de renvoyer un élément dans la hashmap, renvoie -1 si elle n'est pas dedans.
 * @requires map != NULL
 * @requires key != NULL
 * @return -1 si map ne contient pas de clé [key], [valeur] si map contient la paire ([clé], [valeur])
*/
valeur_t get_element(hachage_t* map, cle_t key);

/**
 * Permet de retrouver une clé à partir de sa valeur
 * Complexité : O(n)
 * @requires map != NULL
 * @requires key != -1
 * @return NULL si [value] n'est pas dans [map], [clé] si map contient la paire ([clé], [value])
*/
cle_t retrieve_key(hachage_t* map, valeur_t value);


/**
 * Permet de calculer l'index dans la hashmap en fonction de la clé.
 * Complexité : Dépend du nombre de bucket et du nombre d'éléments
 * @requires map != NULL
 * @requires key != NULL
 * @return hash(key)%map->size
*/
unsigned int get_bucket_index(hachage_t* map, cle_t key);

/**
 * Permet d'afficher une représentation de la table [map] dans la sortie standard.
 * Complexité : O(n)
*/
void show_hashmap(hachage_t* map);

/**
 * Permet d'afficher une représentation de la table [map] dans la sortie standard, ainsi que la valeur de hachage
 * des clés de chaques buckets.
 * Complexité : O(n)
*/
void show_hashmap_with_hash(hachage_t* map);

// Fonctions de hachage

/**
 * Permet de transformer une chaine de caractère en un entier quasiment unique.
 * Complexité : O(n)
 * @requires data != NULL
 * @return entier quasiment unique
*/
unsigned int hash(char* data);


#endif
