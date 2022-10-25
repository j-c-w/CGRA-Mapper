// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/x86/dirac_dwt_init.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * tmp, int x, int w2, int16_t * b)
{
  for (; x < w2; x++)
    {
      b[2 * x] = tmp[x];
      b[2 * x + 1] = ((int) (b[x + w2] + (unsigned) (tmp[x])));
}}
