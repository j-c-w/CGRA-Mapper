// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/dirac_dwt.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int i, int width, int32_t * b2, int32_t * b1, int32_t * b0)
{
  for (i = 0; i < width; i++)
    {
      b1[i] =
	(b1[i] + (unsigned) ((int) (b0[i] + (unsigned) (b2[i]) + 1) >> 1));
}}
