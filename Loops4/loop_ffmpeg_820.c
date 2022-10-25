// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_arnndn.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, float yy, float yy_lookup[769], int maxperiod, float *x, int N)
{
  for (i = 1; i <= maxperiod; i++)
    {
      yy = yy + (x[-i] * x[-i]) - (x[N - i] * x[N - i]);
      yy_lookup[i] = ((0) > (yy) ? (0) : (yy));
    }
}
