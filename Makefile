CC = gcc
CFLAGS = -Wall -lm

all:
	        $(CC) *.c -o gradSolver $(CFLAGS)

clean:
	        rm -rf gradSolver
