#include "utils.h"

int max(int a, int b) {
	if(a > b) return a;
	else      return b;
}

void printMatrix(double *mat, unsigned int size)  {
	unsigned int i, j;
	
	for(i = 0; i < size; i++) {
		for(j = 0; j < size; j++)
		
		if(j == size - 1) 
		  printf("%lf\n", mat[i * size + j]);
		else
		  printf("%lf ", mat[i * size + j]);
	}
}
	
void printVector(double *vec , unsigned int size)  {
	unsigned int i;
	
	for(i = 0; i < size; i++) {
		printf("%lf\n", vec[i]);
	}
}

double* generateVector(unsigned int size) {
  unsigned int counter;
  double *vec;
    
  /* aloc memorie pentru vector */
  vec = malloc(sizeof(double) * size);
  
  /* generam vectorul data */
  for(counter = 0; counter < size; counter++) {
	  vec[counter] = (double) ((double)rand() / (RAND_MAX));
  }
  
  return vec;
}

/* Functia genereaza o matrice triubhiulara */
double* generateMatrix(unsigned int size) {
  unsigned int counter_i, counter_j;
  int nr_zero = -1;
  double *mat;
  
  /* aloc memorie pt matrice */
  mat = malloc(sizeof(double) * size * size);
  
  /* generam matricea data */
  for(counter_i = 0; counter_i < size; counter_i++) 
  {
	  for(counter_j = 0; counter_j < counter_i; counter_j++)   	    
	    mat[counter_i * size +counter_j] = 0;
	      
	    /* Generez zeroouri: */
	    for(counter_j; counter_j < size; counter_j++) 
		  mat[counter_i * size + counter_j] = (double) ((double)rand() / (RAND_MAX));
  }
  
  return mat;
}

int xerbla_(char *srname, int *info)
{
/*  -- LAPACK auxiliary routine (version 2.0) --   
       Univ. of Tennessee, Univ. of California Berkeley, NAG Ltd.,   
       Courant Institute, Argonne National Lab, and Rice University   
       September 30, 1994   


    Purpose   
    =======   

    XERBLA  is an error handler for the LAPACK routines.   
    It is called by an LAPACK routine if an input parameter has an   
    invalid value.  A message is printed and execution stops.   

    Installers may consider modifying the STOP statement in order to   
    call system-specific exception-handling facilities.   

    Arguments   
    =========   

    SRNAME  (input) CHARACTER*6   
            The name of the routine which called XERBLA.   

    INFO    (input) INT   
            The position of the invalid parameter in the parameter list   

            of the calling routine.   

   ===================================================================== 
*/

    printf("** On entry to %6s, parameter number %2d had an illegal value\n",
		srname, *info);

/*     End of XERBLA */

    return 0;
} /* xerbla_ */



int dtrmv_(char *uplo, char *trans, char *diag, long *n, 
	double *a, long *lda, double *x, long *incx)
{


    /* System generated locals */
    long a_dim1, a_offset, i__1, i__2;

    /* Local variables */
    static long info;
    static double temp;
    static long i, j;
    static long ix, jx, kx;
    
    static int nounit;


/*  Purpose   
    =======   

    DTRMV  performs one of the matrix-vector operations   

       x := A*x,   or   x := A'*x,   

    where x is an n element vector and  A is an n by n unit, or non-unit, 
  
    upper or lower triangular matrix.   

    Parameters   
    ==========   

    UPLO   - CHARACTER*1.   
             On entry, UPLO specifies whether the matrix is an upper or   
             lower triangular matrix as follows:   

                UPLO = 'U' or 'u'   A is an upper triangular matrix.   

                UPLO = 'L' or 'l'   A is a lower triangular matrix.   

             Unchanged on exit.   

    TRANS  - CHARACTER*1.   
             On entry, TRANS specifies the operation to be performed as   
             follows:   

                TRANS = 'N' or 'n'   x := A*x.   

                TRANS = 'T' or 't'   x := A'*x.   

                TRANS = 'C' or 'c'   x := A'*x.   

             Unchanged on exit.   

    DIAG   - CHARACTER*1.   
             On entry, DIAG specifies whether or not A is unit   
             triangular as follows:   

                DIAG = 'U' or 'u'   A is assumed to be unit triangular.   

                DIAG = 'N' or 'n'   A is not assumed to be unit   
                                    triangular.   

             Unchanged on exit.   

    N      - long.   
             On entry, N specifies the order of the matrix A.   
             N must be at least zero.   
             Unchanged on exit.   

    A      - DOUBLE PRECISION array of DIMENSION ( LDA, n ).   
             Before entry with  UPLO = 'U' or 'u', the leading n by n   
             upper triangular part of the array A must contain the upper 
  
             triangular matrix and the strictly lower triangular part of 
  
             A is not referenced.   
             Before entry with UPLO = 'L' or 'l', the leading n by n   
             lower triangular part of the array A must contain the lower 
  
             triangular matrix and the strictly upper triangular part of 
  
             A is not referenced.   
             Note that when  DIAG = 'U' or 'u', the diagonal elements of 
  
             A are not referenced either, but are assumed to be unity.   
             Unchanged on exit.   

    LDA    - long.   
             On entry, LDA specifies the first dimension of A as declared 
  
             in the calling (sub) program. LDA must be at least   
             max( 1, n ).   
             Unchanged on exit.   

    X      - DOUBLE PRECISION array of dimension at least   
             ( 1 + ( n - 1 )*abs( INCX ) ).   
             Before entry, the incremented array X must contain the n   
             element vector x. On exit, X is overwritten with the   
             tranformed vector x.   

    INCX   - long.   
             On entry, INCX specifies the increment for the elements of   
             X. INCX must not be zero.   
             Unchanged on exit.   


    Level 2 Blas routine.   

    -- Written on 22-October-1986.   
       Jack Dongarra, Argonne National Lab.   
       Jeremy Du Croz, Nag Central Office.   
       Sven Hammarling, Nag Central Office.   
       Richard Hanson, Sandia National Labs.   



       Test the input parameters.   

    
   Parameter adjustments   
       Function Body */
#define X(I) x[(I) - 1]

#define A(I,J) a[(I)-1 + ((J)-1)* ( *lda)]

    info = 0;
    if (! strcmp(uplo, "U") && ! strcmp(uplo, "L")) {
	info = 1;
    } else if (! strcmp(trans, "N") && ! strcmp(trans, "T") &&
	     ! strcmp(trans, "C")) {
	info = 2;
    } else if (! strcmp(diag, "U") && ! strcmp(diag, "N")) {
	info = 3;
    } else if (*n < 0) {
	info = 4;
    } else if (*lda < max(1,*n)) {
	info = 6;
    } else if (*incx == 0) {
	info = 8;
    }
    if (info != 0) {
	xerbla_("DTRMV ", &info);
	return 0;
    }

/*     Quick return if possible. */

    if (*n == 0) {
	return 0;
    }

    nounit = strcmp(diag, "N");

/*     Set up the start point in X if the increment is not unity. This   
       will be  ( N - 1 )*INCX  too small for descending loops. */

    if (*incx <= 0) {
	kx = 1 - (*n - 1) * *incx;
    } else if (*incx != 1) {
	kx = 1;
    }

/*     Start the operations. In this version the elements of A are   
       accessed sequentially with one pass through A. */

    if (strcmp(trans, "N")) {

/*        Form  x := A*x. */

	if (strcmp(uplo, "U")) {
	    if (*incx == 1) {
		i__1 = *n;
		for (j = 1; j <= *n; ++j) {
		    if (X(j) != 0.) {
			temp = X(j);
			i__2 = j - 1;
			for (i = 1; i <= j-1; ++i) {
			    X(i) += temp * A(i,j);
/* L10: */
			}
			if (nounit) {
			    X(j) *= A(j,j);
			}
		    }
/* L20: */
		}
	    } else {
		jx = kx;
		i__1 = *n;
		for (j = 1; j <= *n; ++j) {
		    if (X(jx) != 0.) {
			temp = X(jx);
			ix = kx;
			i__2 = j - 1;
			for (i = 1; i <= j-1; ++i) {
			    X(ix) += temp * A(i,j);
			    ix += *incx;
/* L30: */
			}
			if (nounit) {
			    X(jx) *= A(j,j);
			}
		    }
		    jx += *incx;
/* L40: */
		}
	    }
	} else {
	    if (*incx == 1) {
		for (j = *n; j >= 1; --j) {
		    if (X(j) != 0.) {
			temp = X(j);
			i__1 = j + 1;
			for (i = *n; i >= j+1; --i) {
			    X(i) += temp * A(i,j);
/* L50: */
			}
			if (nounit) {
			    X(j) *= A(j,j);
			}
		    }
/* L60: */
		}
	    } else {
		kx += (*n - 1) * *incx;
		jx = kx;
		for (j = *n; j >= 1; --j) {
		    if (X(jx) != 0.) {
			temp = X(jx);
			ix = kx;
			i__1 = j + 1;
			for (i = *n; i >= j+1; --i) {
			    X(ix) += temp * A(i,j);
			    ix -= *incx;
/* L70: */
			}
			if (nounit) {
			    X(jx) *= A(j,j);
			}
		    }
		    jx -= *incx;
/* L80: */
		}
	    }
	}
    } else {

/*        Form  x := A'*x. */

	if (strcmp(uplo, "U")) { 
	    if (*incx == 1) {
		for (j = *n; j >= 1; --j) {
		    temp = X(j);
		    if (nounit) {
			temp *= A(j,j);
		    }
		    for (i = j - 1; i >= 1; --i) {
			temp += A(i,j) * X(i);
/* L90: */
		    }
		    X(j) = temp;
/* L100: */
		}
	    } else {
		jx = kx + (*n - 1) * *incx;
		for (j = *n; j >= 1; --j) {
		    temp = X(jx);
		    ix = jx;
		    if (nounit) {
			temp *= A(j,j);
		    }
		    for (i = j - 1; i >= 1; --i) {
			ix -= *incx;
			temp += A(i,j) * X(ix);
/* L110: */
		    }
		    X(jx) = temp;
		    jx -= *incx;
/* L120: */
		}
	    }
	} else {
	    if (*incx == 1) {
		i__1 = *n;		
		for (j = 1; j <= *n; ++j) {
		    temp = 0;				// AICI ERA PROBLEMA
		    if (nounit) {
			temp *= A(j,j); 
		    }
		    i__2 = *n;
		    for (i = j ; i <= *n; ++i) {
			temp += A(i,j) * X(i); 
/* L130: */
		    }
		    X(j) = temp; 
/* L140: */
		}
	    } else {
		jx = kx;
		i__1 = *n;
		for (j = 1; j <= *n; ++j) {
		    temp = X(jx);
		    ix = jx;
		    if (nounit) {
			temp *= A(j,j);
		    }
		    i__2 = *n;
		    for (i = j + 1; i <= *n; ++i) {
			ix += *incx;
			temp += A(i,j) * X(ix);
/* L150: */
		    }
		    X(jx) = temp;
		    jx += *incx;
/* L160: */
		}
	    }
	}
    }

    return 0;

/*     End of DTRMV . */

} /* dtrmv_ */
