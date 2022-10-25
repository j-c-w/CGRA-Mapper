// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/aacdec.c

#include <stdint.h>
#include <stdio.h>




typedef float INTFLOAT;

int
fn (const INTFLOAT * const window, const int n2, int i, const int n,
    const int n4, INTFLOAT * saved, INTFLOAT * out, INTFLOAT * buf)
{
  for (i = 0; i < n4; i++)
    {
      out[n2 + n4 + i] =
	((buf[i + n2]) * (window[i + n - n4])) +
	((-saved[n2 - 1 - i]) * (window[i + 2 * n - n4])) +
	((-saved[n + n2 + i]) * (window[i + 3 * n - n4]));
    }
}
