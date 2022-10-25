// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/flicvideo.c

#include <stdint.h>
#include <stdio.h>






int
fn (unsigned char palette_idx1, int pixel_countdown, int pixel_ptr,
    int byte_run, unsigned char *pixels, int j)
{
  for (j = 0; j < byte_run; j++, pixel_countdown--)
    {
      pixels[pixel_ptr++] = palette_idx1;
    }
}
