#include <stdio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <likwid.h>

#include "mat_utils.h"
#include "grad.h"

int main(int argc, char **argv) {

    char *ivalue = NULL;
    char *rvalue = NULL;
    int index, c, n;
    double *A, *b, *r, iaux, *aux;

    while ((c = getopt(argc, argv, "i:r:")) != -1) {
        switch (c) {
            case 'i':
                ivalue = optarg;
                break;
            case 'r':
                rvalue = optarg;
                break;
            case '?':
                if ((optopt == 'i') || (optopt == 'r'))
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

    if (rvalue == NULL) {
        /* Pega o arquivo de entrada, se não houver, lê da entrada padrão. */
        FILE *stream = (ivalue == NULL? stdin : fopen(ivalue, "r"));
        fscanf(stream, "%d", &n);
        readInput(stream, &A, &b, n);
        if (ivalue != NULL) fclose(stream);
    }
    else {
        n = atoi(rvalue);
        A = (double*) malloc(n*n*sizeof(double));
        b = (double*) malloc(n*sizeof(double));
        generateRandomPositiveDefiniteLinearSystem(n, A, b);
    }

    r = (double *)malloc(n*sizeof(double));
    double *prodMat = (double *)malloc(n*sizeof(double));
    memset(r, 0, n*sizeof(double));

    likwid_markerInit();
    likwid_markerStartRegion("Compute");

    double mult1 = 0.0;
    double mult2 = 0.0;

    for (int i=0; i<n; ++i){
        mult1 += r[i]*r[i];
        prodMat[i] = 0.0;
        for (int j=0; j<n; ++j){
            prodMat[i] += r[j]*A[i*n+j];
        }
        mult2 += r[i]*prodMat[i];
    }

    free(prodMat);

    likwid_markerStopRegion("Compute");
    likwid_markerClose();

    free(aux);
    free(A);
    free(b);
    free(r);

    return 0;
}