// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/aacsbr.c

#include <stdint.h>
#include <stdio.h>






int
fn (const float h_smooth[5], float *g_filt, const int h_SL, int m,
    float (*g_temp)[48], float (*q_temp)[48], int j, float *q_filt,
    const int idx1)
{
  for (j = 0; j <= h_SL; j++)
    {
      g_filt[m] += g_temp[idx1 - j][m] * h_smooth[j];
      q_filt[m] += q_temp[idx1 - j][m] * h_smooth[j];
    }
}
