// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/amrwbdec.c

#include <stdint.h>
#include <stdio.h>






int
fn (float cpe, int i, float last, float *fixed_vector)
{
  for (i = 1; i < 64 - 1; i++)
    {
      float cur = fixed_vector[i];
      fixed_vector[i] -= cpe * (last + fixed_vector[i + 1]);
      last = cur;
}}
