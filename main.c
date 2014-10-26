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
    int index;
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

    double *A, *b, timeGrad, timeError;  // Mat A, vector b
    int n;          // Dimension

    if (rvalue == NULL){
        readInput(ivalue, &A, &b, &n);
    }
    else{
        b = (double*) malloc(n*sizeof(double));
        A = (double*) malloc(n*n*sizeof(double));

        generateRandomPositiveDefiniteLinearSystem(n,A,b);
    }
    if (kvalue == NULL)
        sprintf(kvalue, "%d", 2*n);
    if (evalue == NULL)
        evalue = "0.0001";
    double *x = (double *)malloc(n*sizeof(double));
    double resNorm = gradSolver(A, b, x, n, atof(evalue), atoi(kvalue), &timeGrad, &timeError);
    printOut(ovalue, resNorm, timeGrad, timeError, x, n);

    return 0;
}
