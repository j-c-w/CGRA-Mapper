// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/x86/swscale.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (const int16_t ** tmpU, const int16_t ** chrUSrcPtr, int end, int i)
{
  for (; i < end; i++)
    {
      tmpU[i] = chrUSrcPtr[i];
    }
}
