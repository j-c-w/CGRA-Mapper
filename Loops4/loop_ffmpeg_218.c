// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/jfdctfst.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int z11, int z2, int z3, int tmp1, int tmp11, int tmp5, int tmp3,
    int tmp13, int tmp4, int tmp7, int z4, int16_t * dataptr, int tmp6,
    int tmp2, int tmp10, int ctr, int tmp0, int z13, int tmp12, int z5,
    int z1)
{
  for (ctr = 8 - 1; ctr >= 0; ctr--)
    {
      tmp0 = dataptr[0] + dataptr[7];
      tmp7 = dataptr[0] - dataptr[7];
      tmp1 = dataptr[1] + dataptr[6];
      tmp6 = dataptr[1] - dataptr[6];
      tmp2 = dataptr[2] + dataptr[5];
      tmp5 = dataptr[2] - dataptr[5];
      tmp3 = dataptr[3] + dataptr[4];
      tmp4 = dataptr[3] - dataptr[4];
      tmp10 = tmp0 + tmp3;
      tmp13 = tmp0 - tmp3;
      tmp11 = tmp1 + tmp2;
      tmp12 = tmp1 - tmp2;
      dataptr[0] = tmp10 + tmp11;
      dataptr[4] = tmp10 - tmp11;
      z1 = ((int16_t) (((tmp12 + tmp13) * (((int32_t) 181))) >> (8)));
      dataptr[2] = tmp13 + z1;
      dataptr[6] = tmp13 - z1;
      tmp10 = tmp4 + tmp5;
      tmp11 = tmp5 + tmp6;
      tmp12 = tmp6 + tmp7;
      z5 = ((int16_t) (((tmp10 - tmp12) * (((int32_t) 98))) >> (8)));
      z2 = ((int16_t) (((tmp10) * (((int32_t) 139))) >> (8))) + z5;
      z4 = ((int16_t) (((tmp12) * (((int32_t) 334))) >> (8))) + z5;
      z3 = ((int16_t) (((tmp11) * (((int32_t) 181))) >> (8)));
      z11 = tmp7 + z3;
      z13 = tmp7 - z3;
      dataptr[5] = z13 + z2;
      dataptr[3] = z13 - z2;
      dataptr[1] = z11 + z4;
      dataptr[7] = z11 - z4;
      dataptr += 8;
    }
}
