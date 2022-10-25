// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/pcm.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int j, uint8_t * linear_to_xlaw, int mask)
{
  for (; j < 8192; j++)
    {
      linear_to_xlaw[8192 - j] = (127 ^ (mask ^ 0x80));
      linear_to_xlaw[8192 + j] = (127 ^ mask);
    }
}
