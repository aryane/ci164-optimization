CC = gcc
CFLAGS = -Wall -lm

all:
	        $(CC) *.c -std=c99 -o gradSolver $(CFLAGS)

clean:
	        rm -rf gradSolver
