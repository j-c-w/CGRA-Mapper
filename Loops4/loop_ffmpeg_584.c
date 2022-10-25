// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/ac3dsp.c

#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __int32_t int32_t;

int
fn (int i, const int32_t * coef0, int64_t * sum, const int32_t * coef1,
    int len)
{
  for (i = 0; i < len; i++)
    {
      int lt = coef0[i];
      int rt = coef1[i];
      int md = lt + rt;
      int sd = lt - rt;
      ((sum[0]) += ((int64_t) (lt) * (int64_t) (lt)));
      ((sum[1]) += ((int64_t) (rt) * (int64_t) (rt)));
      ((sum[2]) += ((int64_t) (md) * (int64_t) (md)));
      ((sum[3]) += ((int64_t) (sd) * (int64_t) (sd)));
}}
