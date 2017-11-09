#pragma once
#include "List.h"
#include <stdlib.h>
#include <stdio.h>
#define SIZE_HASH_TABLE 1000000

typedef struct HashTable HashTable;

struct HashTable
{
	List *list;
	size_t size;
	size_t count;
};

size_t hash_sum(char *);
void add_hash_table(HashTable *, char *, char *);
void remove_hash_table(HashTable *hash, char *word);
void resize_hash_table();
void clear_hash_table(HashTable *hash);
Node * find_hash_table(HashTable *hash, char *word);
