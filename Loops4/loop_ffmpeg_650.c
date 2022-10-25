// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavformat/prompeg.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, const uint8_t * in1, int n, const uint8_t * in2, uint8_t * out)
{
  for (i = 0; i < n; i++)
    {
      out[i] = in1[i] ^ in2[i];
    }
}
