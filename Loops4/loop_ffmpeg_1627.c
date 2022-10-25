// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/dirac_dwt.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int b2, int b1, int x, int32_t * b, const int w2, int32_t * temp, int b0)
{
  for (x = 1; x < w2; x++)
    {
      b2 =
	((unsigned) (temp[x]) +
	 ((int) (217 * (temp[x + w2 - 1] + (unsigned) temp[x + w2]) + 2048) >>
	  12));
      b1 =
	((unsigned) (temp[x + w2 - 1]) +
	 ((int) (6497 * (b0 + (unsigned) b2) + 2048) >> 12));
      b[2 * x - 1] = ~((~b1) >> 1);
      b[2 * x] = ~((~b2) >> 1);
      b0 = b2;
}}
