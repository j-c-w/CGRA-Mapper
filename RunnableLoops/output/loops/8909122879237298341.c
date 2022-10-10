#include <stdint.h>
#include <stdio.h>






int
fn (int plane, double *light)
{
  for (plane = 0; plane < 3; ++plane)
    {
      light[plane] = 1.0;
    }
}
