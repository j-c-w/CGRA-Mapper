// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_median.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const uint16_t * srcp, uint16_t * ccoarse, int width, const int radiusV,
    uint16_t * cfine)
{
  for (int i = 0; i < width; i++)
    {
      cfine[((1 << ((16 + 1) / 2)) *
	     ((width) * ((srcp[i]) >> ((16 + 1) / 2)) + (i)) +
	     ((srcp[i]) & ((1 << ((16 + 1) / 2)) - 1)))] += radiusV + 1;
      ccoarse[((1 << ((16 + 1) / 2)) * (i) +
	       ((srcp[i]) >> ((16 + 1) / 2)))] += radiusV + 1;
}}
