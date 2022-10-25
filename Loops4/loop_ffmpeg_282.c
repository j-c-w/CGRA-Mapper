// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/g723_1enc.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int shift, int16_t weight[10], int i)
{
  for (i = 0; i < 10; i++)
    {
      weight[i] <<= shift;
    }
}
