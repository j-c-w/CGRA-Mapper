// Source is: /home/alex/.local/share/compy-Learn/1.0/DarkNet/content/./src/image.c

#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;
typedef uint32_t stbi__uint32;

int
fn (stbi_uc * p, stbi__uint32 pixel_count, stbi__uint32 i)
{
  for (i = 0; i < pixel_count; ++i)
    {
      stbi_uc t = p[0];
      p[0] = p[2];
      p[2] = t;
      p += 3;
    }
}
