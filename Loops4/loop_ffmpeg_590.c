// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/aacdec_fixed.c

#include <stdint.h>
#include <stdio.h>






int
fn (int out, int i, int *coefs, unsigned int round, int c, int len, int s)
{
  for (i = 0; i < len; i++)
    {
      out = (int) (((int64_t) coefs[i] * c) >> 32);
      coefs[i] = -((int) (out + round) >> s);
}}
