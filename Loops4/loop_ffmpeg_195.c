// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/s302menc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (const uint8_t ff_reverse[256], uint8_t vucf, uint8_t * o, int channels,
    const uint16_t * samples, const int nb_channels)
{
  for (channels = 0; channels < nb_channels; channels += 2)
    {
      o[0] = ff_reverse[samples[0] & 0xFF];
      o[1] = ff_reverse[(samples[0] & 0xFF00) >> 8];
      o[2] = ff_reverse[(samples[1] & 0x0F) << 4] | vucf;
      o[3] = ff_reverse[(samples[1] & 0x0FF0) >> 4];
      o[4] = ff_reverse[(samples[1] & 0xF000) >> 12];
      o += 5;
      samples += 2;
    }
}
