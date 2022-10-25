#include "polybench.h"

# define _PB_NI POLYBENCH_LOOP_BOUND(NI,ni)
# define _PB_NJ POLYBENCH_LOOP_BOUND(NJ,nj)
# define _PB_NK POLYBENCH_LOOP_BOUND(NK,nk)

#   define NI 20
#   define NJ 25
#   define NK 30

void kernel(int ni, int nj, int nk,
		 int POLYBENCH_2D(C,NI,NJ,ni,nj),
		 int POLYBENCH_2D(A,NI,NK,ni,nk),
		 int POLYBENCH_2D(B,NK,NJ,nk,nj))
{
  int x, i, j, k;

//BLAS PARAMS
//TRANSA = 'N'
//TRANSB = 'N'
// => Form C := A*B + C,
//A is NIxNK
//B is NKxNJ
//C is NIxNJ
//#pragma scop
  for (i = 0; i < _PB_NI; i++) {
    for (k = 0; k < _PB_NK; k++) {
       #pragma clang loop vectorize(disable) unroll_count(4)
       // #pragma clang loop vectorize_width(4) unroll_count(4)
       for (j = 0; j < _PB_NJ; j++)
	  C[i][j] += A[i][k] * B[k][j];
    }
  }
//#pragma endscop
/*
  int total = _PB_NI*_PB_NJ*_PB_NK;
  //#pragma clang loop unroll_count(2)
  #pragma clang loop vectorize_width(4)
  for (x = 0; x < total; x++) {
    i = x / _PB_NK / _PB_NJ;
    k = (x / _PB_NJ) % _PB_NK;
    j = x % _PB_NJ;
    C[i][j] += A[i][k] * B[k][j];
  }
*/
}
