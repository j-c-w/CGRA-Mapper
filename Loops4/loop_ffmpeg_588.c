// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswresample/rematrix.c

#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef int64_t integer;

int
fn (int i, integer len, int *coeffp, int32_t ** out, const int32_t ** in)
{
  for (i = 0; i < len; i++)
    {
      int64_t t =
	in[2][i] * (int64_t) coeffp[0 * 6 + 2] +
	in[3][i] * (int64_t) coeffp[0 * 6 + 3];
      out[0][i] =
	(((t + in[0][i] * (int64_t) coeffp[0 * 6 + 0] +
	   in[4][i] * (int64_t) coeffp[0 * 6 + 4]) + 16384) >> 15);
      out[1][i] =
	(((t + in[1][i] * (int64_t) coeffp[1 * 6 + 1] +
	   in[5][i] * (int64_t) coeffp[1 * 6 + 5]) + 16384) >> 15);
    }
}
