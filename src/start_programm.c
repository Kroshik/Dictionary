#include "header_only.h"
#include "common.h"


HashTable hash;

void start_print(char *dictionary_path)
{
	int ch;
	while (1)
	{
		printf ("1: Adding a new word and interpretation.\n");
		printf ("2: Search for word and him interpretation.\n");
		printf ("3: Delete the word.\n");
		printf ("4: Exit\n");
		int press = 0;
		if(!scanf("%i", &press))
		{
			while (EOF != (ch = fgetc(stdin)) && ch != '\n');  
			continue;	
		}
		while (EOF != (ch = fgetc(stdin)) && ch != '\n');  
		switch (press) 
		{
			case 1:
				add_word(stdin);
				break;
			case 2:
				search_word(stdin);
				break;
			case 3:
				remove_word(stdin);
				break;
			case 4:
				if (dictionary_path)
				{
					save_dictionary(dictionary_path);
				}	
				clear_hash_table(&hash);
				exit(5);
			default:
				printf ("Incorrect command\n");
				break;
		}
	}

}

void add_word(FILE *input)
{
	printf ("Write adding word:\n");
	char *word = (char*) malloc(SIZE_WORD + 1);  // need allocate memory in heap
	if(fscanf(input, "%129s", word) < 0)
	{
		exit(3);
	}
	fgetc(input);  	// read only '\n' for correct work get_line()
	if (strlen(word) > SIZE_WORD)
	{
		printf ("Your word is too long.\n");	
		return;
	}
	printf ("Write interpretation word:\n");
	char *interpretation = get_line (input);
	add_hash_table (&hash, word, interpretation);
}

void search_word(FILE *input)
{
	printf ("Write searching word:\n");
	char word[SIZE_WORD + 1];  // dont need allocate memory in heap, just stack
	if(scanf("%129s", word) != 1)
		exit(3);
	fgetc(input);   // read only '\n' for correct work get_line()
	if (strlen(word) > SIZE_WORD)
	{
		printf ("Your word is too long.\n");
		return;
	}
	Node *node = find_hash_table(&hash, word);
	if (node == NULL)
	{
		printf ("Word don't exist in Dictionary\n");
		return;
	}
	printf ("Interpretation word %s  is: %s\n", node->word, node->interpretation);
}

void remove_word(FILE *input)
{
	printf ("Write word for delete:\n");
	char word[SIZE_WORD + 1];  // dont need allocate memory in heap, just stack
	if(scanf("%129s", word) != 1)
		exit(3);
	fgetc(input);   // read only '\n' for correct work get_line()
	if (strlen(word) > SIZE_WORD)
	{
		printf ("Your word is too long.\n");
		return;
	}
	remove_hash_table(&hash, word);
	return;
}

char * get_line(FILE *input)
{
	size_t size_buf = 100;
	size_t len = 0;
	int ch;
	char *buf;
	buf = (char*)malloc(size_buf);
	if(!buf)
		return buf;
	while (EOF != (ch = fgetc(input)) && ch != '\n')
	{
		buf[len++] = ch;
        if(len == size_buf)
		{
        	size_buf <<= 1;
            buf = realloc(buf, size_buf);
            if(!buf)
				return buf;
        }
	}
	if (ch == EOF && len == 0) {
		free(buf);
		return NULL;
	}
		
	buf[len++]='\0';
    return realloc(buf, len);
}

