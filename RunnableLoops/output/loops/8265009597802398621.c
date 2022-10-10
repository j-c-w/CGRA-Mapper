#include <stdint.h>
#include <stdio.h>






int
fn (int byte_run, int pixel_countdown, unsigned char *pixels, int pixel_ptr,
    int j, int pixel)
{
  for (j = 0; j < byte_run; j++, pixel_countdown -= 1)
    {
      do
	{
	  ((uint8_t *) (&pixels[pixel_ptr]))[0] = (pixel);
	  ((uint8_t *) (&pixels[pixel_ptr]))[1] = (pixel) >> 8;
	  ((uint8_t *) (&pixels[pixel_ptr]))[2] = (pixel) >> 16;
	}
      while (0);
      pixel_ptr += 3;
    }
}
