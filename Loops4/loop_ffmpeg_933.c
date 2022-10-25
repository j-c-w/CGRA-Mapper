// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/agm.c

#include <stdint.h>
#include <stdio.h>






int
fn (int chroma[64], double f, int luma[64])
{
  for (int i = 0; i < 64; i++)
    {
      luma[i] = ((1) > (16 * f) ? (1) : (16 * f));
      chroma[i] = ((1) > (16 * f) ? (1) : (16 * f));
}}
