// Source is: /home/alex/.local/share/compy-Learn/1.0/DarkNet/content/./src/image.c

#include <stdint.h>
#include <stdio.h>




typedef unsigned char stbi_uc;

int
fn (stbi_uc * in_far, int i, int w, int t1, stbi_uc * in_near, int t0,
    stbi_uc * out)
{
  for (i = 1; i < w; ++i)
    {
      t0 = t1;
      t1 = 3 * in_near[i] + in_far[i];
      out[i * 2 - 1] = ((stbi_uc) ((3 * t0 + t1 + 8) >> 4));
      out[i * 2] = ((stbi_uc) ((3 * t1 + t0 + 8) >> 4));
    }
}
