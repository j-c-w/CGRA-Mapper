// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibJXR/image/decode/strInvTransform.c

#include <stdint.h>
#include <stdio.h>




typedef int PixelI;

int
fn (PixelI * p, int i)
{
  for (i = 0; i < 256; i += 16)
    {
      p[i] += p[i];
    }
}
