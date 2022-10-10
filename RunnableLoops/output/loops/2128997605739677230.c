#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int length, int i, int32_t * p2, int order_half, int length2,
    int32_t * p1)
{
  for (i = length2 + order_half; i < length; i++)
    {
      int32_t a = p1[i];
      int32_t b = p2[i];
      p1[i] = a + b;
    }
}
