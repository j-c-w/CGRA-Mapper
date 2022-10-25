// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/vc2enc_dwt.c

#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef int32_t dwtcoef;

int
fn (const ptrdiff_t synth_width, int y, dwtcoef * synthl, int x,
    const ptrdiff_t synth_height)
{
  for (y = 0; y < synth_height; y += 2)
    {
      synthl[(y + 1) * synth_width + x] =
	synthl[(y + 1) * synth_width + x] - synthl[y * synth_width + x];
      synthl[y * synth_width + x] =
	synthl[y * synth_width + x] +
	((synthl[(y + 1) * synth_width + x] + 1) >> 1);
    }
}
