#include "polybench.h"
#include "bicg.h"

void kernel(int m, int n,
	    DATA_TYPE POLYBENCH_2D(A,N,M,n,m),
	    DATA_TYPE POLYBENCH_1D(s,M,m),
	    DATA_TYPE POLYBENCH_1D(q,N,n),
	    DATA_TYPE POLYBENCH_1D(p,M,m),
	    DATA_TYPE POLYBENCH_1D(r,N,n)) {
  int i, j;

//#pragma scop
  for (i = 0; i < _PB_N; i++)
    {
      q[i] = SCALAR_VAL(0.0);
      for (j = 0; j < _PB_M; j++)
      {
        s[j] = s[j] + r[i] * A[i][j];
        q[i] = q[i] + A[i][j] * p[j];
      }
    }
//#pragma endscop

}
