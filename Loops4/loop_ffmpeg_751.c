// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/swscale.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int width, int32_t * dstU, int32_t * dstV, int i)
{
  for (i = 0; i < width; i++)
    {
      dstU[i] =
	(((dstU[i]) >
	  (30775 << 4) ? (30775 << 4) : (dstU[i])) * 4663 -
	 (9289992 << 4)) >> 12;
      dstV[i] =
	(((dstV[i]) >
	  (30775 << 4) ? (30775 << 4) : (dstV[i])) * 4663 -
	 (9289992 << 4)) >> 12;
    }
}
