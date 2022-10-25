// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_colorconstancy.c

#include <stdint.h>
#include <stdio.h>






int
fn (double *light, int plane)
{
  for (plane = 0; plane < 3; ++plane)
    {
      light[plane] = 1.0;
    }
}
