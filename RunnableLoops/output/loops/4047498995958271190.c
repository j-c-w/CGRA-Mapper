#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (IDWTELEM * temp, int x, int width, IDWTELEM * b)
{
  for (x = 2; x < width - 1; x += 2)
    {
      b[x] = temp[x] - ((temp[x - 1] + temp[x + 1] + 2) >> 2);
      b[x - 1] = temp[x - 1] + ((b[x - 2] + b[x] + 1) >> 1);
    }
}
