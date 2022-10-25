// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/qcelpdec.c

#include <stdint.h>
#include <stdio.h>






int
fn (const float pow_0_775[10], int n, float lpc_p[10], float *lpc,
    const float pow_0_625[10], float lpc_s[10])
{
  for (n = 0; n < 10; n++)
    {
      lpc_s[n] = lpc[n] * pow_0_625[n];
      lpc_p[n] = lpc[n] * pow_0_775[n];
    }
}
