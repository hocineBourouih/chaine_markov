#include "hachage.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

bucket_t* append_bucket(bucket_t* bucket, cle_t key, valeur_t value) {
    if(bucket == NULL) {
        bucket_t* new_bucket = malloc(sizeof(bucket_t));
        new_bucket->next = NULL;
        new_bucket->pair.key = key;
        new_bucket->pair.value = value;
        return new_bucket;
    }

    if(strcmp(bucket->pair.key, key) == 0) {
        bucket->pair.value = value;
        return bucket;
    }
    bucket->next = append_bucket(bucket->next, key, value);

    return bucket;
}

bucket_t* append_bucket_fast(bucket_t* bucket, cle_t key, valeur_t value) {
    bucket_t* new_bucket = malloc(sizeof(bucket_t));
    new_bucket->pair.key = key;
    new_bucket->pair.value = value;
    new_bucket->next = bucket;
    return new_bucket;
}


void delete_bucket(bucket_t* bucket) {
    if(bucket == NULL) {
        return;
    }

    delete_bucket(bucket->next);
    free(bucket);
}


valeur_t search_bucket(bucket_t* bucket, cle_t key) {
    if(bucket == NULL) {
        return -1;
    }

    if(strcmp(bucket->pair.key, key) == 0) {
        return bucket->pair.value;
    }

    return search_bucket(bucket->next, key);
}


cle_t search_key_bucket(bucket_t* bucket, valeur_t value) {
    if(bucket == NULL) {
        return NULL;
    }

    if(value == bucket->pair.value) {
        return bucket->pair.key;
    }

    return search_key_bucket(bucket->next, value);
}


void show_bucket(bucket_t* bucket){
    if(bucket == NULL) {
        printf("X\n");
        return;
    }
    printf("{\"%s\" => %d} -> ", bucket->pair.key, bucket->pair.value);
    show_bucket(bucket->next);
}

void show_bucket_with_hash(bucket_t* bucket) {
    if(bucket == NULL) {
        printf("X\n");
        return;
    }
    printf("{\"%s\" (%"PRIu32") => %d} -> ",   bucket->pair.key,
                                    hash(bucket->pair.key),
                                    bucket->pair.value);
    show_bucket_with_hash(bucket->next);
}

hachage_t* create_hashmap(int size) {
    hachage_t* map = malloc(sizeof(map));
    map->size = size;
    map->bucket_array = malloc(sizeof(bucket_t*)*size);
    return map;
}

void delete_hashmap(hachage_t* map) {
    if(map == NULL) return;

    for(uint32_t i = 0; i < map->size; i++) {
        delete_bucket(map->bucket_array[i]);
        map->bucket_array[i] = NULL;
    }
}

void add_element(hachage_t* map, cle_t key, valeur_t value) {
    unsigned int index = get_bucket_index(map, key);
    map->bucket_array[index] = append_bucket(map->bucket_array[index], key, value);
}

void add_element_fast(hachage_t* map, cle_t key, valeur_t value) {
    unsigned int index = get_bucket_index(map, key);
    map->bucket_array[index] = append_bucket_fast(map->bucket_array[index], key, value);
}


valeur_t get_element(hachage_t* map, cle_t key) {
    unsigned int index = get_bucket_index(map, key);
    return search_bucket(map->bucket_array[index], key);
}


cle_t retrieve_key(hachage_t* map, valeur_t val) {
    cle_t key = NULL;
    int index = 0;

    while(key == NULL && index < map->size) {
        key = search_key_bucket(map->bucket_array[index], val);
        index++;
    }

    return key;
}


uint32_t hash(char* data) {
    unsigned int primes[7] = {13, 73, 37, 17, 7, 97, 19}; 
    uint32_t seed = 1;
    int size = strlen(data) * sizeof(char);
    for(uint32_t i = 0; i < size; i++) {
        seed = seed * primes[i%7] + data[i]; 
    }
    return seed;
}

unsigned int get_bucket_index(hachage_t* map, cle_t key) {
    return hash(key)%(map->size);
}

void show_hashmap(hachage_t* map) {
    for(int i = 0; i < map->size; i++) {
        printf("%d: ", i);
        show_bucket(map->bucket_array[i]);
    }
}

void show_hashmap_with_hash(hachage_t* map) {
    for(int i = 0; i < map->size; i++) {
        printf("%d: ", i);
        show_bucket_with_hash(map->bucket_array[i]);
    }
}