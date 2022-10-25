// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/ra144.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, int *bp2, int *bp1, int *refl, int j, int b)
{
  for (j = 0; j <= i; j++)
    {
      bp1[j] =
	(int) ((bp2[j] -
		((int) (refl[i + 1] * (unsigned) bp2[i - j]) >> 12)) *
	       (unsigned) b) >> 12;
}}
