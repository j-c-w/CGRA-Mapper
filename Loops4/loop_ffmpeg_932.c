// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/agm.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t unscaled_luma[64], int luma[64], int chroma[64], double f,
    const uint8_t unscaled_chroma[64])
{
  for (int i = 0; i < 64; i++)
    {
      luma[i] =
	((1) >
	 (unscaled_luma[(i & 7) * 8 + (i >> 3)] *
	  f) ? (1) : (unscaled_luma[(i & 7) * 8 + (i >> 3)] * f));
      chroma[i] =
	((1) >
	 (unscaled_chroma[(i & 7) * 8 + (i >> 3)] *
	  f) ? (1) : (unscaled_chroma[(i & 7) * 8 + (i >> 3)] * f));
}}
