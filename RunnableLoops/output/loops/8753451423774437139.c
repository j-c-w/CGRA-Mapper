#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * s4, const uint8_t * s1, uint8_t * d, int width,
    const uint8_t * s3, const uint8_t * s2, int w)
{
  for (w = width; w > 0; w--)
    {
      d[0] =
	(s1[0] + s1[1] + s1[2] + s1[3] + s2[0] + s2[1] + s2[2] + s2[3] +
	 s3[0] + s3[1] + s3[2] + s3[3] + s4[0] + s4[1] + s4[2] + s4[3] +
	 8) >> 4;
      s1 += 4;
      s2 += 4;
      s3 += 4;
      s4 += 4;
      d++;
    }
}
