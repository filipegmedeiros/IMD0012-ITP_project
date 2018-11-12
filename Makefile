################## MAKEFILE #################

FLAGS = -lGL -lpng -lz -lm -o
CFLAGS = -Wall
CC = gcc
BINS = db run
VPATH=src bin

all:    $(BINS)

db:    headers.h main.c src_main.c src_tables.c
	$(CC) $(CFLAGS) ./src/main.c ./src/headers.h ./src/source_func-primarias.c ./src/source_func-secundarias.c $(FLAGS) ./bin/programa.out

run:    programa.out
	./$<