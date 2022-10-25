// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/dirac_dwt.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (const int w2, int x, int32_t * b, int32_t * temp)
{
  for (x = 1; x < w2; x++)
    {
      temp[x] =
	(b[x] -
	 (unsigned) ((int) (b[x + w2 - 1] + (unsigned) (b[x + w2]) + 2) >>
		     2));
      temp[x + w2 - 1] =
	(b[x + w2 - 1] +
	 (unsigned) ((int) (temp[x - 1] + (unsigned) (temp[x]) + 1) >> 1));
}}
