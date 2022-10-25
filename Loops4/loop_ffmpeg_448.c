// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/dvenc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int i, uint8_t * b, ptrdiff_t linesize, uint8_t * d, uint8_t * c_ptr)
{
  for (i = 0; i < 8; i++)
    {
      d = c_ptr + linesize * 8;
      b[0] = c_ptr[0];
      b[1] = c_ptr[1];
      b[2] = c_ptr[2];
      b[3] = c_ptr[3];
      b[4] = d[0];
      b[5] = d[1];
      b[6] = d[2];
      b[7] = d[3];
      c_ptr += linesize;
      b += 16;
    }
}
