// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_dctdnoiz.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, int g, float *dstp_b, const uint8_t * srcp, int x, int r,
    float *dstp_g, float *dstp_r, int b)
{
  for (x = 0; x < w; x++)
    {
      dstp_r[x] =
	srcp[r] * 0.5773502691896258f + srcp[g] * 0.5773502691896258f +
	srcp[b] * 0.5773502691896258f;
      dstp_g[x] =
	srcp[r] * 0.7071067811865475f + srcp[b] * -0.7071067811865475f;
      dstp_b[x] =
	srcp[r] * 0.4082482904638631f + srcp[g] * -0.8164965809277261f +
	srcp[b] * 0.4082482904638631f;
      srcp += 3;
    }
}
