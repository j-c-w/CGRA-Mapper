// Source is: /home/alex/.local/share/compy-Learn/1.0/DarkNet/content/./src/image.c

#include <stdint.h>
#include <stdio.h>




typedef uint32_t stbi__uint32;
typedef uint16_t stbi__uint16;

int
fn (stbi__uint16 * p, stbi__uint32 pixel_count, stbi__uint16 * tc,
    stbi__uint32 i)
{
  for (i = 0; i < pixel_count; ++i)
    {
      p[1] = (p[0] == tc[0] ? 0 : 65535);
      p += 2;
    }
}
