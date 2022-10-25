// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/ilbcdec.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t veclen, int16_t * decvector, int16_t cbvec0[40],
    int16_t cbvec1[40], int16_t * gainPtr, unsigned int a32,
    int16_t cbvec2[40], int j)
{
  for (j = 0; j < veclen; j++)
    {
      a32 = ((int32_t) (((int16_t) (*gainPtr++)) * ((int16_t) (cbvec0[j]))));
      a32 += ((int32_t) (((int16_t) (*gainPtr++)) * ((int16_t) (cbvec1[j]))));
      a32 += ((int32_t) (((int16_t) (*gainPtr)) * ((int16_t) (cbvec2[j]))));
      gainPtr -= 2;
      decvector[j] = (int) (a32 + 8192) >> 14;
}}
