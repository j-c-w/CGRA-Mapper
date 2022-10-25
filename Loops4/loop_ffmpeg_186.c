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
      int16_t *d = (int16_t *) dst[c];
      const int16_t *s = (int16_t *) src[c];
      d[i] = s[i] * gain;
}}
