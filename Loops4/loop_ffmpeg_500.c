// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/jpeg2000dsp.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (const int i_ict_params[4], int i, int csize, int32_t * src2,
    int32_t * src0, int32_t i1, int32_t i2, int32_t i0, int32_t * src1)
{
  for (i = 0; i < csize; i++)
    {
      i0 = *src0 + *src2 + ((int) ((26345U * *src2) + (1 << 15)) >> 16);
      i1 =
	*src0 -
	((int) (((unsigned) i_ict_params[1] * *src1) + (1 << 15)) >> 16) -
	((int) (((unsigned) i_ict_params[2] * *src2) + (1 << 15)) >> 16);
      i2 =
	*src0 + (2 * *src1) + ((int) ((-14942U * *src1) + (1 << 15)) >> 16);
      *src0++ = i0;
      *src1++ = i1;
      *src2++ = i2;
}}
