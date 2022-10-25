// Source is: /home/alex/.local/share/compy-Learn/1.0/DarkNet/content/./src/blas.c

#include <stdint.h>
#include <stdio.h>






int
fn (int j, int i, float *X, float *OUT, int NX)
{
  int index = 0;
  for (i = 0; i < NX; ++i)
    {
      OUT[index++] = X[j * NX + i];
    }
}
