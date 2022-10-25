// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/ac3enc.c

#include <stdint.h>
#include <stdio.h>






int
fn (uint8_t exponent_group_tab[2][3][256], int expstr, int i, int grpsize)
{
  for (i = 12; i < 256; i++)
    {
      exponent_group_tab[0][expstr][i] = (i + grpsize - 4) / grpsize;
      exponent_group_tab[1][expstr][i] = (i) / grpsize;
    }
}
