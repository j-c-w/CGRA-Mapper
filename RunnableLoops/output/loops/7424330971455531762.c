#include <stdint.h>
#include <stdio.h>






int
fn (float *sum, int len, int i, const float *coef0, const float *coef1)
{
  for (i = 0; i < len; i++)
    {
      float lt = coef0[i];
      float rt = coef1[i];
      float md = lt + rt;
      float sd = lt - rt;
      sum[0] += lt * lt;
      sum[1] += rt * rt;
      sum[2] += md * md;
      sum[3] += sd * sd;
}}
