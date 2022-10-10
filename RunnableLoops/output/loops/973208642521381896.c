#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (int y, int x, int w, IDWTELEM * buf)
{
  for (x = 0; x < w; x++)
    {
      buf[x + y * w] -= 128 << 4;
    }
}
