// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/takdec.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (unsigned int a2, int i, unsigned int a1, int length, int32_t * coeffs)
{
  for (i = 0; i < length - 2 >> 1; i++)
    {
      unsigned a3 = *coeffs + a1;
      unsigned a4 = a3 + a2;
      *coeffs = a4;
      a1 = coeffs[1] + a3;
      a2 = a1 + a4;
      coeffs[1] = a2;
      coeffs += 2;
}}
