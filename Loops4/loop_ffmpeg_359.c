// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/speedhq.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (uint8_t level_bits[266], int i, int entry, int sign,
    int16_t level_symbols[266], uint16_t level_code[266])
{
  for (i = 0; i < 4; ++i)
    {
      level_code[entry] = (i << 3) | (sign << 2) | 2;
      level_bits[entry] = 5;
      level_symbols[entry] = sign ? -(i + 2) : (i + 2);
      ++entry;
    }
}
