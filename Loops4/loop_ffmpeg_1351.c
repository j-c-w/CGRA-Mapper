// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/opus_rc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (unsigned int k, unsigned int symbol, const uint16_t * cdf)
{
  for (k = 0; cdf[k] <= symbol; k++);
}
