// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/pixlet.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t stride, int k, int16_t * ptr, int16_t * tmp,
    unsigned int scaled_height)
{
  for (k = 0; k < scaled_height; k++)
    {
      *ptr = tmp[k];
      ptr += stride;
    }
}
