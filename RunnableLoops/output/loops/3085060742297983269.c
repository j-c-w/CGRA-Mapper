#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef int32_t dwtcoef;

int
fn (const ptrdiff_t synth_width, int y, int x, const ptrdiff_t synth_height,
    dwtcoef * synthl)
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
