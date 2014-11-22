CC = gcc
CFLAGS = -std=c99 -Wall -lm
LIKWIDFLAGS = -pthread -DLIKWID_PERFMON -L/usr/local/lib -llikwid

all:
	        $(CC) src/main.c src/grad.* src/mat_utils.* -o bin/gradSolver $(CFLAGS)
	        $(CC) src/generate_input.c src/mat_utils.* -o bin/generate_input $(CFLAGS)

lambda:
			$(CC) src/main.c src/gradLambda.c src/grad.h src/mat_utils.* -o bin/gradLambda $(CFLAGS) $(LIKWIDFLAGS)

residue:
			$(CC) src/main.c src/gradResidue.c src/grad.h src/mat_utils.* -o bin/gradResidue $(CFLAGS) $(LIKWIDFLAGS)

clean:
	        rm -rf bin
