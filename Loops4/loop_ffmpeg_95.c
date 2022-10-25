// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/x86/snowdsp.c

#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (IDWTELEM * temp, int i, IDWTELEM * b)
{
  for (; (i & 0x3E) != 0x3E; i -= 2)
    {
      b[i + 1] = temp[i >> 1];
      b[i] = b[i >> 1];
    }
}
