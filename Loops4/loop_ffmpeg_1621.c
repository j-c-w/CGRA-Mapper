// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_gradfun.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (const uint16_t * buf1, int v, uint16_t * dc, int x, int width,
    int src_linesize, const uint8_t * src, uint16_t * buf, int old)
{
  for (x = 0; x < width; x++)
    {
      v =
	buf1[x] + src[2 * x] + src[2 * x + 1] + src[2 * x + src_linesize] +
	src[2 * x + 1 + src_linesize];
      old = buf[x];
      buf[x] = v;
      dc[x] = v - old;
    }
}
