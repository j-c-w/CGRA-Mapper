// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/lpc.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, const double *data, int len, int j, double sum0)
{
  double sum1 = 1.0;
  for (i = j; i < len; i++)
    {
      sum0 += data[i] * data[i - j];
      sum1 += data[i] * data[i - j - 1];
    }
}
