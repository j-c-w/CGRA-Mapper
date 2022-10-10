#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int font_height, int fg, const uint8_t * font, int mask, int char_y,
    uint8_t * dst, int bg, int ch)
{
  for (mask = 0x80; mask; mask >>= 1)
    {
      *dst++ = font[ch * font_height + char_y] & mask ? fg : bg;
    }
}
