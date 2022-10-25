// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/dsd.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (float ctables[6][256], unsigned int pos, uint8_t buf[16], double sum,
    unsigned int i)
{
  for (i = 0; i < ((48 + 7) / 8); i++)
    {
      uint8_t a = buf[(pos - i) & (16 - 1)];
      uint8_t b = buf[(pos - (((48 + 7) / 8) * 2 - 1) + i) & (16 - 1)];
      sum += ctables[i][a] + ctables[i][b];
    }
}
