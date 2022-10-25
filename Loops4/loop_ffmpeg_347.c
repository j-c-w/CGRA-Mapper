// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/ra144enc.c

#include <stdint.h>
#include <stdio.h>






int
fn (float c, int i, float *work, float g, const float *data)
{
  for (i = 0; i < 40; i++)
    {
      g += work[i] * work[i];
      c += data[i] * work[i];
    }
}
