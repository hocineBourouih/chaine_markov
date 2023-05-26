#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "markov.h"

// Structure pour représenter une entrée détat
struct etatEntree 
    {
    int etat;
    unsigned int poid; // poid entre les etat
    UT_hash_handle hh; // obligatoire utiliser la bibliothèque uthash

    /* La bib uthash requiert que chaque structure utiliser pour une table de hachage
       inclue un champ de type UT_hash_handle, qui est utilisé par la bibliothèque pour stocker
       des informations internes sur la table de hachage.*/
    };



// Structure de chaine de Markov
struct markov_t 
    {
    struct etatEntree **poids; // Tab de pointeurs vers les états dentré
    unsigned int num_etat; // nb detats dans la chaine
    };



markov_t *markovCreation(unsigned int valeur_initiale)
    {
    srand(valeur_initiale);
    markov_t *chain = malloc(sizeof(markov_t));

    chain->poids = NULL;
    chain->num_etat = 0;

    return chain;
    }


// détruire une chaîne de Markov et libérer la mémoire alloué
void markovDetruire(markov_t *chain) 
{
    for(unsigned int i = 0; i < chain->num_etat; i++) 
    {
        struct etatEntree *entre, *tmp;
        
        // Parcourir et libérer les entrées d'état dans la table de hachage
        HASH_ITER(hh, chain->poids[i], entre, tmp) {
            HASH_DEL(chain->poids[i], entre);
            free(entre);
        }
    }

    free(chain->poids);

    free(chain);
}


void markovAjoutEtat(markov_t *chain, int etat) 
    {
    // Vérifier si l'état est déjà dans la chaîne 
    if(etat >= chain->num_etat) 
    {
        // Agrandir le tableau de poids pour accueillir le nouvel etat
        chain->poids = realloc(chain->poids, sizeof(struct etatEntree *) * (etat + 1));


        // Initialise les pointeurs des nouveaux état à NULL
        for(unsigned int i = chain->num_etat; i <= etat; i++) 
        {
            chain->poids[i] = NULL;
        }

        // mettre à jour de nb detats
        chain->num_etat = etat + 1;
    }
}


void markovIncrementPoid(markov_t *chain, int etat1, int etat2) 
    {
    struct etatEntree *entre;

    // Rechercher lentrée d'état correspondant à etat2 dans la table de hachage
    // on utilise la fonction de notre bib uthash
    HASH_FIND_INT(chain->poids[etat1], &etat2, entre);

    // Si elle existe pas on la cree et on l'ajoute à la table
    if(entre == NULL) 
    {
        entre = malloc(sizeof(struct etatEntree));
        entre->etat = etat2;
        entre->poid = 0;

        // Ajouter la nouvelle entrée d'état à la table de hachage
        HASH_ADD_INT(chain->poids[etat1], etat, entre);
    }

    // Incrémenter le poids entre les deux état
    entre->poid++;
}


double markovTransitionProba(markov_t *chain, int etat1, int etat2) 
    {
    struct etatEntree *entre;
    unsigned int total_poid = 0;

    // on recheche l'entré qui corespond à l'état 2 dans la table du hachage 
    HASH_FIND_INT(chain->poids[etat1], &etat2, entre);

    // Si l'entrée d'état n'existe pas, la probabilité de transition est de 0
    if(entre == NULL)
    {
        return 0;
    }

    struct etatEntree *tmp;
    for(tmp = chain->poids[etat1]; tmp != NULL; tmp = tmp->hh.next) 
    {
        total_poid += tmp->poid;
    }

    return (double)entre->poid / total_poid;
}



int markovAleaEtatSuivant(markov_t *chain, int etat_actuel) 
    {
    struct etatEntree *tmp, *selected_entre;
    unsigned int total_poid = 0;

    // Calculer le poids total des transitions à partir de l'état etat_actuel
    for(tmp = chain->poids[etat_actuel]; tmp != NULL; tmp = tmp->hh.next) 
    {
        total_poid += tmp->poid;
    }

    // Si le poids total est de 0 on fait pas de transition 
    if(total_poid == 0)
    {
        return -1;
    }

    // Sélectionner un poids aléatoire entre 0 et total_poid 
    unsigned int random_poid = rand() % total_poid;
    unsigned int cumulative_poid = 0;

    // Parcourir les entré d'état et sélectionner celle le poids cumulatif dépasse le poids aléa générer
    for(tmp = chain->poids[etat_actuel]; tmp != NULL; tmp = tmp->hh.next) 
    {
        cumulative_poid += tmp->poid;

        if(random_poid < cumulative_poid)
        {
            selected_entre = tmp;
            break;
        }
    }

    // Retourner l'état de l'entrée d'état sélectionnée, ou -1 si aucune entrée d'état a été sélectionné
    if(selected_entre != NULL) 
    {
        return selected_entre->etat;
    }
    else
    {
        return -1;
    }

}
