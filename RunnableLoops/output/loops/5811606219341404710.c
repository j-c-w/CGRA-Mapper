#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int alinesize, uint16_t * dsta)
{
  int by = 0;
  int bx = 0;
  int x = 0;
  int i = 0;
  for (int j = 0; j < 4; j++)
    {
      dsta[x + (i + by * 4) * alinesize + bx * 4 + j] = 4095;
}}
