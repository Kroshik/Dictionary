#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "List.h"
#include "HashTable.h"
#define SIZE_WORD 128



/*
Function for start programm
*/
void start_print(char *);
void add_word(FILE *);
char * get_line(FILE *);
void search_word(FILE *);
void remove_word(FILE *);

/*
Function for test programm
*/
void tets_find();
void test_push();
void test_clear();
void test_erase();
