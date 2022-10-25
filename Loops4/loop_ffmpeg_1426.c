// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/aacsbr_fixed.c

#include <stdint.h>
#include <stdio.h>




typedef SoftFloat;
typedef SoftFloat AAC_FLOAT;
typedef __uint16_t uint16_t;

int
fn (int p, int e, AAC_FLOAT (*e_curr)[48], int kx1, SoftFloat sum, int k,
    const uint16_t * table)
{
  for (k = table[p]; k < table[p + 1]; k++)
    {
      e_curr[e][k - kx1] = sum;
    }
}
