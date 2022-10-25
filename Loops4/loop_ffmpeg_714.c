// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/x86/swscale.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __int16_t int16_t;

int
fn (int i, const int vChrFilterSize, int16_t * vChrFilter, const int chrDstY,
    const int16_t ** chrUSrcPtr, int s, int32_t * chrMmxFilter)
{
  for (i = 0; i < vChrFilterSize; i += 2)
    {
      *(const void * *) &chrMmxFilter[s * i] = chrUSrcPtr[i];
      *(const void * *) &chrMmxFilter[s * i + 8 / 4] =
	chrUSrcPtr[i + (vChrFilterSize > 1)];
      chrMmxFilter[s * i + 16 / 4] = chrMmxFilter[s * i + 16 / 4 + 1] =
	vChrFilter[chrDstY * vChrFilterSize + i] + (vChrFilterSize >
						    1 ? vChrFilter[chrDstY *
								   vChrFilterSize
								   + i +
								   1] *
						    (1 << 16) : 0);
}}
