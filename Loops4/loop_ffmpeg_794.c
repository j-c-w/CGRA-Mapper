// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavutil/utils.c

#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;

int
fn (unsigned int i, uint64_t * l, uint64_t t)
{
  for (i = 0; l[i] != t; i++);
}
