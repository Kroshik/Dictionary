NAME := dictionary
BUILD_DIR := bin
SRC_DIR := src
CC := gcc
CFLAGS := -MMD -Werror -O3 -Wall
C_FILES := $(wildcard ${SRC_DIR}/*.c)
OBJ_FILES := $(addprefix ${BUILD_DIR}/, $(notdir ${C_FILES:.c=.o}))
OBJ_FILES := ${OBJ_FILES:.cc=.o}

all: mkdir link

mkdir: 
	mkdir -p ${BUILD_DIR}

link: ${OBJ_FILES}
	${CC} ${CFLAGS} -o ${BUILD_DIR}/${NAME} $^

clean:
	rm -rf -- ${BUILD_DIR}

${BUILD_DIR}/%.o: ${SRC_DIR}/%.c
	$(CC) $(CFLAGS) -c $< -o $@

-include ${BUILD_DIR}/*.d

.PHONY: clean all mkdir link
