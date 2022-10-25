// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/aacdec_fixed.c

#include <stdint.h>
#include <stdio.h>




typedef int INTFLOAT;

int
fn (const INTFLOAT * const window, const int n2, int i, INTFLOAT * saved,
    const int n4, const int n, INTFLOAT * out, INTFLOAT * buf)
{
  for (i = n4; i < n2; i++)
    {
      out[i - n4] =
	(int) (((int64_t) (buf[n2 - 1 - i]) * (window[i - n4]) +
		0x40000000) >> 31) +
	(int) (((int64_t) (saved[i + n2]) * (window[i + n - n4]) +
		0x40000000) >> 31) +
	(int) (((int64_t) (-saved[n + n2 - 1 - i]) *
		(window[i + 2 * n - n4]) + 0x40000000) >> 31) +
	(int) (((int64_t) (-saved[2 * n + n2 + i]) *
		(window[i + 3 * n - n4]) + 0x40000000) >> 31);
}}
