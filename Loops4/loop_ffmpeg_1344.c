// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/ilbcdec.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int32_t int32_t;

int
fn (int32_t * f, int16_t * lsp, int i, int16_t low, int k, int16_t high,
    int32_t tmp, int j, int l)
{
  for (j = i; j > 1; j--, l--)
    {
      high = f[l - 1] >> 16;
      low = (f[l - 1] - (high * (1 << 16))) >> 1;
      tmp = ((high * lsp[k]) * 4) + (((low * lsp[k]) >> 15) * 4);
      f[l] += f[l - 2];
      f[l] -= (unsigned) tmp;
}}
