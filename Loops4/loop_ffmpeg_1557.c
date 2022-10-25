// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/x86/snowdsp.c

#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (int x, IDWTELEM * buf, int y, int w)
{
  for (x = 0; x < w; x++)
    {
      buf[x + y * w] -= 128 << 4;
    }
}
