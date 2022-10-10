#include <stdint.h>
#include <stdio.h>




typedef int DWTELEM;

int
fn (const int width2, int x, DWTELEM * temp, const int w2, DWTELEM * b)
{
  for (x = 0; x < width2; x++)
    {
      temp[x] = b[2 * x];
      temp[x + w2] = b[2 * x + 1];
    }
}
