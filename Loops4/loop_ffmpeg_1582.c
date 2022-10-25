// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/snowdec.c

#include <stdint.h>
#include <stdio.h>




typedef short IDWTELEM;

int
fn (int x, IDWTELEM * line, int w)
{
  for (x = 0; x < w; x++)
    {
      line[x] -= 128 << 4;
    }
}
