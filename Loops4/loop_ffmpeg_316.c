// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/on2avc.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *buf)
{
  for (i = 0; i < 256; i++)
    {
      do
	{
	  float SWAP_tmp = buf[511 - i];
	  buf[511 - i] = buf[i];
	  buf[i] = SWAP_tmp;
	}
      while (0);
    }
}
