// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_gblur.c

#include <stdint.h>
#include <stdio.h>






int
fn (float *ptr, int column_step, float boundaryscale)
{
  for (int k = 0; k < column_step; k++)
    {
      ptr[k] *= boundaryscale;
}}
