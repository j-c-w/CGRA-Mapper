// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/smc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int prev_block_ptr, int block_ptr, int pixel_x, uint8_t * const pixels)
{
  for (pixel_x = 0; pixel_x < 4; pixel_x++)
    {
      pixels[block_ptr++] = pixels[prev_block_ptr++];
    }
}
