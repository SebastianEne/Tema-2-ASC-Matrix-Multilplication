#include "utils.h"
#include <cblas.h>

int main(int argc, char* argv[]) {
  
  /* in argv[1] primim ca parametru dimensiunea matricei pe care vrem sa o generam */
  long size_matrix = (long)atoi(argv[1]); 
  long inc = 1;
  double *mat;
  double *vec;
  int i, j;
  
  srand(time(NULL));

  /* generam matricea data */
  mat = generateMatrix(size_matrix);
  //printMatrix(mat, size_matrix);
  //printf("\n");
  
  /* generam vectorul */
  vec = generateVector(size_matrix);
  //printVector(vec, size_matrix);
  //printf("\n");
  
  /* memorez amprenta de timp T_START*/
  struct timeval t_start, t_end;
  gettimeofday(&t_start, NULL);
  
  /* rulez implementarea "de mana"*/
  dtrmv_((char*)"U",
		 (char*)"N",
		 (char*)"N",
		 (long*)&(size_matrix),
		 mat,
	     (long*)&(size_matrix),
	     vec,
	     (long*)&inc);
  
  //printVector(vec, size_matrix);
  //printf("\n");
  
  /* memorez amprenta de timp T_FINAL*/   
  gettimeofday(&t_end, NULL);
  float elapsed = ((t_end.tv_sec - t_start.tv_sec) * 1000000.0f + t_end.tv_usec - t_start.tv_usec) / 1000000.0f;
  
  /* afiseaza durata si memoreaza */
  printf("[CBLAS]nr elemente:[%ld] calculul dureaza:%f\n",size_matrix,elapsed);
  
  /* memorez amprenta de timp T_START_1 */
  struct timeval t_start_1, t_end_1;
  gettimeofday(&t_start_1, NULL);
  
  /* rulez implemntare cblas_dtrmv din ATLAS */
  cblas_dtrmv(
        CblasRowMajor,  
        CblasUpper,     
        CblasNoTrans,   
        CblasUnit,     
        size_matrix,
        mat,
        size_matrix,
        vec,
        1
  );
  
  /* memorez amprenta de timp T_FINAL */
  gettimeofday(&t_end_1, NULL);
  
  /* afisez durata si memorez */
  float elapsed_1 = ((t_end_1.tv_sec - t_start_1.tv_sec) * 1000000.0f + t_end_1.tv_usec - t_start_1.tv_usec) / 1000000.0f;
  printf("[CBLAS]nr elemente:[%ld] calculul dureaza:%f\n",size_matrix,elapsed_1);
  return 0;
}
