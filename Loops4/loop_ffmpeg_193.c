// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/s302menc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (const uint8_t ff_reverse[256], uint8_t vucf, uint8_t * o,
    const uint32_t * samples, int channels, const int nb_channels)
{
  for (channels = 0; channels < nb_channels; channels += 2)
    {
      o[0] = ff_reverse[(samples[0] & 0x0000FF00) >> 8];
      o[1] = ff_reverse[(samples[0] & 0x00FF0000) >> 16];
      o[2] = ff_reverse[(samples[0] & 0xFF000000) >> 24];
      o[3] = ff_reverse[(samples[1] & 0x00000F00) >> 4] | vucf;
      o[4] = ff_reverse[(samples[1] & 0x000FF000) >> 12];
      o[5] = ff_reverse[(samples[1] & 0x0FF00000) >> 20];
      o[6] = ff_reverse[(samples[1] & 0xF0000000) >> 28];
      o += 7;
      samples += 2;
    }
}
