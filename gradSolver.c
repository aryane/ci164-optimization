#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

/**
 * @brief Função para medição de tempo.
 * @param void ??
 */
double timestamp(void){
    struct timeval tp;
    gettimeofday(&tp, NULL);
    return((double)(tp.tv_sec + tp.tv_usec/1000000.0));
}

/**
 * @brief Gera matrizes N*N da forma Ax = b positivas definidas.
 * @param N Dimensão da matriz.
 * @param *A Matriz A.
 * @param *b Vetor b.
 */
int generateRandomPositiveDefiniteLinearSystem(unsigned int N, double *A, double *b)
{
  if ( !A || !b )
    return (-1);

  /* generate a randomly initialized matrix in row-major order */
  double *ptr = A;
  double *end = A + N*N;

  double invRandMax = 1.0/(double)RAND_MAX;

  while( ptr != end ) {
    *ptr++ = (double)rand() * invRandMax;
  }

  /* Now we want to make this matrix positive definite. Since all
     values are positive and <1.0, we have to ensure it is symmetric
     and diagonally dominant.

     A = A + transpose(A)
     A = A + I*N                        */
  unsigned int i,j;
  for (i=0; i<N; ++i)
    for (j=i+1; j<N; ++j)
    {
      double aux = A[i*N+j];
      A[i*N+j] += A[j*N+i];
      A[j*N+i] += aux;
    }

  for (i=0; i<N; ++i)
    A[i*N+i] += A[i*N+i] + N;

  /* create the vector of independent terms (b) */
  for (i=0; i<N; ++i)
    b[i] = (double)rand() * invRandMax;

  return 0;
}


int main(int argc, char **argv) {
    // Hello World! =D

    return 0;
}
