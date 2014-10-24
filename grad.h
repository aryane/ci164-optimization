#ifndef GRADSOLVER
#define GRADSOLVER

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#include <string.h>
#include "mat_utils.h"

/**
 * @file grad.h
 * @brief Header do arquivo grad.c
 * @author Aryane Ast dos Santos
 * @author Kevin Katzer
 */

void gradSolver(double *A, double *x, int n, double e, int it);
void calcGrad(double *A, double *x, double *r, int n);
double residualNorm(double *r, int n);
void residue(double *A, double *b, double *x, double *r, int n);
double multVet(double *v, double *r, int n);
void multMat(double *A, double *v, double *result, int n);
void helper();
int readN(FILE *f);
void readMat(FILE *f, double *A, double *b, int n);

#endif
