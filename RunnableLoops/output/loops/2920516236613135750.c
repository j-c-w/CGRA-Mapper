#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (IDWTELEM * line, int x, int w)
{
  for (x = 0; x < w; x++)
    {
      line[x] *= 1 << 4;
    }
}
