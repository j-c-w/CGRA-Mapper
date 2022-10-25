// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mpeg12dec.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t field1, int i, const uint8_t * p, uint8_t * cap)
{
  int cc_count = 0;
  for (i = 0; i < cc_count; i++)
    {
      cap[0] = (p[0] == 0xff && field1) ? 0xfc : 0xfd;
      cap[1] = p[1];
      cap[2] = p[2];
      cap[3] = (p[3] == 0xff && !field1) ? 0xfc : 0xfd;
      cap[4] = p[4];
      cap[5] = p[5];
      cap += 6;
      p += 6;
    }
}
