// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavformat/sdsdec.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (const uint8_t * src, uint32_t * dst, int i)
{
  for (i = 0; i < 120; i += 2)
    {
      unsigned sample =
	((unsigned) src[i + 0] << 25) + ((unsigned) src[i + 1] << 18);
      dst[i / 2] = sample;
}}