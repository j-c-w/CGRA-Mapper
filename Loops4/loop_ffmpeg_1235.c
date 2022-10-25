// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/h264_mb.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const int bit_depth, int j, uint16_t * tmp_cb, uint16_t * tmp_cr)
{
  for (j = 0; j < 8; j++)
    {
      tmp_cb[j] = tmp_cr[j] = 1 << (bit_depth - 1);
    }
}
