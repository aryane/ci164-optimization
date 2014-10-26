#ifndef GRADSOLVER
#define GRADSOLVER

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#include <string.h>
#include <errno.h>
#include "mat_utils.h"

/**
 * @file grad.h
 * @brief Header do arquivo grad.c
 * @author Aryane Ast dos Santos
 * @author Kevin Katzer
 */

double gradSolver(double *A, double *b, double *x, int n, double e, int it, double *timeGrad, double *timeError);
void calcGrad(double *A, double *x, double *r, int n);
double residualNorm(double *r, int n);
void residue(double *A, double *b, double *x, double *r, int n);
double multVet(double *v, double *r, int n);
void multMat(double *A, double *v, double *result, int n);
void helper();
void readInput(char *ivalue, double **A, double **b, int *n);
void printMat(FILE *stream, double *A, int n);
void printVet(FILE *stream, double *v, int n);
void printOut(char *ovalue, double resNorm, double timeGrad, double timeError,
    double *sol, int n);

#endif
