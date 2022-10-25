// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/dcadsp.c

#include <stdint.h>
#include <stdio.h>






int
fn (const float (*iir)[4], float tmp, int k, float (*hist)[2], float res)
{
  for (k = 0; k < 5; k++)
    {
      tmp = hist[k][0] * iir[k][0] + hist[k][1] * iir[k][1] + res;
      res = hist[k][0] * iir[k][2] + hist[k][1] * iir[k][3] + tmp;
      hist[k][0] = hist[k][1];
      hist[k][1] = tmp;
    }
}
