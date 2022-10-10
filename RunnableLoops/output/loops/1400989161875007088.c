#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int min_width, int B, int A, int i, const ptrdiff_t stride2, int C,
    uint8_t * bsrc)
{
  for (i = 1; i < min_width; i++)
    {
      A = bsrc[i - stride2];
      B = bsrc[i - (stride2 + 1)];
      C = bsrc[i - 1];
      bsrc[i] = (A - B + C + bsrc[i]) & 0xFF;
    }
}
