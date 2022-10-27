#  define DATA_TYPE int
#  define DATA_PRINTF_MODIFIER "%d "
#   define NI 20
#   define NJ 25
#   define NK 30
#  define POLYBENCH_PADDING_FACTOR 0
#  define POLYBENCH_C99_SELECT(x,y) x
#define POLYBENCH_RESTRICT
# define POLYBENCH_2D(var, dim1, dim2, ddim1, ddim2) var[POLYBENCH_RESTRICT POLYBENCH_C99_SELECT(dim1,ddim1) + POLYBENCH_PADDING_FACTOR][POLYBENCH_C99_SELECT(dim2,ddim2) + POLYBENCH_PADDING_FACTOR]
void kernel(int ni, int nj, int nk,
	   DATA_TYPE POLYBENCH_2D(C,NI,NJ,ni,nj),
	   DATA_TYPE POLYBENCH_2D(A,NI,NJ,ni,nj),
	   DATA_TYPE POLYBENCH_2D(B,NI,NJ,ni,nj))
{
  int x = 0, i = 0, j = 0, k = 0;
  int total = NI * NJ;
  // #pragma clang loop vectorize(disable) unroll_count(4)
  // #pragma clang loop vectorize(enable) vectorize_width(4) unroll_count(4)
  for (x = 0; x < total; x++) {
    i = x / NJ;
    j = x % NJ;
    if (A[i][j] < 0)
      C[i][j] = 0;
    else
      C[i][j] = A[i][j];
  }
}
