#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (uint16_t * ccoarse, int width, uint16_t * cfine, const uint8_t * p)
{
  for (int j = 0; j < width; j++)
    {
      cfine[((1 << ((8 + 1) / 2)) *
	     ((width) * ((p[j]) >> ((8 + 1) / 2)) + (j)) +
	     ((p[j]) & ((1 << ((8 + 1) / 2)) - 1)))]--;
      ccoarse[((1 << ((8 + 1) / 2)) * (j) + ((p[j]) >> ((8 + 1) / 2)))]--;
}}
