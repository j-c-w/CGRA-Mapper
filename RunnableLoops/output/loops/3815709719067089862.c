#include <stdint.h>
#include <stdio.h>






int
fn (int work_len, float *work, int i)
{
  for (i = 1; i < work_len / 2; i++)
    {
      work[i] *= 2;
      work[i + work_len / 2] = 0;
    }
}
