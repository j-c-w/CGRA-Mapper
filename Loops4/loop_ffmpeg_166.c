// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/pictordec.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int pixels_per_value, uint8_t * d, unsigned int mask, int j, int xl,
    unsigned int value, int bits_per_plane)
{
  for (; xl < pixels_per_value; xl++)
    {
      j = (j < bits_per_plane ? 8 : j) - bits_per_plane;
      d[xl] |= (value >> j) & mask;
    }
}
