################## MAKEFILE #################

FLAGS = -lGL -lpng -lz -lm -o
CFLAGS = -Wall -Werror
CC = gcc
BINS = db run
VPATH=src bin

all:    $(BINS)

db:    headers.h main.c source_func-primarias.c source_func-secundarias.c
	$(CC) $(CFLAGS) ./src/main.c ./src/headers.h ./src/source_func-primarias.c ./src/source_func-secundarias.c $(FLAGS) ./bin/programa.out

run:    programa.out
	./$<
