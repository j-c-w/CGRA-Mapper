// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/notchlc.c

#include <stdint.h>
#include <stdio.h>






int
fn (unsigned int loc, int v[16][16], int u[16][16], int udif, int u0, int v0,
    int vdif)
{
  int j = 0;
  int ii = 0;
  int i = 0;
  for (int jj = 0; jj < 4; jj++)
    {
      u[i + ii][j + jj] = u0 + ((udif * (int) (loc & 3) + 2) / 3);
      v[i + ii][j + jj] = v0 + ((vdif * (int) (loc & 3) + 2) / 3);
}}
