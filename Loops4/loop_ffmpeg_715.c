// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/x86/swscale.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int32_t int32_t;

int
fn (int i, const int vChrFilterSize, int16_t * vChrFilter, const int chrDstY,
    const int16_t ** chrUSrcPtr, int32_t * chrMmxFilter)
{
  for (i = 0; i < vChrFilterSize; i++)
    {
      *(const void * *) &chrMmxFilter[4 * i + 0] = chrUSrcPtr[i];
      chrMmxFilter[4 * i + 2] = chrMmxFilter[4 * i + 3] =
	((uint16_t) vChrFilter[chrDstY * vChrFilterSize + i]) * 0x10001U;
}}
