// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/colorspacedsp.c

#include <stdint.h>
#include <stdio.h>






int
fn (int x, int w, int *(*rnd_scratch)[2], const int rnd)
{
  for (x = 0; x < w; x++)
    {
      rnd_scratch[1][0][x] = rnd_scratch[1][1][x] = rnd_scratch[2][0][x] =
	rnd_scratch[2][1][x] = rnd;
    }
}
