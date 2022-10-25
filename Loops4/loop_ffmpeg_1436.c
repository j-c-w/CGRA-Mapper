// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/mjpegdec.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (uint8_t * ptr, int mb_x, uint16_t (*buffer)[4], unsigned int width)
{
  for (mb_x = 0; mb_x < width; mb_x++)
    {
      ((uint16_t *) ptr)[2 * mb_x + 0] = buffer[mb_x][0];
      ((uint16_t *) ptr)[2 * mb_x + 1] = buffer[mb_x][1];
    }
}
