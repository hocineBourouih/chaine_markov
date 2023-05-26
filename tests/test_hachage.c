#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"../src/hachage.h"



  void append_bucket_test();
  void search_bucket_test();
  void search_key_bucket_test();
  void create_hashmap_test();
  void add_element_test();
  void get_element_test();
  void retrieve_key_test();




int main(int argc, char *argv[])
{
  append_bucket_test();
  search_bucket_test();
  search_key_bucket_test();
  create_hashmap_test();
  add_element_test();
  get_element_test();
  retrieve_key_test();
  return EXIT_SUCCESS;
}




void append_bucket_test() {
  bucket_t *bucket = NULL;
  cle_t key = "cle";
  int value = 42 ;
  bucket = append_bucket(bucket, key, value);
  assert(bucket != NULL);
  assert(strcmp(bucket->pair.key, "cle") == 0);
  assert(bucket->pair.value == 42);

  bucket = append_bucket(bucket, "cle2", 12);
  assert(bucket->next != NULL);
  assert(strcmp(bucket->next->pair.key, "cle2") == 0);
  assert(bucket->next->pair.value == 12);
  
  delete_bucket(bucket);
}





void search_bucket_test() {
  bucket_t *bucket = NULL;

  bucket = append_bucket(bucket, "cle", 42);
  bucket = append_bucket(bucket, "cle2", 12);

  assert(search_bucket(bucket, "cle") == 42);
  assert(search_bucket(bucket, "cle2") == 12);
  assert(search_bucket(bucket, "jeej") == -1);

  delete_bucket(bucket);
}







void search_key_bucket_test() {
  bucket_t *bucket = NULL;
  bucket = append_bucket(bucket, "cle", 42);
  bucket = append_bucket(bucket, "cle2", 12);

  assert(strcmp(search_key_bucket(bucket, 42), "cle") == 0);
  assert(strcmp(search_key_bucket(bucket, 12), "cle2") == 0);
  assert(search_key_bucket(bucket, 17) == NULL);

  delete_bucket(bucket);
}




void create_hashmap_test() {
  hachage_t *hashmap = create_hashmap(4);

  for(int i = 0 ; i < 4 ; i++) {
     assert(hashmap->bucket_array[i] == NULL);
  }
  assert(hashmap->size == 4);

  delete_hashmap(hashmap);
  
}


void add_element_test() {
  hachage_t *hashmap = create_hashmap(4);
  unsigned int index = get_bucket_index(hashmap, "cle");
  add_element(hashmap, "cle", 42);

  assert(hashmap->bucket_array[index] != NULL);
  assert(hashmap->bucket_array[index]->pair.value == 42);

  delete_hashmap(hashmap);
}





void get_element_test() {
  hachage_t *hashmap = create_hashmap(4);
  add_element(hashmap, "cle", 42);

  assert(get_element(hashmap, "cle") == 42);
  assert(get_element(hashmap, "cle2") == -1);

  delete_hashmap(hashmap);
}





void retrieve_key_test() {
  hachage_t *hashmap = create_hashmap(4);
  add_element(hashmap, "cle", 42);

  assert(strcmp(retrieve_key(hashmap, 42), "cle") == 0);
  assert(retrieve_key(hashmap, 12) == NULL);

  delete_hashmap(hashmap);
}


