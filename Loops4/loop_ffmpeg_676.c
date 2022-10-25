// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/iirfilter.c

#include <stdint.h>
#include <stdio.h>




typedef struct FFIIRFilterCoeffs
{
  int order;
  float gain;
  int *cx;
  float *cy;
} FFIIRFilterCoeffs;

int
fn (struct FFIIRFilterCoeffs *c, double p[31][2], int order, int i)
{
  for (i = 0; i < order; i++)
    {
      c->gain += p[i][0];
      c->cy[i] =
	(-p[i][0] * p[order][0] +
	 -p[i][1] * p[order][1]) / (p[order][0] * p[order][0] +
				    p[order][1] * p[order][1]);
    }
}
