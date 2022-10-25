// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/ra144enc.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, float zero[40], const int16_t * sblock_data, float data[40],
    float work[50])
{
  for (i = 0; i < 40; i++)
    {
      zero[i] = work[10 + i];
      data[i] = sblock_data[i] - zero[i];
    }
}
