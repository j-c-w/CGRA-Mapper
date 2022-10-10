#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * ccoarse, const int radiusV, int width, uint16_t * cfine,
    const uint16_t * srcp)
{
  for (int i = 0; i < width; i++)
    {
      cfine[((1 << ((12 + 1) / 2)) *
	     ((width) * ((srcp[i]) >> ((12 + 1) / 2)) + (i)) +
	     ((srcp[i]) & ((1 << ((12 + 1) / 2)) - 1)))] += radiusV + 1;
      ccoarse[((1 << ((12 + 1) / 2)) * (i) +
	       ((srcp[i]) >> ((12 + 1) / 2)))] += radiusV + 1;
}}
