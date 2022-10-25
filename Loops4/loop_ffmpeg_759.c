// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/dirac_dwt.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * b6, int32_t * dst, int i, int32_t * b5, int32_t * b3,
    int32_t * b4, int width, int32_t * b2, int32_t * b1, int32_t * b0,
    int32_t * b7)
{
  for (i = 0; i < width; i++)
    {
      dst[i] =
	((unsigned) dst[i] +
	 ((int)
	  (-2 * (b0[i] + (unsigned) b7[i]) + 10 * (b1[i] + (unsigned) b6[i]) -
	   25 * (b2[i] + (unsigned) b5[i]) + 81 * (b3[i] + (unsigned) b4[i]) +
	   128) >> 8));
}}
