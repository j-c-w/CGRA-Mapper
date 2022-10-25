// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/pcm.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int v, unsigned char *dst, uint8_t linear_to_alaw[16384], int n,
    const short *samples)
{
  for (; n > 0; n--)
    {
      v = *samples++;
      *dst++ = linear_to_alaw[(v + 32768) >> 2];
    }
}
