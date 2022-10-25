// Source is: /home/alex/.local/share/compy-Learn/1.0/DarkNet/content/./src/image.c

#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;
typedef uint32_t stbi__uint32;

int
fn (stbi_uc * orig, stbi_uc * p, stbi__uint32 i, stbi_uc * palette,
    stbi__uint32 pixel_count)
{
  for (i = 0; i < pixel_count; ++i)
    {
      int n = orig[i] * 4;
      p[0] = palette[n];
      p[1] = palette[n + 1];
      p[2] = palette[n + 2];
      p += 3;
}}
