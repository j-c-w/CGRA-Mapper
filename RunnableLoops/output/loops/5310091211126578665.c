#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * pd, int i)
{
  for (i--; i >= 0; i--)
    {
      pd[2 * i + 1] = (pd[i] & 15) * 0x11;
      pd[2 * i + 0] = (pd[i] >> 4) * 0x11;
    }
}
