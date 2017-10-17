# Project: dictionary
# Makefile created by Dev-C++ 5.11

CPP      = g++
CC       = gcc
WINDRES  = windres.exe
OBJ      = main.o List.o test_List.o HashTable.o start_programm.o test_Hash_Table.o common.o
LINKOBJ  = main.o List.o test_List.o HashTable.o start_programm.o test_Hash_Table.o common.o
LIBS     = 
INCS     = 
CXXINCS  = 
BIN      = dictionary
CXXFLAGS = $(CXXINCS) -g3 -std=c11 -Wall -Werror
CFLAGS   = $(INCS) -g3 -std=c11 -Wall -Werror
RM       = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LINKOBJ) -o $(BIN) $(LIBS)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

List.o: List.c
	$(CC) -c List.c -o List.o $(CFLAGS)

test_List.o: test_List.c
	$(CC) -c test_List.c -o test_List.o $(CFLAGS)

HashTable.o: HashTable.c
	$(CC) -c HashTable.c -o HashTable.o $(CFLAGS)

start_programm.o: start_programm.c
	$(CC) -c start_programm.c -o start_programm.o $(CFLAGS)

test_Hash_Table.o: test_Hash_Table.c
	$(CC) -c test_Hash_Table.c -o test_Hash_Table.o $(CFLAGS)
