#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint16_t uint16_t;

int
fn (const int xcenter, const int fill_color, const int h, uint16_t * out,
    const int32_t * correction, int i, const int off_y,
    const uint16_t * indata, const int w, const int inlinesize,
    const int ycenter)
{
  for (int j = 0; j < w; j++)
    {
      const int off_x = j - xcenter;
      const int64_t radius_mult = correction[j + i * w];
      const int x = xcenter + ((radius_mult * off_x + (1 << 23)) >> 24);
      const int y = ycenter + ((radius_mult * off_y + (1 << 23)) >> 24);
      const char isvalid = x >= 0 && x < w && y >= 0 && y < h;
      *out++ = isvalid ? indata[y * inlinesize + x] : fill_color;
}}
