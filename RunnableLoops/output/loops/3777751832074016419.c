#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * ccoarse, int width, uint16_t * cfine, const uint16_t * srcp)
{
  for (int j = 0; j < width; j++)
    {
      cfine[((1 << ((9 + 1) / 2)) *
	     ((width) * ((srcp[j]) >> ((9 + 1) / 2)) + (j)) +
	     ((srcp[j]) & ((1 << ((9 + 1) / 2)) - 1)))]++;
      ccoarse[((1 << ((9 + 1) / 2)) * (j) + ((srcp[j]) >> ((9 + 1) / 2)))]++;
}}
