#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int j, const uint8_t * buf, int len, int r)
{
  for (j = 0; j < r; j++)
    {
      __attribute__((unused)) int p_diff = buf[0];
      buf++;
      len--;
}}
