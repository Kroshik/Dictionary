#include "HashTable.h"
#include <assert.h>
#include <string.h>

void test_add_hash_table()
{
	HashTable hash = {};
//	add_hash_table(&hash, "word", "interup");
//	add_hash_table(&hash, "wo", "pop");
//	add_hash_table(&hash, "wii", "wop");
//	add_hash_table(&hash, "wi1i", "wop");
//	add_hash_table(&hash, "wii2", "wop");
//	add_hash_table(&hash, "wii12", "wop");
//	add_hash_table(&hash, "wii43", "wop");
//	add_hash_table(&hash, "wii32", "wop");
//	print_List(hash.list);
	add_hash_table(&hash, "aaA", "aaA");
//	add_hash_table(&hash, "Aaa", "www");
	add_hash_table(&hash, "Aaa", "Aaa");
	Node *node = find_hash_table(&hash, "aaA");
	Node *nod  = find_hash_table(&hash, "Aaa");
	assert(node != NULL);
	assert(nod != NULL);
	assert(node != nod);
	assert(strcmp(node->word, nod->word));
	printf("node_1 = %s  inter = %s \n", node->word, node->interpretation);
	printf("node_2 = %s  inter = %s", nod->word, nod->interpretation);
	
	
}

