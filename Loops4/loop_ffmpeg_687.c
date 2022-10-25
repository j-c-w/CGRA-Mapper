// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/acelp_vectors.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int16_t * fc_v, int pulse_signs, int i, int bits, int mask,
    const uint8_t * tab1, int pulse_indexes, int pulse_count)
{
  for (i = 0; i < pulse_count; i++)
    {
      fc_v[i + tab1[pulse_indexes & mask]] +=
	(pulse_signs & 1) ? 8191 : -8192;
      pulse_indexes >>= bits;
      pulse_signs >>= 1;
    }
}
