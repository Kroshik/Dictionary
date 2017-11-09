#include "List.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void push_front_List(struct List *list, char *word, char *interpretation)
{
	Node *node = (struct Node*) malloc (sizeof(struct Node));
	node->next = list->head;
	node->word = word;
	node->interpretation = interpretation;
	list->head = node;
};

void print_List(struct List *list)
{
	Node *node = list->head;
	while (node != NULL)
	{
		printf("%s\n", node->word);
		printf("%s\n", node->interpretation);
		node = node->next;
	}
}

void clear_List(struct List *list)
{
	Node *node = list->head;
	Node *node_prev = node;
	while ( node != NULL)
	{
		node_prev = node;
		node = node->next;
		free(node_prev->interpretation);
		free(node_prev->word);
		free(node_prev);
	}
	list->head = NULL;
};

Node * find_List(struct List *list, char *word)
{
	Node *node = list->head;
	while (node != NULL)
	{
		if (strcmp(node->word, word) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}

void erase_List(struct List *list, char *word)
{
	Node *node = find_List(list, word);
	if (node == NULL)
		return;
	Node *iter = list->head;
	if (iter == node)
	{
		list->head = node->next;
		free(node->interpretation);
		free(node->word);
		free(node);
		return;
	}
	while (iter != NULL)
	{
		if (iter->next == node )
		{
			iter->next = node->next;
			free(node);
			return;
		}
		iter = iter->next;
	}
}

