// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/h264idct.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * block, unsigned int temp[8], const int stride, int i)
{
  const int xStride = 16;
  for (i = 0; i < 4; i++)
    {
      temp[2 * i + 0] =
	block[stride * i + xStride * 0] + (unsigned) block[stride * i +
							   xStride * 1];
      temp[2 * i + 1] =
	block[stride * i + xStride * 0] - (unsigned) block[stride * i +
							   xStride * 1];
}}
