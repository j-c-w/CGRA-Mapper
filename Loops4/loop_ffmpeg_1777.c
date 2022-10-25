// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/smcenc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (uint16_t flags, const int stride, uint8_t value,
    const uint8_t * pixel_ptr)
{
  int shift = 15;
  int y = 0;
  for (int x = 0; x < 4; x++)
    {
      flags |= (value == pixel_ptr[x + y * stride]) << shift;
      shift--;
}}
