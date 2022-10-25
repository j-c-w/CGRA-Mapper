// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/flicvideo.c

#include <stdint.h>
#include <stdio.h>






int
fn (int pixel_countdown, int pixel_ptr, int pixel, int byte_run,
    unsigned char *pixels, int j)
{
  for (j = 0; j < byte_run; j++, pixel_countdown -= 2)
    {
      *((signed short *) (&pixels[pixel_ptr])) = pixel;
      pixel_ptr += 2;
}}
