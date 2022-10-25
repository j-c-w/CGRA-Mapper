// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/x86/mpegvideoencdsp_init.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef int64_t x86_reg;

int
fn (int scale, x86_reg i, int16_t * rem, int16_t * basis)
{
  for (i = 0; i < 8 * 8; i++)
    {
      rem[i] += (basis[i] * scale + (1 << (16 - 6 - 1))) >> (16 - 6);
    }
}
