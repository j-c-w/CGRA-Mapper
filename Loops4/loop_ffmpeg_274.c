// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/fic.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * ptr, uint8_t planes[4][1024], int i)
{
  for (i = 0; i < 1024; i++)
    {
      planes[0][i] = ((25 * ptr[0] + 129 * ptr[1] + 66 * ptr[2]) / 255) + 16;
      planes[1][i] =
	((-38 * ptr[0] + 112 * ptr[1] + -74 * ptr[2]) / 255) + 128;
      planes[2][i] =
	((-18 * ptr[0] + 112 * ptr[1] + -94 * ptr[2]) / 255) + 128;
      planes[3][i] = ptr[3];
      ptr += 4;
    }
}
