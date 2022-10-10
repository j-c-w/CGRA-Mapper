#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * framebuf, int i, int right, int off)
{
  for (i = 0; i < right; i++)
    {
      framebuf[off + i] = 0x80;
    }
}
