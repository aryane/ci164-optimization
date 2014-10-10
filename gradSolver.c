#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <string.h>
#include "mat_utils.h"


/**
 * @file gradSolver.c
 * @brief TODO
 * @author Aryane Ast dos Santos
 * @author Kevin Katzer
 */

/**
 * @brief Calcula norma do resíduo de um sistema na forma Ax = b
 * @param *A Matriz.
 * @param *b vetor b.
 * @param *x Vetor solução.
 * @param n Dimensão da matriz.
 */
double calcResidualNorm(double *A, double *b, double *x, int n) {
    double r[n], norm, sum=0.0;
    int i, j;

    for (i=0; i<n; ++i) {
        r[i] = b[i];
        for (j=0; i<n; ++i) {
            r[i] -= A[i*n+j]*x[j];
        }
    }

    // norma do vetor
    for (i=0; i<n; ++i)
        sum += r[i] * r[i];
    norm = sqrt(sum);

    return norm;
}

int main(int argc, char **argv) {
    
    /* Leitura dos parâmetros de entrada */

    for (int i=1; i<argc; i += 2){
        if (argv[i][1] == 'i')
            //Arquivo de Entrada = argv[i+1]//
        else if (argv[i][1] == 'o')
            //Arquivo de Saída = argv[i+1]//
        else if (argv[i][1] == 'r')
            //Dimensão do Sistema = argv[i+1]//
        else if (argv[i][1] == 'k')
            //Número Máximo de Iterações = argv[i+1]//
        else if (argv[i][1] == 'e')
            //Maior Erro Aceitável = argv[i+1]//
        else 
            //Parâmetro Inválido//
    }

    return 0;
}
