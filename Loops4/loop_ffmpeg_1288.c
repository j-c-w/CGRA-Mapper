// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/bmp.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * ptr, int j, const uint8_t * buf, int n)
{
  for (j = 0; j < n; j++)
    {
      ptr[j * 2 + 0] = (buf[j] >> 4) & 0xF;
      ptr[j * 2 + 1] = buf[j] & 0xF;
    }
}
