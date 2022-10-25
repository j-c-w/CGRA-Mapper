// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/rgb2rgb.c

#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;
typedef __uint8_t uint8_t;

int
fn (const int chromWidth, int i, const uint8_t * vc, const uint8_t * uc,
    const uint8_t * yc, uint64_t * ldst)
{
  for (i = 0; i < chromWidth; i += 2)
    {
      uint64_t k =
	uc[0] + (yc[0] << 8) + (vc[0] << 16) + ((unsigned) yc[1] << 24);
      uint64_t l =
	uc[1] + (yc[2] << 8) + (vc[1] << 16) + ((unsigned) yc[3] << 24);
      *ldst++ = k + (l << 32);
      yc += 4;
      uc += 2;
      vc += 2;
}}
