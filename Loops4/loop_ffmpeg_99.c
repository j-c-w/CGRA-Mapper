// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/s302m.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (const uint8_t ff_reverse[256], int buf_size, const uint8_t * buf,
    uint16_t * o)
{
  for (; buf_size > 4; buf_size -= 5)
    {
      *o++ = (ff_reverse[buf[1]] << 8) | ff_reverse[buf[0]];
      *o++ =
	(ff_reverse[buf[4] & 0xf0] << 12) | (ff_reverse[buf[3]] << 4) |
	(ff_reverse[buf[2]] >> 4);
      buf += 5;
    }
}
