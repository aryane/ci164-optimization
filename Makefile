CC = gcc
CFLAGS = -std=c99 -Wall -lm

all:
	        $(CC) main.c grad.* mat_utils.* -o gradSolver $(CFLAGS)
	        $(CC) generate_input.c mat_utils.* -o generate_input $(CFLAGS)

clean:
	        rm -rf gradSolver generate_input
