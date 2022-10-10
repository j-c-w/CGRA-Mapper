#include <stdint.h>
#include <stdio.h>






int
fn (int work_len, int i, float *work)
{
  for (i = 1; i < work_len / 2; i++)
    {
      work[i] *= 2;
      work[i + work_len / 2] = 0;
    }
}
