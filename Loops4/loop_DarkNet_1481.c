// Source is: /home/alex/.local/share/compy-Learn/1.0/DarkNet/content/./src/image.c

#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;
typedef uint32_t stbi__uint32;

int
fn (stbi_uc * cur, stbi__uint32 x, int q)
{
  for (q = x - 1; q >= 0; --q)
    {
      cur[q * 4 + 3] = 255;
      cur[q * 4 + 2] = cur[q * 3 + 2];
      cur[q * 4 + 1] = cur[q * 3 + 1];
      cur[q * 4 + 0] = cur[q * 3 + 0];
    }
}
