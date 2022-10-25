// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/aacdec_fixed.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, unsigned int *dest, int c, int shift, int tmp, const int len,
    const int *src)
{
  for (i = 0; i < len; i++)
    {
      tmp = (int) (((int64_t) src[i] * c + (int64_t) 0x1000000000) >> 37);
      dest[i] += tmp * (1U << shift);
}}
