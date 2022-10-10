#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint8_t uint8_t;

int
fn (const int fill_color, const int xcenter, const int h,
    const int32_t * correction, uint8_t * out, int i, const int off_y,
    const uint8_t * indata, const int ycenter, const int inlinesize,
    const int w)
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
