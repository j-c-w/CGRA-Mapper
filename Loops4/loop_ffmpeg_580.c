// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswresample/rematrix.c

#include <stdint.h>
#include <stdio.h>




typedef int64_t integer;

int
fn (float *coeffp, int i, integer len, float **out, const float **in)
{
  for (i = 0; i < len; i++)
    {
      float t =
	in[2][i] * (float) coeffp[0 * 6 + 2] +
	in[3][i] * (float) coeffp[0 * 6 + 3];
      out[0][i] =
	t + in[0][i] * (float) coeffp[0 * 6 + 0] +
	in[4][i] * (float) coeffp[0 * 6 + 4];
      out[1][i] =
	t + in[1][i] * (float) coeffp[1 * 6 + 1] +
	in[5][i] * (float) coeffp[1 * 6 + 5];
}}
