// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/lpc.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int i, double w, double *w_data, int n2, double c, const int32_t * data)
{
  for (i = 0; i < n2; i++)
    {
      w = c - n2 + i;
      w = 1.0 - (w * w);
      w_data[-i - 1] = data[-i - 1] * w;
      w_data[+i] = data[+i] * w;
    }
}
