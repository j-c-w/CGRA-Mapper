#include <stdint.h>
#include <stdio.h>






int
fn (int *tab0, int i, unsigned int tmp1, int *tab1, unsigned int tmp0)
{
  for (i = 0; i < 576; i++)
    {
      tmp0 = tab0[i];
      tmp1 = tab1[i];
      tab0[i] = tmp0 + tmp1;
      tab1[i] = tmp0 - tmp1;
    }
}
