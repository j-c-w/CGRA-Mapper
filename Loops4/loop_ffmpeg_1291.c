// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/af_headphone.c

#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (const uint32_t modulo, int n_read, float *dst, int wr, int j,
    float *ringbuffer)
{
  for (j = 0; j < n_read; j++)
    {
      dst[2 * j] = ringbuffer[wr];
      ringbuffer[wr] = 0.0;
      wr = (wr + 1) & modulo;
    }
}
