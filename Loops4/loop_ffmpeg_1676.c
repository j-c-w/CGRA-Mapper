// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/vp9block.c

#include <stdint.h>
#include <stdio.h>






int
fn (int y, int h, int row_and_7, int t8, int t4, uint8_t (*mask)[8][4])
{
  for (y = row_and_7; y < h + row_and_7; y++)
    {
      mask[0][y][2] |= t4;
      mask[0][y][1] |= t8;
    }
}
