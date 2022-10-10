#include <stdint.h>
#include <stdio.h>






int
fn (int byte_run, int pixel_countdown, unsigned char *pixels, int pixel_ptr,
    int j, unsigned char palette_idx1)
{
  for (j = 0; j < byte_run; j++, pixel_countdown--)
    {
      pixels[pixel_ptr++] = palette_idx1;
    }
}
