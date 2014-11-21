CC = gcc
CFLAGS = -std=c99 -Wall -lm
LIKWIDFLAGS = -pthread -DLIKWID_PERFMON -L/usr/local/lib -llikwid

all:
	        $(CC) main.c grad.* mat_utils.* -o gradSolver $(CFLAGS)
	        $(CC) generate_input.c mat_utils.* -o generate_input $(CFLAGS)

clean:
	        rm -rf gradSolver generate_input
likwid:
	        $(CC) main.c grad.* mat_utils.* -o gradSolverlik $(CFLAGS) $(LIKWIDFLAGS)
