#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;
typedef long int ptrdiff_t;

int
fn (int i, const uint8_t * pixels, int16_t * __restrict block,
    ptrdiff_t line_size)
{
  for (i = 0; i < 4; i++)
    {
      block[0] = pixels[0];
      block[1] = pixels[1];
      block[2] = pixels[2];
      block[3] = pixels[3];
      block[4] = pixels[4];
      block[5] = pixels[5];
      block[6] = pixels[6];
      block[7] = pixels[7];
      pixels += line_size;
      block += 8;
    }
}
