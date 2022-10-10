#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * out, int n, int i, const uint8_t * in2, const uint8_t * in1)
{
  for (i = 0; i < n; i++)
    {
      out[i] = in1[i] ^ in2[i];
    }
}
