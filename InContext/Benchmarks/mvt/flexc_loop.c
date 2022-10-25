#include"polybench.h"
#define DATA_TYPE int
#   define N 40

/* Main computational kernel. The whole function will be timed,
   including the call and return. */
__attribute__((noinline))
static
void kernel_mvt(int n,
		DATA_TYPE POLYBENCH_1D(x1,N,n),
		DATA_TYPE POLYBENCH_1D(x2,N,n),
		DATA_TYPE POLYBENCH_1D(y_1,N,n),
		DATA_TYPE POLYBENCH_1D(y_2,N,n),
		DATA_TYPE POLYBENCH_2D(A,N,N,n,n))
{
  int i, j;

#pragma scop
  #pragma clang loop unroll_count(1)
  for (j = 0; j < N; j++) {
    // #pragma clang loop unroll_count(1) vectorize(disable)
    #pragma clang loop unroll_count(1) vectorize_width(4)
    for (i = 0; i < N; i++) {
      x1[i] = x1[i] + A[i][j] * y_1[j];
      x2[i] = x2[i] + A[j][i] * y_2[j];
    }
  }
#pragma endscop
}
