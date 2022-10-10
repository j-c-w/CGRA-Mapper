#include <stdint.h>
#include <stdio.h>






int
fn (int k, const float *t3, const float *h0, float *s1, const float *t0,
    const float *h2, float *s0, float *d2, int i, float *s2, int j, float *s3,
    float *d1, int step, int len4, const float *h3, const float *t1,
    const float *h1, const float *t2)
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
