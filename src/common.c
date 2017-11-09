#include "common.h"
#include "header_only.h"
#include <stdlib.h>

extern HashTable hash;

void save_dictionary(char *dictionary_path)
{
	FILE *dictionary_file = fopen(dictionary_path, "w");
	if (!dictionary_file)
	{
		fprintf(stderr, "Can't open dictionary file: %s", dictionary_path);
		exit(7);
	}
	
	for (size_t i = 0; i < hash.size; i++)
	{
		Node *node = hash.list[i].head;
		while (node != NULL)
		{
			fprintf(dictionary_file, "%s\n%s\n", node->word, node->interpretation);
			node = node->next;
		}
	}
	
	fclose(dictionary_file);
}

void load_dictionary(FILE *file)
{
	while (!feof(file))
	{
		char *word = (char*) malloc(SIZE_WORD + 1);  // need allocate memory in heap
		if (fscanf(file, "%129s", word) < 0)
		{
			free(word);
			break;
		}
		fgetc(file);  	// read only '\n' for correct work get_line()
		if (strlen(word) > SIZE_WORD)
		{
			fprintf(stderr, "Invalid format file\n");
			exit(1);
		}
		char *interpretation = get_line(file);
		if (interpretation == NULL)
			return;
		add_hash_table(&hash, word, interpretation);
	}
}
