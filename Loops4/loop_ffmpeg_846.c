// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavformat/ac3dec.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (uint16_t frame_size, uint8_t buf3[4096], int i, const uint8_t * buf2)
{
  for (i = 8; i < frame_size; i += 2)
    {
      buf3[i] = buf2[i + 1];
      buf3[i + 1] = buf2[i];
    }
}
