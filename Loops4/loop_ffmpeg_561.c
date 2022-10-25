// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/fftools/ffprobe.c

#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;

int
fn (size_t len, size_t i, const char *s)
{
  for (i = 0; i < len && s[i]; i++);
}
