// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/x86/rgb2rgb.c

#include <stdint.h>
#include <stdio.h>




typedef int64_t x86_reg;
typedef __uint8_t uint8_t;

int
fn (int w, const uint8_t * yp, const uint8_t * up, const uint8_t * vp,
    uint8_t * d, x86_reg x)
{
  for (; x < w; x++)
    {
      const int x2 = x << 2;
      d[8 * x + 0] = yp[x2];
      d[8 * x + 1] = up[x];
      d[8 * x + 2] = yp[x2 + 1];
      d[8 * x + 3] = vp[x];
      d[8 * x + 4] = yp[x2 + 2];
      d[8 * x + 5] = up[x];
      d[8 * x + 6] = yp[x2 + 3];
      d[8 * x + 7] = vp[x];
}}
