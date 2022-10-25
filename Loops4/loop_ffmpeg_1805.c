// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_xmedian.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int nb_inputs, uint8_t ** srcf, uint8_t values[256])
{
  int x = 0;
  for (int i = 0; i < nb_inputs; i++)
    {
      const uint8_t *src = (const uint8_t *) srcf[i];
      values[i] = src[x];
}}
