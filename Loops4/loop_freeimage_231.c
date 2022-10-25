// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJPEG/jfdctflt.c

#include <stdint.h>
#include <stdio.h>






int
fn (float tmp0, float z11, float tmp2, float tmp3, float tmp10, float z5,
    float z13, int ctr, float tmp5, float *dataptr, float z4, float tmp4,
    float tmp1, float tmp6, float z3, float z1, float tmp13, float tmp11,
    float tmp7, float tmp12, float z2)
{
  for (ctr = 8 - 1; ctr >= 0; ctr--)
    {
      tmp0 = dataptr[8 * 0] + dataptr[8 * 7];
      tmp7 = dataptr[8 * 0] - dataptr[8 * 7];
      tmp1 = dataptr[8 * 1] + dataptr[8 * 6];
      tmp6 = dataptr[8 * 1] - dataptr[8 * 6];
      tmp2 = dataptr[8 * 2] + dataptr[8 * 5];
      tmp5 = dataptr[8 * 2] - dataptr[8 * 5];
      tmp3 = dataptr[8 * 3] + dataptr[8 * 4];
      tmp4 = dataptr[8 * 3] - dataptr[8 * 4];
      tmp10 = tmp0 + tmp3;
      tmp13 = tmp0 - tmp3;
      tmp11 = tmp1 + tmp2;
      tmp12 = tmp1 - tmp2;
      dataptr[8 * 0] = tmp10 + tmp11;
      dataptr[8 * 4] = tmp10 - tmp11;
      z1 = (tmp12 + tmp13) * ((float) 0.707106781);
      dataptr[8 * 2] = tmp13 + z1;
      dataptr[8 * 6] = tmp13 - z1;
      tmp10 = tmp4 + tmp5;
      tmp11 = tmp5 + tmp6;
      tmp12 = tmp6 + tmp7;
      z5 = (tmp10 - tmp12) * ((float) 0.382683433);
      z2 = ((float) 0.541196100) * tmp10 + z5;
      z4 = ((float) 1.306562965) * tmp12 + z5;
      z3 = tmp11 * ((float) 0.707106781);
      z11 = tmp7 + z3;
      z13 = tmp7 - z3;
      dataptr[8 * 5] = z13 + z2;
      dataptr[8 * 3] = z13 - z2;
      dataptr[8 * 1] = z11 + z4;
      dataptr[8 * 7] = z11 - z4;
      dataptr++;
}}
