// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/utils.c

#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const uint16_t (*tab)[2], int i, int a, int size, int b)
{
  for (i = 0; i < size && !(tab[i][0] == a && tab[i][1] == b); i++);
}
