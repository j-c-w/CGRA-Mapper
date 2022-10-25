// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mpegaudiodsp_float.c

#include <stdint.h>
#include <stdio.h>






int
fn (float t3, int i, float *buf, float *out, float s2, float s0,
    const float icos36[9], float s3, float tmp[18], float t1, int j,
    const float icos36h[9], float t2, float *win, float s1, float t0)
{
  for (j = 0; j < 4; j++)
    {
      t0 = tmp[i];
      t1 = tmp[i + 2];
      s0 = t1 + t0;
      s2 = t1 - t0;
      t2 = tmp[i + 1];
      t3 = tmp[i + 3];
      s1 = ((2) * (icos36h[j]) * (t3 + t2));
      s3 = ((icos36[8 - j]) * (t3 - t2));
      t0 = s0 + s1;
      t1 = s0 - s1;
      out[(9 + j) * 32] = ((1) * (win[9 + j]) * (t1)) + buf[4 * (9 + j)];
      out[(8 - j) * 32] = ((1) * (win[8 - j]) * (t1)) + buf[4 * (8 - j)];
      buf[4 * (9 + j)] =
	((1) * (win[(((36) + (2 * 4) - 1) & ~((2 * 4) - 1)) / 2 + 9 + j]) *
	 (t0));
      buf[4 * (8 - j)] =
	((1) * (win[(((36) + (2 * 4) - 1) & ~((2 * 4) - 1)) / 2 + 8 - j]) *
	 (t0));
      t0 = s2 + s3;
      t1 = s2 - s3;
      out[(9 + 8 - j) * 32] =
	((1) * (win[9 + 8 - j]) * (t1)) + buf[4 * (9 + 8 - j)];
      out[j * 32] = ((1) * (win[j]) * (t1)) + buf[4 * (j)];
      buf[4 * (9 + 8 - j)] =
	((1) *
	 (win[(((36) + (2 * 4) - 1) & ~((2 * 4) - 1)) / 2 + 9 + 8 - j]) *
	 (t0));
      buf[4 * (j)] =
	((1) * (win[(((36) + (2 * 4) - 1) & ~((2 * 4) - 1)) / 2 + j]) * (t0));
      i += 4;
    }
}
