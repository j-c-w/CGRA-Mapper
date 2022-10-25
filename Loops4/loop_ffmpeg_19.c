// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/texturedspenc.c

#include <stdint.h>
#include <stdio.h>






int
fn (float vfg, int iter, float vfr, float vfb, float covf[6])
{
  const int iter_power = 4;
  for (iter = 0; iter < iter_power; iter++)
    {
      float r = vfr * covf[0] + vfg * covf[1] + vfb * covf[2];
      float g = vfr * covf[1] + vfg * covf[3] + vfb * covf[4];
      float b = vfr * covf[2] + vfg * covf[4] + vfb * covf[5];
      vfr = r;
      vfg = g;
      vfb = b;
}}
