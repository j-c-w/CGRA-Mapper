// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/nellymoser.c

#include <stdint.h>
#include <stdio.h>






int
fn (int max, const float *buf, int i)
{
  for (i = 0; i < 124; i++)
    {
      max = ((max) > (buf[i]) ? (max) : (buf[i]));
    }
}
