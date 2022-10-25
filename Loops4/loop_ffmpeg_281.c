// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/sipr.c

#include <stdint.h>
#include <stdio.h>






int
fn (float tmp2[11], int i, const float ff_pow_0_55[10],
    const float ff_pow_0_7[10], const float *Az, float tmp1[49])
{
  for (i = 0; i < 10; i++)
    {
      tmp1[i + 1] = Az[i] * ff_pow_0_55[i];
      tmp2[i] = Az[i] * ff_pow_0_7[i];
    }
}
