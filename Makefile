CC = gcc
CFLAGS = -std=c99 -Wall -lm
LIKWIDFLAGS = -pthread -DLIKWID_PERFMON -L/usr/local/lib -llikwid

all:
	        $(CC) src/main.c src/grad.* src/mat_utils.* -o bin/gradSolver $(CFLAGS)
	        $(CC) src/generate_input.c src/mat_utils.* -o bin/generate_input $(CFLAGS)

all_opt:
	        $(CC) src/main.c src/gradOpt.c src/grad.h src/mat_utils.* -o bin/gradSolverOpt $(CFLAGS)

lambda:
			$(CC) src/gradLambda.c src/grad.* src/mat_utils.* -o bin/gradLambda $(CFLAGS) $(LIKWIDFLAGS)

lambda_opt:
			$(CC) src/gradLambdaOpt.c src/gradOpt.c src/grad.h src/mat_utils.* -o bin/gradLambdaOpt $(CFLAGS) $(LIKWIDFLAGS)

residue:
			$(CC) src/gradResidue.c src/grad.* src/mat_utils.* -o bin/gradResidue $(CFLAGS) $(LIKWIDFLAGS)

residue_opt:
			$(CC) src/gradResidueOpt.c src/gradOpt.c src/grad.h src/mat_utils.* -o bin/gradResidueOpt $(CFLAGS) $(LIKWIDFLAGS)

clean:
	        rm -rf bin/*
