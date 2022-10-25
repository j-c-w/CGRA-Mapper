// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/x86/mpegaudiodsp.c

#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;

int
fn (ptrdiff_t incr, float (*sumd), float *out, float (*sumc), float *out2,
    float (*suma), int j, float (*sumb))
{
  for (j = 1; j < 16; j++)
    {
      *out = -suma[j] + sumd[16 - j];
      *out2 = sumb[16 - j] + sumc[j];
      out += incr;
      out2 -= incr;
    }
}
