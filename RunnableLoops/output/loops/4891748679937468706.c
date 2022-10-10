#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * cfine, int width, const uint16_t * srcp, uint16_t * ccoarse)
{
  for (int j = 0; j < width; j++)
    {
      cfine[((1 << ((14 + 1) / 2)) *
	     ((width) * ((srcp[j]) >> ((14 + 1) / 2)) + (j)) +
	     ((srcp[j]) & ((1 << ((14 + 1) / 2)) - 1)))]++;
      ccoarse[((1 << ((14 + 1) / 2)) * (j) +
	       ((srcp[j]) >> ((14 + 1) / 2)))]++;
}}
