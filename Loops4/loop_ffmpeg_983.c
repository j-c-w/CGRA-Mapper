// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_median.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (uint16_t * cfine, int width, uint16_t * ccoarse, const uint8_t * srcp)
{
  for (int j = 0; j < width; j++)
    {
      cfine[((1 << ((8 + 1) / 2)) *
	     ((width) * ((srcp[j]) >> ((8 + 1) / 2)) + (j)) +
	     ((srcp[j]) & ((1 << ((8 + 1) / 2)) - 1)))]++;
      ccoarse[((1 << ((8 + 1) / 2)) * (j) + ((srcp[j]) >> ((8 + 1) / 2)))]++;
}}
