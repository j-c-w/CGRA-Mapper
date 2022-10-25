// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/notchlc.c

#include <stdint.h>
#include <stdio.h>






int
fn (int u[16][16], int v[16][16], unsigned int loc, int udif, int u0, int v0,
    int vdif)
{
  int i = 0;
  int ii = 0;
  int jj = 0;
  int j = 0;
  int iii = 0;
  for (int jjj = 0; jjj < 4; jjj++)
    {
      u[i + ii + iii][j + jj + jjj] = u0 + ((udif * (int) (loc & 3) + 2) / 3);
      v[i + ii + iii][j + jj + jjj] = v0 + ((vdif * (int) (loc & 3) + 2) / 3);
      loc >>= 2;
}}
