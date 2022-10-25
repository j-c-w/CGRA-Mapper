// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/h264_cavlc.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int level[16], int i, int16_t * block, int total_coeff,
    const uint8_t * scantable)
{
  for (; i < total_coeff; i++)
    {
      scantable--;
      ((int32_t *) block)[*scantable] = level[i];
    }
}
