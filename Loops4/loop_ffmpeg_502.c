// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/ac3.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int i, int16_t * mask, uint8_t * dba_lengths, int seg, int delta,
    int band)
{
  for (i = 0; i < dba_lengths[seg]; i++)
    {
      mask[band++] += delta;
    }
}
