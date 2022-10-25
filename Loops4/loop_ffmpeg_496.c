// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavformat/qtpalette.c

#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (uint32_t b, uint32_t * palette, int i, uint32_t r, uint32_t color_count,
    uint32_t g, const uint8_t * color_table)
{
  for (i = 0; i < color_count; i++)
    {
      r = color_table[i * 3 + 0];
      g = color_table[i * 3 + 1];
      b = color_table[i * 3 + 2];
      palette[i] = (0xFFU << 24) | (r << 16) | (g << 8) | (b);
    }
}
