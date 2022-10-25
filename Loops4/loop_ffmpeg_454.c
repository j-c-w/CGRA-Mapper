// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/binkdsp.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (uint8_t * __restrict pixels, int16_t * block, int line_size, int i)
{
  for (i = 0; i < 8; i++)
    {
      pixels[0] += block[0];
      pixels[1] += block[1];
      pixels[2] += block[2];
      pixels[3] += block[3];
      pixels[4] += block[4];
      pixels[5] += block[5];
      pixels[6] += block[6];
      pixels[7] += block[7];
      pixels += line_size;
      block += 8;
    }
}
