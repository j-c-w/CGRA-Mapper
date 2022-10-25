// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mpegaudiodec_common.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t ff_scale_factor_modshift[64])
{
  for (int i = 0; i < 64; i++)
    {
      int shift, mod;
      shift = i / 3;
      mod = i % 3;
      ff_scale_factor_modshift[i] = mod | (shift << 2);
}}
