// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mpegaudioenc_float.c

#include <stdint.h>
#include <stdio.h>






int
fn (int xr, int *tab, int i, const int *xp)
{
  for (i = 0; i < 4; i++)
    {
      xr = (((int64_t) (tab[30 - i * 4]) * (int64_t) (xp[0])) >> 15);
      tab[30 - i * 4] = (tab[i * 4] - xr);
      tab[i * 4] = (tab[i * 4] + xr);
      xr = (((int64_t) (tab[2 + i * 4]) * (int64_t) (xp[1])) >> 15);
      tab[2 + i * 4] = (tab[28 - i * 4] - xr);
      tab[28 - i * 4] = (tab[28 - i * 4] + xr);
      xr = (((int64_t) (tab[31 - i * 4]) * (int64_t) (xp[0])) >> 15);
      tab[31 - i * 4] = (tab[1 + i * 4] - xr);
      tab[1 + i * 4] = (tab[1 + i * 4] + xr);
      xr = (((int64_t) (tab[3 + i * 4]) * (int64_t) (xp[1])) >> 15);
      tab[3 + i * 4] = (tab[29 - i * 4] - xr);
      tab[29 - i * 4] = (tab[29 - i * 4] + xr);
      xp += 2;
    }
}
