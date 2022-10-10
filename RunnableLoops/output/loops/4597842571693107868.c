#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int b, int x, float *dstp_r, int r, const uint8_t * srcp, float *dstp_b,
    int g, int w, float *dstp_g)
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
