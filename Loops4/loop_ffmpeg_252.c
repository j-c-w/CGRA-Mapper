// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/alsdec.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (const int32_t * par, int32_t * cof, int i, unsigned int k, int j)
{
  for (i = 0, j = k - 1; i < j; i++, j--)
    {
      unsigned tmp1 =
	((((int64_t) (par[k]) * (int64_t) (cof[j])) + (1 << 19)) >> 20);
      cof[j] +=
	((((int64_t) (par[k]) * (int64_t) (cof[i])) + (1 << 19)) >> 20);
      cof[i] += tmp1;
}}
