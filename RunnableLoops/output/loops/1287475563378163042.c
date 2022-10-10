#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (const int nb_channels, const uint32_t * samples, uint8_t * o,
    uint8_t vucf, const uint8_t ff_reverse[256], int channels)
{
  for (channels = 0; channels < nb_channels; channels += 2)
    {
      o[0] = ff_reverse[(samples[0] & 0x000FF000) >> 12];
      o[1] = ff_reverse[(samples[0] & 0x0FF00000) >> 20];
      o[2] = ff_reverse[((samples[0] & 0xF0000000) >> 28) | vucf];
      o[3] = ff_reverse[(samples[1] & 0x000FF000) >> 12];
      o[4] = ff_reverse[(samples[1] & 0x0FF00000) >> 20];
      o[5] = ff_reverse[(samples[1] & 0xF0000000) >> 28];
      o += 6;
      samples += 2;
    }
}
