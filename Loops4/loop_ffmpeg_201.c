// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/lcldec.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int col, uint8_t * v_out, unsigned char *encoded, unsigned int width,
    uint8_t * y_out, uint8_t * u_out)
{
  for (col = 0; col < width; col++)
    {
      y_out[col] = *encoded++;
      u_out[col] = *encoded++ + 128;
      v_out[col] = *encoded++ + 128;
    }
}
