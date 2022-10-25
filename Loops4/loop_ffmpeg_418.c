// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mpegaudiodec_float.c

#include <stdint.h>
#include <stdio.h>






int
fn (float out2[12], float *out_ptr, float *buf, int i, float *win)
{
  for (i = 0; i < 6; i++)
    {
      *out_ptr = ((1) * (win[i]) * (out2[i])) + buf[4 * (i + 6 * 2)];
      buf[4 * (i + 6 * 0)] = ((1) * (win[i + 6]) * (out2[i + 6]));
      out_ptr += 32;
    }
}
