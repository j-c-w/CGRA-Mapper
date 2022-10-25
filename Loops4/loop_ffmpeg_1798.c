// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_v360.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (const int16_t * const kker, const int iws, ptrdiff_t in_linesize,
    const int16_t * const vv, const int16_t * const uu,
    const uint16_t * const s)
{
  int tmp = 0;
  for (int j = 0; j < 4; j++)
    {
      tmp += kker[iws + j] * s[vv[iws + j] * in_linesize + uu[iws + j]];
}}
