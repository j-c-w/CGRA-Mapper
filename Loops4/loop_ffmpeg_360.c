// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/speedhq.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (int i, int entry, int16_t run_symbols[134], uint16_t run_code[134],
    uint8_t run_bits[134])
{
  for (i = 0; i < 4; ++i)
    {
      run_code[entry] = (i << 2) | 1;
      run_bits[entry] = 4;
      run_symbols[entry] = i + 1;
      ++entry;
    }
}
