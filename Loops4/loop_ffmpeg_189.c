// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_afade.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, uint8_t * const *cf1, double gain0, uint8_t ** dst,
    uint8_t * const *cf0, double gain1, int c, int channels)
{
  for (c = 0; c < channels; c++)
    {
      int32_t *d = (int32_t *) dst[c];
      const int32_t *s0 = (int32_t *) cf0[c];
      const int32_t *s1 = (int32_t *) cf1[c];
      d[i] = s0[i] * gain0 + s1[i] * gain1;
}}
