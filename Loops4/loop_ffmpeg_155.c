// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/atrac3.c

#include <stdint.h>
#include <stdio.h>






int
fn (float mc1_r, float *su2, int band, float *su1, float mc1_l, int nsample,
    float mc2_r, float mc2_l)
{
  for (; nsample < band + 8; nsample++)
    {
      float c1 = su1[nsample];
      float c2 = su2[nsample];
      c2 =
	c1 * ((mc1_l) + (nsample - band) * 0.125 * ((mc2_l) - (mc1_l))) +
	c2 * ((mc1_r) + (nsample - band) * 0.125 * ((mc2_r) - (mc1_r)));
      su1[nsample] = c2;
      su2[nsample] = c1 * 2.0 - c2;
}}
