#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (IDWTELEM * dst, int i, IDWTELEM * ref, int add, int mul, IDWTELEM * src,
    int shift, int w)
{
  for (; i < w; i++)
    {
      dst[i] = src[i] - ((mul * (ref[i] + ref[i + 1]) + add) >> shift);
    }
}
