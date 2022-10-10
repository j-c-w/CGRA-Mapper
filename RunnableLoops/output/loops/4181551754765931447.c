#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, const uint8_t * srcp_r, const uint8_t * srcp_b, float *dstp_r,
    const uint8_t * srcp_g, float *dstp_b, int w, float *dstp_g)
{
  for (x = 0; x < w; x++)
    {
      dstp_r[x] =
	srcp_r[x] * 0.5773502691896258f + srcp_g[x] * 0.5773502691896258f +
	srcp_b[x] * 0.5773502691896258f;
      dstp_g[x] =
	srcp_r[x] * 0.7071067811865475f + srcp_b[x] * -0.7071067811865475f;
      dstp_b[x] =
	srcp_r[x] * 0.4082482904638631f + srcp_g[x] * -0.8164965809277261f +
	srcp_b[x] * 0.4082482904638631f;
    }
}
