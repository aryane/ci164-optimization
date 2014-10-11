#ifndef MAT_UTILS
#define MAT_UTILS

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

/**
 * @file mat_utils.h
 * @brief Header do arquivo mat_utils.c
 * @author Aryane Ast dos Santos
 * @author Kevin Katzer
 */

double timestamp(void);
int generateRandomPositiveDefiniteLinearSystem(unsigned int N, double *A, double *b);
double *generateSquareRandomPositiveDefiniteMatrix(unsigned int n);

#endif
