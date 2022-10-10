#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef long int ptrdiff_t;

int
fn (unsigned int scaled_height, ptrdiff_t stride, int16_t * tmp, int k,
    int16_t * ptr)
{
  for (k = 0; k < scaled_height; k++)
    {
      tmp[k] = *ptr;
      ptr += stride;
    }
}
