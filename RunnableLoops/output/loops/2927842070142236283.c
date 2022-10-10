#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int j, const uint8_t * buf, int n, uint8_t * ptr)
{
  for (j = 0; j < n; j++)
    {
      ptr[j * 2 + 0] = (buf[j] >> 4) & 0xF;
      ptr[j * 2 + 1] = buf[j] & 0xF;
    }
}
