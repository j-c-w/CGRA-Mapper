// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/lpc.c

#include <stdint.h>
#include <stdio.h>






int
fn (int j, const double *data, int i, int len)
{
  double sum = 1.0;
  for (i = j - 1; i < len; i += 2)
    {
      sum += data[i] * data[i - j] + data[i + 1] * data[i - j + 1];
    }
}
