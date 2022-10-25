// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/s302m.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (const uint8_t ff_reverse[256], int buf_size, const uint8_t * buf,
    uint32_t * o)
{
  for (; buf_size > 6; buf_size -= 7)
    {
      *o++ =
	((unsigned) ff_reverse[buf[2]] << 24) | (ff_reverse[buf[1]] << 16) |
	(ff_reverse[buf[0]] << 8);
      *o++ =
	((unsigned) ff_reverse[buf[6] & 0xf0] << 28) | (ff_reverse[buf[5]] <<
							20) |
	(ff_reverse[buf[4]] << 12) | (ff_reverse[buf[3] & 0x0f] << 4);
      buf += 7;
}}
