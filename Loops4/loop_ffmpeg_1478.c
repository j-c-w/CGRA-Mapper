// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/exrenc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (uint8_t * t2, const ptrdiff_t half_size, const uint8_t * src,
    uint8_t * t1)
{
  for (ptrdiff_t i = 0; i < half_size; i++)
    {
      t1[i] = *(src++);
      t2[i] = *(src++);
}}
