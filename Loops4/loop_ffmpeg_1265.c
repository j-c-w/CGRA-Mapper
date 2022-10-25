// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_arnndn.c

#include <stdint.h>
#include <stdio.h>






int
fn (float y_2, float y_1, float *sum, const float *y, int len, float y_0,
    const float *x, int j, float y_3)
{
  for (j = 0; j < len - 3; j += 4)
    {
      float tmp;
      tmp = *x++;
      y_3 = *y++;
      sum[0] += tmp * y_0;
      sum[1] += tmp * y_1;
      sum[2] += tmp * y_2;
      sum[3] += tmp * y_3;
      tmp = *x++;
      y_0 = *y++;
      sum[0] += tmp * y_1;
      sum[1] += tmp * y_2;
      sum[2] += tmp * y_3;
      sum[3] += tmp * y_0;
      tmp = *x++;
      y_1 = *y++;
      sum[0] += tmp * y_2;
      sum[1] += tmp * y_3;
      sum[2] += tmp * y_0;
      sum[3] += tmp * y_1;
      tmp = *x++;
      y_2 = *y++;
      sum[0] += tmp * y_3;
      sum[1] += tmp * y_0;
      sum[2] += tmp * y_1;
      sum[3] += tmp * y_2;
}}
