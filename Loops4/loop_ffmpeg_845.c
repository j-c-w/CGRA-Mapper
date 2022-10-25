// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavutil/des.c

#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;

int
fn (int i, uint32_t r, const uint32_t S_boxes_P_shuffle[8][64], uint64_t k,
    uint32_t out)
{
  for (i = 7; i >= 0; i--)
    {
      uint8_t tmp = (r ^ k) & 0x3f;
      out |= S_boxes_P_shuffle[i][tmp];
      r = (r >> 4) | (r << 28);
      k >>= 6;
    }
}
