// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavformat/isom.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, unsigned int code, char *to)
{
  for (i = 2; i >= 0; i--)
    {
      to[i] = 0x60 + (code & 0x1f);
      code >>= 5;
    }
}
