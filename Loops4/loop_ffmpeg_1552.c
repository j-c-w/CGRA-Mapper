// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/dirac_dwt.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (const int w2, int x, int32_t * b, int32_t * temp)
{
  for (x = 0; x < w2; x++)
    {
      temp[x] = ((int) (b[x] - (unsigned) ((int) (b[x + w2] + 1U) >> 1)));
      temp[x + w2] = ((int) (b[x + w2] + (unsigned) (temp[x])));
}}
