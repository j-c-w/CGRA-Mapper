// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/aacsbr.c

#include <stdint.h>
#include <stdio.h>






int
fn (float *in, float *out, int m, int B, int A, const int m_max)
{
  for (m = 0; m + 1 < m_max; m += 2)
    {
      out[2 * m] += in[m] * A;
      out[2 * m + 2] += in[m + 1] * B;
    }
}
