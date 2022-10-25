// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_afade.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, uint8_t ** dst, double gain, int c, uint8_t * const *src,
    int channels)
{
  for (c = 0; c < channels; c++)
    {
      int32_t *d = (int32_t *) dst[c];
      const int32_t *s = (int32_t *) src[c];
      d[i] = s[i] * gain;
}}
