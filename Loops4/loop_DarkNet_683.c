// Source is: /home/alex/.local/share/compy-Learn/1.0/DarkNet/content/./src/image.c

#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;
typedef uint32_t stbi__uint32;

int
fn (stbi_uc * tc, stbi__uint32 pixel_count, stbi_uc * p, stbi__uint32 i)
{
  for (i = 0; i < pixel_count; ++i)
    {
      p[1] = (p[0] == tc[0] ? 0 : 255);
      p += 2;
    }
}
