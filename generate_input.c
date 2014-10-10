#include <stdio.h>
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
 * @param *fp_in arquivo de teste já aberto para escrita. Servirá de entrada no
 * programa principal posteriormente.
 */
void print_input_mat(FILE *fp_in, int n) {
    double *A=NULL, *b=NULL;
    b = (double*) malloc(N*sizeof(double));
    generateRandomPositiveDefiniteLinearSystem(n, A, b);

    printf("%d\n", n);
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            fprintf(fp_in, "%f ", A[i*n+j]);
        }
        fprintf(fp_in, "\n");
    }
    for (int i=0; i<n; ++i) {
        fprintf(fp_in, "%f ", b[i]);
    }
}

int main(int argc, char **argv) {
    /** Não testa quantidade de argumentos pois temos domínio da situação ;) */
    if (argc > 1)
    FILE *fp_in = fopen(argv[1], "w");

    print_input_mat(fp_in, 10);

    return 0;
}
