// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mobiclip.c

#include <stdint.h>
#include <stdio.h>






int
fn (int mat[64], int size)
{
  int y = 0;
  for (int x = y + 1; x < size; x++)
    {
      int a = mat[x * size + y];
      int b = mat[y * size + x];
      mat[y * size + x] = a;
      mat[x * size + y] = b;
}}
