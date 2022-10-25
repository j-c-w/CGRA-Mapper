// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/aacdec.c

#include <stdint.h>
#include <stdio.h>




typedef float INTFLOAT;

int
fn (const INTFLOAT * const window, const int n2, int i, const int n,
    const int n4, INTFLOAT * saved, INTFLOAT * out, INTFLOAT * buf)
{
  for (i = 0; i < n2; i++)
    {
      out[n4 + i] =
	((buf[i]) * (window[i + n2 - n4])) +
	((-saved[n - 1 - i]) * (window[i + n2 + n - n4])) +
	((-saved[n + i]) * (window[i + n2 + 2 * n - n4])) +
	((saved[2 * n + n - 1 - i]) * (window[i + n2 + 3 * n - n4]));
    }
}
