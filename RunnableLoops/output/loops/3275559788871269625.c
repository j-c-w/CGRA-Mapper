#include <stdint.h>
#include <stdio.h>






int
fn (int i, unsigned char b, unsigned int *palette32,
    unsigned char *raw_palette, unsigned char g, unsigned char r)
{
  int palette_index = 0;
  for (i = 0; i < 256; i++)
    {
      r = raw_palette[palette_index++] * 4;
      g = raw_palette[palette_index++] * 4;
      b = raw_palette[palette_index++] * 4;
      palette32[i] = 0xFFU << 24 | (r << 16) | (g << 8) | (b);
      palette32[i] |= palette32[i] >> 6 & 0x30303;
    }
}
