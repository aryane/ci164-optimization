CC = gcc
CFLAGS = -std=c99 -Wall -lm
LIKWIDFLAGS = -pthread -DLIKWID_PERFMON -L/usr/local/lib -llikwid

all:
	        $(CC) main.c grad.* mat_utils.* -o gradSolver $(CFLAGS)
	        $(CC) generate_input.c mat_utils.* -o generate_input $(CFLAGS)

lambda:
			$(CC) main.c gradLambda.c grad.h mat_utils.* -o gradLambda $(CFLAGS) $(LIKWIDFLAGS)

residue:
			$(CC) main.c gradResidue.c grad.h mat_utils.* -o gradResidue $(CFLAGS) $(LIKWIDFLAGS)

clean:
	        rm -rf gradSolver generate_input