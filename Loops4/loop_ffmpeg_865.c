// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/vorbis.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (unsigned int i, unsigned int num, uint8_t * bits, unsigned int p)
{
  for (i = p; (i < num) && (bits[i] == 0); ++i);
}
