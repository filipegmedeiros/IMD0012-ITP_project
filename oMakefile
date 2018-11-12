################## MAKEFILE #################

FLAGS = -lGL -lpng -lz -lm -o
CFLAGS = -Wall
CC = gcc
BINS = db run
VPATH=src bin

all:    $(BINS)

db:    headers.h main.c sources.c
	$(CC) $(CFLAGS) ./src/main.c ./src/headers.h ./src/sources.c $(FLAGS) ./bin/programa.out

run:    programa.out
	./$<