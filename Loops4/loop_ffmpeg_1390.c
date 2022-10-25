// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/opus_silk.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (unsigned int chirp_base, int order, int k, unsigned int chirp,
    int32_t lpc32[16])
{
  for (k = 0; k < order; k++)
    {
      lpc32[k] =
	(((((int64_t) (lpc32[k]) * (int64_t) (chirp)) >> ((16) - 1)) +
	  1) >> 1);
      chirp = (chirp_base * chirp + 32768) >> 16;
    }
}
