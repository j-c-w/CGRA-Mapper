// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_deshake.c

#include <stdint.h>
#include <stdio.h>






int
fn (int cut, int count, int x, double *values, double mean)
{
  for (x = cut; x < count - cut; x++)
    {
      mean += values[x];
    }
}
