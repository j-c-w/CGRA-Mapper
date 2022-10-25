// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/qdm2.c

#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;

int
fn (int i, uint8_t random_dequant_index[256][5], uint64_t random_seed, int j,
    uint32_t ldw)
{
  for (j = 0; j < 5; j++)
    {
      random_dequant_index[i][j] = ldw / random_seed;
      ldw %= random_seed;
      random_seed /= 3;
    }
}
