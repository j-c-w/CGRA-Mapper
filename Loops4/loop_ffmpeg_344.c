// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/ra144enc.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, const int8_t ff_cb2_vects[128][40], float cb1[40], float cb2[40],
    int cb2_idx, int cb1_idx, const int8_t ff_cb1_vects[128][40])
{
  for (i = 0; i < 40; i++)
    {
      cb1[i] = ff_cb1_vects[cb1_idx][i];
      cb2[i] = ff_cb2_vects[cb2_idx][i];
    }
}
