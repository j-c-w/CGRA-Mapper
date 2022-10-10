#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (IDWTELEM * dst, int i, IDWTELEM * ref, IDWTELEM * src, int w)
{
  for (; i < w; i++)
    {
      dst[i] = src[i] + ((ref[i] + ref[(i + 1)] + 8 + 4 * src[i]) >> 4);
    }
}
