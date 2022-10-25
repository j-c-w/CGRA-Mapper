// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/dvbsubdec.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, int (*counttab2)[256])
{
  for (i = 0; i < 256; i++)
    {
      counttab2[i + 1][i] = 0;
    }
}
