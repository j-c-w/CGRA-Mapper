#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint32_t uint32_t;

int
fn (const uint32_t ff_inverse[257], int32_t * audio, int n, int offset,
    int div, int levels, int code2)
{
  for (; n < 8; n++)
    {
      div = ((uint32_t) ((((uint64_t) code2) * ff_inverse[levels]) >> 32));
      audio[n] = code2 - div * levels - offset;
      code2 = div;
    }
}
