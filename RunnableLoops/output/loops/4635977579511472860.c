#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (IDWTELEM * dst, int shift, int i, IDWTELEM * ref, int add, IDWTELEM * src,
    int mul, int w)
{
  for (; i < w; i++)
    {
      dst[i] = src[i] - ((mul * (ref[i] + ref[i + 1]) + add) >> shift);
    }
}
