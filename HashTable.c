#include "HashTable.h"

size_t hash_sum(char *word)
{
	const size_t p = 53;
	size_t p_pow = 1;
	size_t hash = 0;
	while (*word)
	{
		hash += (*word - 'a' + 1) * p_pow;
		p_pow *= p;
		word++;
	}
	return (hash);
}

void add_hash_table(HashTable *hash, char *word, char *interpretation)
{
	size_t index = hash_sum(word) % SIZE_HASH_TABLE;
	if (hash->size == 0)
	{
		hash->list = (List*) calloc (SIZE_HASH_TABLE, sizeof(List));  //using calloc because that initialization List
		hash->size = SIZE_HASH_TABLE;
	}
	
	Node *node = find_List(hash->list + index, word);
	if (node == NULL)
		push_front_List(hash->list + index, word, interpretation);
	else
		printf ("This word exist in the Dictionary\n");	
}
void remove_hash_table(HashTable *hash, char *word)
{
	size_t index = hash_sum(word) % SIZE_HASH_TABLE;
	if (hash->size == 0 || find_List(hash->list + index, word) == NULL)
	{
		printf ("This word don't exist in the Dictionary\n");
		return;
	}
	erase_List(hash->list + index, word);
}

Node * find_hash_table(HashTable *hash, char *word)
{
	size_t index = hash_sum(word) % SIZE_HASH_TABLE;
	return (hash->list != NULL ? find_List(hash->list + index, word) : NULL);
}


