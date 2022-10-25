// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/rpza.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * pixels, int block_ptr, uint16_t colorA, int pixel_x)
{
  for (pixel_x = 0; pixel_x < 4; pixel_x++)
    {
      pixels[block_ptr] = colorA;
      block_ptr++;
    }
}
