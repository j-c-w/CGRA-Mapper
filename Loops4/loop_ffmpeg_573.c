// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_noise.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int8_t int8_t;

int
fn (const int8_t * const *shift, int i, int len, const int8_t * src2,
    uint8_t * dst)
{
  for (i = 0; i < len; i++)
    {
      const int n = shift[0][i] + shift[1][i] + shift[2][i];
      dst[i] = src2[i] + ((n * src2[i]) >> 7);
}}
