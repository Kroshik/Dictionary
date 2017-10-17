#pragma once

//#include "header_only.h"

typedef struct Node Node;
typedef struct List List;

struct Node
{
	Node *next;
	char *word;
	char *interpretation;
};
struct List
{
	Node *head;	
};
/*
Function for using List
*/
void push_front_List(struct List *list, char *word, char *interpretation);  //push node in head
void print_List(struct List *list);  //Just print all node's in List
void clear_List(struct List *list);  //Clear List
struct Node * find_List(struct List *list, char *word);  //Search in List char* and return *node
void erase_List(struct List *list, char *word);  //Delete from List node with word = char *word

