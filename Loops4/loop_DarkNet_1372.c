// Source is: /home/alex/.local/share/compy-Learn/1.0/DarkNet/content/./src/image.c

#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;

int
fn (stbi_uc * cur, int k, stbi_uc * raw, int filter_bytes)
{
  for (k = 0; k < filter_bytes; ++k)
    {
      cur[k] = raw[k];
    }
}
