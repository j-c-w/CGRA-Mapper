// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/ac3dec_float.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, uint8_t ungroup_3_in_7_bits_tab[128][3])
{
  for (i = 0; i < 128; i++)
    {
      ungroup_3_in_7_bits_tab[i][0] = i / 25;
      ungroup_3_in_7_bits_tab[i][1] = (i % 25) / 5;
      ungroup_3_in_7_bits_tab[i][2] = (i % 25) % 5;
    }
}
