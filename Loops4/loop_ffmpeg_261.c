// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/bgmc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint16_t * const cf_table[16], uint8_t * lut, int delta,
    unsigned int sx, unsigned int i)
{
  for (i = 0; i < (1 << (14 - 8)); i++)
    {
      unsigned int target = (i + 1) << (14 - (14 - 8));
      unsigned int symbol = 1 << delta;
      while (cf_table[sx][symbol] > target)
	symbol += 1 << delta;
      *lut++ = symbol >> delta;
    }
}
