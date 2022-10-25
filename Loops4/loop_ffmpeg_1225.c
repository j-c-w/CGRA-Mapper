// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/g723_1dec.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int64_t int64_t;

int
fn (int16_t * vector_ptr, int64_t sum, int t, int tmp[120], int shift, int j)
{
  for (j = 0; j < 60 * 2; j++)
    {
      t = vector_ptr[j] >> shift;
      sum += t * t;
      tmp[j] = t;
    }
}
