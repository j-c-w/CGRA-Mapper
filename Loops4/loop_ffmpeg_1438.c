// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/ituh263enc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int mv, uint8_t umv_fcode_tab[8193])
{
  for (mv = 0; mv < 4096 * 2 + 1; mv++)
    {
      umv_fcode_tab[mv] = 1;
    }
}
