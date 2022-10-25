// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/x86/swscale.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (const int16_t ** tmpU, int i, const int vChrFilterSize)
{
  for (; i < vChrFilterSize; i++)
    {
      tmpU[i] = tmpU[i - 1];
    }
}
