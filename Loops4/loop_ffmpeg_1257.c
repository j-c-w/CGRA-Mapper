// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/proresenc_anatoliy.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * last_line, unsigned int dst_width, int j, uint16_t * dst)
{
  for (j = 0; j < dst_width; ++j)
    {
      dst[j] = last_line[j];
    }
}
