// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/alsdec.c

#include <stdint.h>
#include <stdio.h>






int
fn (long k, long nbits_aligned, unsigned long j, unsigned long acc,
    unsigned char *larray)
{
  for (k = 0; k < nbits_aligned / 8; ++k)
    {
      acc = (acc << 8) + larray[j++];
    }
}
