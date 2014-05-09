#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

int max(int a, int b);

int xerbla_(char *srname, int *info);

int dtrmv_(char *uplo, char *trans, char *diag, long *n, 
	double *a, long *lda, double *x, long *incx);

double* generateVector(unsigned int size);

double* generateMatrix(unsigned int size);
#endif 
