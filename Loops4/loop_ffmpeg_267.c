// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/on2avc.c

#include <stdint.h>
#include <stdio.h>






int
fn (int k, float *d1, int len4, const float *h2, const float *t3,
    const float *t2, float *d2, const float *h3, const float *t0,
    const float *t1, int j, int step, float *s0, const float *h1, int i,
    float *s2, float *s3, float *s1, const float *h0)
{
  for (i = 0; i < (len4 - 2) >> 1; i++)
    {
      *d1++ =
	s0[j + 0] * t0[k + 0] + s0[j + 1] * t0[k + 1] + s1[j + 0] * t1[k +
								       0] +
	s1[j + 1] * t1[k + 1] + s2[j + 0] * t2[k + 0] + s2[j + 1] * t2[k +
								       1] +
	s3[j + 0] * t3[k + 0] + s3[j + 1] * t3[k + 1];
      *d1++ =
	s0[j + 0] * t0[k + 1] - s0[j + 1] * t0[k + 0] + s1[j + 0] * t1[k +
								       1] -
	s1[j + 1] * t1[k + 0] + s2[j + 0] * t2[k + 1] - s2[j + 1] * t2[k +
								       0] +
	s3[j + 0] * t3[k + 1] - s3[j + 1] * t3[k + 0];;
      *d2++ =
	s0[j + 0] * h0[k + 0] + s0[j + 1] * h0[k + 1] + s1[j + 0] * h1[k +
								       0] +
	s1[j + 1] * h1[k + 1] + s2[j + 0] * h2[k + 0] + s2[j + 1] * h2[k +
								       1] +
	s3[j + 0] * h3[k + 0] + s3[j + 1] * h3[k + 1];
      *d2++ =
	s0[j + 0] * h0[k + 1] - s0[j + 1] * h0[k + 0] + s1[j + 0] * h1[k +
								       1] -
	s1[j + 1] * h1[k + 0] + s2[j + 0] * h2[k + 1] - s2[j + 1] * h2[k +
								       0] +
	s3[j + 0] * h3[k + 1] - s3[j + 1] * h3[k + 0];;
      j -= 2;
      k += 2 * step;
    }
}
