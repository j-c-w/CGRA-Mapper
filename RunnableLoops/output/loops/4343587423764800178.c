#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * dstV, int i, int width, int32_t * dstU)
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
