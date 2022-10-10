#include <stdint.h>
#include <stdio.h>






int
fn (int len, float v1, float tmp0, float *tab0, float v2, int j, float *tab1)
{
  for (j = 0; j < len; j++)
    {
      tmp0 = tab0[j];
      tab0[j] = ((v1) * (tmp0));
      tab1[j] = ((v2) * (tmp0));
    }
}
