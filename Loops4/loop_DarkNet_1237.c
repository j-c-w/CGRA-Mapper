// Source is: /home/alex/.local/share/compy-Learn/1.0/DarkNet/content/./src/gemm.c

#include <stdint.h>
#include <stdio.h>






int
fn (int j, int i, float BETA, int ldc, float *C, int N)
{
  for (j = 0; j < N; ++j)
    {
      C[i * ldc + j] *= BETA;
    }
}
