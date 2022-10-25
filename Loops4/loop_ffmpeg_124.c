// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mpegvideo_enc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int i, int level_tab[65], int start_i, const uint8_t * perm_scantable,
    int run_tab[65], int16_t * block)
{
  for (; i > start_i; i -= run_tab[i] + 1)
    {
      block[perm_scantable[i - 1]] = level_tab[i];
    }
}
