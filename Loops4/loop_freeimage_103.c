// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/dec/vp8l_dec.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * const new_data, const int final_num_colors, int i)
{
  for (; i < 4 * final_num_colors; ++i)
    {
      new_data[i] = 0;
    }
}
