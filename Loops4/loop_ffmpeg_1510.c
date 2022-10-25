// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/interplayvideo.c

#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;
typedef __uint16_t uint16_t;

int
fn (uint16_t * pixel_ptr, int x, uint16_t P[4], uint64_t flags)
{
  for (x = 0; x < 8; x += 2, flags >>= 2)
    {
      pixel_ptr[x] = pixel_ptr[x + 1] = P[flags & 0x03];
    }
}
