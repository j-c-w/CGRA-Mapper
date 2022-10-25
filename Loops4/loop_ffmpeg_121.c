// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/x86/snowdsp.c

#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (int w, int i, IDWTELEM * ref, IDWTELEM * dst, int add, int shift, int mul,
    IDWTELEM * src)
{
  for (; i < w; i++)
    {
      dst[i] = src[i] - ((mul * (ref[i] + ref[i + 1]) + add) >> shift);
    }
}
