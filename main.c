#include <stdio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

#include "mat_utils.h"
#include "grad.h"

/**
 * @file gradSolver.c
 * @brief TODO
 * @author Aryane Ast dos Santos
 * @author Kevin Katzer
 */

int main(int argc, char **argv) {

    char *ivalue = NULL;
    char *ovalue = NULL;
    char *rvalue = NULL;
    char *kvalue = NULL;
    char *evalue = NULL;
    double error;
    int index, k;
    int c;

    while ((c = getopt(argc, argv, "i:o:r:k:e:")) != -1) {
        switch (c) {
            case 'i':
                ivalue = optarg;
                break;
            case 'o':
                ovalue = optarg;
                break;
            case 'r':
                rvalue = optarg;
                break;
            case 'k':
                kvalue = optarg;
                break;
            case 'e':
                evalue = optarg;
                break;
            case '?':
                if ((optopt == 'k') || (optopt == 'e') || (optopt == 'i') ||
                        (optopt == 'o') || (optopt == 'r'))
                    fprintf (stderr, "Opção -%c requere um argumento.\n", optopt);
                else if (isprint (optopt))
                    fprintf (stderr, "Opção desconhecida `-%c'.\n", optopt);
                else
                    fprintf (stderr,
                            "Character de opção desconhecido `\\x%x'.\n",
                            optopt);
                    helper();
                exit(1);
            default:
                abort();
        }
    }
    for (index = optind; index < argc; index++)
        printf("Argumento %s não é opção.\n", argv[index]);

    int n;
    double *A, *b;
    if (rvalue == NULL) {
        /* Pega o arquivo de entrada, se não houver, lê da entrada padrão. */
        FILE *stream = (ivalue == NULL? stdin : fopen(ivalue, "r"));
        fscanf(stream, "%d", &n);
        A = (double*) malloc(n*n*sizeof(double));
        b = (double*) malloc(n*sizeof(double));
        readInput(stream, ivalue, &A, &b, n);
        fclose(stream);
    }
    else {
        n = atoi(rvalue);
        A = (double*) malloc(n*n*sizeof(double));
        b = (double*) malloc(n*sizeof(double));
        generateRandomPositiveDefiniteLinearSystem(n, A, b);
    }

    double timeGrad, timeError;

    /* Pega erro e máximo de iterações */
    k = (kvalue == NULL? 2*n : atoi(kvalue));
    error = (evalue == NULL? 0.0001 : atof(evalue));

    double *x = (double *)malloc(n*sizeof(double));
    double residualNorm = gradSolver(A, b, x, n, error, k, &timeGrad, &timeError);
    printOut(ovalue, residualNorm, timeGrad, timeError, x, n);

    free(A);
    free(b);

    return 0;
}
