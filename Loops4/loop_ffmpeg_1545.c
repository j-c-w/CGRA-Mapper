// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/vc2enc_dwt.c

#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef int32_t dwtcoef;

int
fn (const ptrdiff_t synth_width, dwtcoef * synthl, int x)
{
  for (x = 0; x < synth_width; x++)
    {
      synthl[x] -=
	(17 * synthl[x - synth_width] - synthl[x - 3 * synth_width] + 8) >> 4;
      synthl[x - 2 * synth_width] -=
	(9 * synthl[x - 3 * synth_width] + 8 * synthl[x - 1 * synth_width] -
	 synthl[x - 5 * synth_width] + 8) >> 4;
    }
}
