#include "grad.h"

/**
 * @file grad.c
 * @brief Funções criadas para a resolução do trabalho
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

double residualNorm(double *r, int n) {
    double norm, sum = 0.0;
    for (int i=0; i<n; ++i)
        sum += r[i] * r[i];
    norm = sqrt(sum);

    return norm;
}

void residue(double *A, double *b, double *x, double *r, int n) {
    for (int i=0; i<n; ++i) {
        r[i] = b[i];
        for (int j=0; i<n; ++i) {
            r[i] -= A[i*n+j]*x[j];
        }
    }
}

/**
 * @brief Imprime os parâmetros possíveis em stdout
 */
void helper() {
    printf("\033[1mUSO\033[0m\n");
    printf("\t./gradSolver [OPÇÕES]\n");
    printf("\033[1mOPÇÕES\033[0m\n");
    printf("\t\033[1m-i\033[0m\n");
    printf("\t\tArquivo de entrada do programa. Se não incluído, a matriz deve ser inserida via stdin.");
    printf("\tgradSolver -i [endereço do arquivo]\n");
    printf("\t\033[1m-o\033[0m\n");
    printf("\t\tArquivo de saída do programa. Se não incluído, a matriz será impressa em stdout.");
    printf("\tgradSolver -o [endereço do arquivo]\n");
    printf("\t\033[1m-r\033[0m\n");
    printf("\t\tDimensão da matriz a ser gerada aleatoriamente. Não deve ser inserido se for fornecido um arquivo de entrada.");
    printf("\tgradSolver -r [dimensão]\n");
    printf("\t\033[1m-k\033[0m\n");
    printf("\t\tNúmero máximo de iterações a serem executadas. (Opcional)");
    printf("\tgradSolver -k [número de iterações]\n");
    printf("\t\033[1m-e\033[0m\n");
    printf("\t\tO maior erro aceitável. (Opcional)\tgradSolver -e [erro]\n");
}
