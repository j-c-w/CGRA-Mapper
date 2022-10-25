// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/dirac_dwt.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int i, int32_t * b3, int32_t * b4, int width, int32_t * b2, int32_t * b1,
    int32_t * b0)
{
  for (i = 0; i < width; i++)
    {
      b2[i] =
	(int) (((unsigned) (b2[i]) -
		((int) (9U * b1[i] + 9U * b3[i] - b4[i] - b0[i] + 16) >> 5)));
}}
