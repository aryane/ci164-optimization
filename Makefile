CC = gcc
CFLAGS = -Wall -lm

all:
	        $(CC) *.c -std=c99 -o gradSolver $(CFLAGS)
	        $(CC) generate_input.c mat_utils.* -std=c99 -o generate_input $(CFLAGS)

clean:
	        rm -rf gradSolver generate_input
