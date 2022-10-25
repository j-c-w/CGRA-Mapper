// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/vmdvideo.c

#include <stdint.h>
#include <stdio.h>






int
fn (unsigned char *d, unsigned int j, unsigned int chainlen,
    unsigned int chainofs, unsigned char queue[4096], unsigned int qpos)
{
  for (j = 0; j < chainlen; j++)
    {
      *d = queue[chainofs++ & 0x0FFF];
      queue[qpos++] = *d++;
      qpos &= 0x0FFF;
    }
}
