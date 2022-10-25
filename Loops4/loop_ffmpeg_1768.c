// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/xiph.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * extradata, int *header_len, int i, int extradata_size)
{
  int overall_len = 3;
  for (; overall_len < extradata_size && *extradata == 0xff; extradata++)
    {
      header_len[i] += 0xff;
      overall_len += 0xff + 1;
    }
}
