// Source is: /home/alex/.local/share/compy-Learn/1.0/DarkNet/content/./src/blas.c

#include <stdint.h>
#include <stdio.h>






int
fn (int j, float *Y, int NY, int i, float *OUT)
{
  int index = 0;
  for (i = 0; i < NY; ++i)
    {
      OUT[index++] = Y[j * NY + i];
    }
}
