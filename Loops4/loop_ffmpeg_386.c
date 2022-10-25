// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libswscale/swscale_unscaled.c

#include <stdint.h>
#include <stdio.h>






int
fn (int i, int stride2013[4], int stride1023[4], int srcSliceY,
    uint16_t * dst1023[4], uint16_t * dst2013[4])
{
  for (i = 0; i < 4; i++)
    {
      dst2013[i] += stride2013[i] * srcSliceY / 2;
      dst1023[i] += stride1023[i] * srcSliceY / 2;
    }
}
