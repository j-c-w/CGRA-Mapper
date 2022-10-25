// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/ralf.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int cur_len, int i, const uint8_t * data, int counts[17],
    uint8_t lens[644], int elems)
{
  int max_bits = 0;
  int nb = 0;
  for (i = 0; i < elems; i++)
    {
      cur_len = (nb ? *data & 0xF : *data >> 4) + 1;
      counts[cur_len]++;
      max_bits = ((max_bits) > (cur_len) ? (max_bits) : (cur_len));
      lens[i] = cur_len;
      data += nb;
      nb ^= 1;
    }
}
