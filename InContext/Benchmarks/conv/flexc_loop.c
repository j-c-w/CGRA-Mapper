#   define NI 20
#   define NJ 25
#   define NK 30

#define DATA_TYPE_IS_INT
#  define DATA_TYPE int
#  define DATA_PRINTF_MODIFIER "%d "
# define _PB_NI POLYBENCH_LOOP_BOUND(NI,ni)
# define _PB_NJ POLYBENCH_LOOP_BOUND(NJ,nj)
# define _PB_NK POLYBENCH_LOOP_BOUND(NK,nk)

#  define POLYBENCH_RESTRICT
#  define POLYBENCH_C99_SELECT(x,y) x
# define POLYBENCH_2D(var, dim1, dim2, ddim1, ddim2) var[POLYBENCH_RESTRICT POLYBENCH_C99_SELECT(dim1,ddim1) + POLYBENCH_PADDING_FACTOR][POLYBENCH_C99_SELECT(dim2,ddim2) + POLYBENCH_PADDING_FACTOR]
#  define POLYBENCH_PADDING_FACTOR 0

int kernel(int ni, int nj, int nk,
	   DATA_TYPE alpha,
	   DATA_TYPE beta,
	   DATA_TYPE POLYBENCH_2D(C,NI,NJ,ni,nj),
	   DATA_TYPE POLYBENCH_2D(A,NI,NJ,ni,nj),
	   DATA_TYPE POLYBENCH_2D(B,NI,NJ,ni,nj))
{
  int x = 0, i = 0, j = 0, k = 0;

//BLAS PARAMS
//TRANSA = 'N'
//TRANSB = 'N'
//A is NIxNK
//B is NKxNJ
//C is NIxNJ

  int total = NI * NJ;
  int out = 0;
  // #pragma clang loop unroll_count(4) vectorize(disable)
  // #pragma clang loop unroll_count(1) vectorize_width(4)
  //#pragma clang loop vectorize_width(4)
  for (x = 0; x < total; x++) {
    i = x / NJ;
    j = x % NJ;
    out += A[i][j] * B[i][j];
  }

  /*
  for (i = 0; i < NI; i++) {
    // #pragma clang loop unroll_count(2) vectorize(disable)
    #pragma clang loop unroll_count(1) vectorize_width(4)
    for (j = 0; j < NJ; j++) {
      out += A[i][j] * B[i][j];
    }
  }
  */
  return out;
}
