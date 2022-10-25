// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/4xm.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int z10, int z11, int tmp1, int tmp11, int tmp5, int tmp3, int tmp13,
    int tmp4, int tmp7, int tmp6, int temp[64], int tmp2, int tmp10, int tmp0,
    int z12, int z13, int tmp12, int z5, int i, int16_t * block)
{
  for (i = 0; i < 8; i++)
    {
      tmp10 = block[8 * 0 + i] + block[8 * 4 + i];
      tmp11 = block[8 * 0 + i] - block[8 * 4 + i];
      tmp13 = block[8 * 2 + i] + block[8 * 6 + i];
      tmp12 =
	((int) ((block[8 * 2 + i] - block[8 * 6 + i]) * (unsigned) (92682)) >>
	 16) - tmp13;
      tmp0 = tmp10 + tmp13;
      tmp3 = tmp10 - tmp13;
      tmp1 = tmp11 + tmp12;
      tmp2 = tmp11 - tmp12;
      z13 = block[8 * 5 + i] + block[8 * 3 + i];
      z10 = block[8 * 5 + i] - block[8 * 3 + i];
      z11 = block[8 * 1 + i] + block[8 * 7 + i];
      z12 = block[8 * 1 + i] - block[8 * 7 + i];
      tmp7 = z11 + z13;
      tmp11 = ((int) ((z11 - z13) * (unsigned) (92682)) >> 16);
      z5 = ((int) ((z10 + z12) * (unsigned) (121095)) >> 16);
      tmp10 = ((int) ((z12) * (unsigned) (70936)) >> 16) - z5;
      tmp12 = ((int) ((z10) * (unsigned) (-171254)) >> 16) + z5;
      tmp6 = tmp12 - tmp7;
      tmp5 = tmp11 - tmp6;
      tmp4 = tmp10 + tmp5;
      temp[8 * 0 + i] = tmp0 + tmp7;
      temp[8 * 7 + i] = tmp0 - tmp7;
      temp[8 * 1 + i] = tmp1 + tmp6;
      temp[8 * 6 + i] = tmp1 - tmp6;
      temp[8 * 2 + i] = tmp2 + tmp5;
      temp[8 * 5 + i] = tmp2 - tmp5;
      temp[8 * 4 + i] = tmp3 + tmp4;
      temp[8 * 3 + i] = tmp3 - tmp4;
}}
