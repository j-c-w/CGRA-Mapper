#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;
typedef __uint16_t uint16_t;

int
fn (int alinesize, uint64_t control, unsigned int alpha0, uint16_t * dsta,
    unsigned int alpha1)
{
  int by = 0;
  int bx = 0;
  int x = 0;
  int i = 0;
  for (int j = 0; j < 4; j++)
    {
      dsta[x + (i + by * 4) * alinesize + bx * 4 + j] =
	(alpha0 + (alpha1 - alpha0) * (control & 7)) << 4;
}}
