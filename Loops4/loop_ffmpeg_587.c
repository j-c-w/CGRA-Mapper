// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavutil/fixed_dsp.c

#include <stdint.h>
#include <stdio.h>






int
fn (int *v2, unsigned int *v1, int i, int len)
{
  for (i = 0; i < len; i++)
    {
      int t = v1[i] - v2[i];
      v1[i] += v2[i];
      v2[i] = t;
}}
