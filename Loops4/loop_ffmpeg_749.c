// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/utvideoenc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;
typedef __uint8_t uint8_t;

int
fn (uint64_t * counts, uint8_t * src, int width, int i)
{
  for (i = 0; i < width; i++)
    {
      counts[src[i]]++;
    }
}
