#include <stdio.h>
#include <string.h>
#include "mat_utils.h"

/**
 * @file generate_input.c
 * @brief Geração de matrizes positivas definidas simétricas para serem usadas
 * posteriormente no gradSolver
 * @author Aryane Ast dos Santos
 * @author Kevin Katzer
 */

/**
 * @brief Gera arquivo teste de entrada com uma matriz de dimensão n no formato
 * N
 * a_11 a_12 ... a_1n
 * a_21 a_22 ... a_2n
 *  .   .       .
 *  .   .       .
 *  a_n1 a_n2 ... a_nn
 *  b1 b2 ... bn
 * @param n Dimensão da matriz.
 * @param *stream stream teste para escrita.
 */
void print_input_mat(FILE *stream, int n) {
    double *b = (double*) malloc(n*sizeof(double));
    double *A = generateSquareRandomPositiveDefiniteMatrix(n);

    /** Gera valores randomicos para o vetor b */
    double invRandMax = 1.0/(double)RAND_MAX;
    memset((void*)b, (double)rand()*invRandMax, (size_t)n*sizeof(double));

    fprintf(stream, "%d\n", n);
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            fprintf(stream, "%f ", A[i*n+j]);
        }
        fprintf(stream, "\n");
    }
    for (int i=0; i<n; ++i) {
        fprintf(stream, "%f ", b[i]);
    }
}

void printHelp() {
    printf("Uso: ");
    printf("./generate_input [stream] [n]\n");
    printf("onde stream é o arquivo onde será escrita a entrada de teste\n");
    printf("(pode ser stdout) e n a dimensão da matriz gerada.\n");
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printHelp();
        exit(1);
    }

    FILE *fp_in;
    if (!strcmp(argv[1], "stdout"))
        fp_in = stdout;
    else
        fp_in = fopen(argv[1], "w");

    print_input_mat(fp_in, atoi(argv[2]));

    return 0;
}
