#include <stdint.h>
#include <stdio.h>






int
fn (int byte_run, unsigned char *pixels, int pixel_countdown, int pixel_ptr,
    int j, int pixel)
{
  for (j = 0; j < byte_run; j++, pixel_countdown -= 2)
    {
      *((signed short *) (&pixels[pixel_ptr])) = pixel;
      pixel_ptr += 2;
}}
