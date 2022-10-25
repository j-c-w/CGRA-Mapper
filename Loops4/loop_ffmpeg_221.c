// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/jfdctfst.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int tmp13, int z1, int tmp0, int tmp4, int tmp7, int tmp1, int tmp3,
    int16_t * dataptr, int tmp6, int tmp11, int tmp5, int tmp2, int tmp10,
    int ctr, int tmp12)
{
  for (ctr = 8 - 1; ctr >= 0; ctr--)
    {
      tmp0 = dataptr[8 * 0] + dataptr[8 * 1];
      tmp1 = dataptr[8 * 2] + dataptr[8 * 3];
      tmp2 = dataptr[8 * 4] + dataptr[8 * 5];
      tmp3 = dataptr[8 * 6] + dataptr[8 * 7];
      tmp4 = dataptr[8 * 0] - dataptr[8 * 1];
      tmp5 = dataptr[8 * 2] - dataptr[8 * 3];
      tmp6 = dataptr[8 * 4] - dataptr[8 * 5];
      tmp7 = dataptr[8 * 6] - dataptr[8 * 7];
      tmp10 = tmp0 + tmp3;
      tmp11 = tmp1 + tmp2;
      tmp12 = tmp1 - tmp2;
      tmp13 = tmp0 - tmp3;
      dataptr[8 * 0] = tmp10 + tmp11;
      dataptr[8 * 4] = tmp10 - tmp11;
      z1 = ((int16_t) (((tmp12 + tmp13) * (((int32_t) 181))) >> (8)));
      dataptr[8 * 2] = tmp13 + z1;
      dataptr[8 * 6] = tmp13 - z1;
      tmp10 = tmp4 + tmp7;
      tmp11 = tmp5 + tmp6;
      tmp12 = tmp5 - tmp6;
      tmp13 = tmp4 - tmp7;
      dataptr[8 * 1] = tmp10 + tmp11;
      dataptr[8 * 5] = tmp10 - tmp11;
      z1 = ((int16_t) (((tmp12 + tmp13) * (((int32_t) 181))) >> (8)));
      dataptr[8 * 3] = tmp13 + z1;
      dataptr[8 * 7] = tmp13 - z1;
      dataptr++;
    }
}
