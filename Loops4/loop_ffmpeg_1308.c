// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/snow_dwt.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, int i, int tmp[1024], uint8_t * pix1, uint8_t * pix2, int j)
{
  for (j = 0; j < w; j += 4)
    {
      tmp[32 * i + j + 0] = (pix1[j + 0] - pix2[j + 0]) << 4;
      tmp[32 * i + j + 1] = (pix1[j + 1] - pix2[j + 1]) << 4;
      tmp[32 * i + j + 2] = (pix1[j + 2] - pix2[j + 2]) << 4;
      tmp[32 * i + j + 3] = (pix1[j + 3] - pix2[j + 3]) << 4;
    }
}
