// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/vp8dsp.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (unsigned int d1, int i, unsigned int b1, unsigned int c1, int16_t tmp[16],
    int16_t * dc, unsigned int a1)
{
  for (i = 0; i < 4; i++)
    {
      a1 = (dc[i * 4 + 0] + dc[i * 4 + 2]) * 23170;
      b1 = (dc[i * 4 + 0] - dc[i * 4 + 2]) * 23170;
      c1 = dc[i * 4 + 1] * 12540 - dc[i * 4 + 3] * 30274;
      d1 = dc[i * 4 + 1] * 30274 + dc[i * 4 + 3] * 12540;
      tmp[i * 4 + 0] = (int) (a1 + d1) >> 14;
      tmp[i * 4 + 3] = (int) (a1 - d1) >> 14;
      tmp[i * 4 + 1] = (int) (b1 + c1) >> 14;
      tmp[i * 4 + 2] = (int) (b1 - c1) >> 14;
}}
