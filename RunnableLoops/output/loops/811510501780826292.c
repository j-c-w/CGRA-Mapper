#include <stdint.h>
#include <stdio.h>






int
fn (int len, int *tab0, int v1, int j, int *tab1, int v2, unsigned int tmp0)
{
  for (j = 0; j < len; j++)
    {
      tmp0 = tab0[j];
      tab0[j] = (((int64_t) ((int) (tmp0)) * (int64_t) ((v1))) >> (23));
      tab1[j] = (((int64_t) ((int) (tmp0)) * (int64_t) ((v2))) >> (23));
}}
