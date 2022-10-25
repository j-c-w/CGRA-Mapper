// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/dolby_e.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, float mantissa_tab1[17][4])
{
  for (i = 2; i < 16; i++)
    {
      mantissa_tab1[i][1] = 1.0f / ((1 << i) - 1);
      mantissa_tab1[i][2] = 0.5f / ((1 << i) - 1);
      mantissa_tab1[i][3] = 0.25f / ((1 << i) - 1);
    }
}
