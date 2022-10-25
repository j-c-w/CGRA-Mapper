// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_bilateral.c

#include <stdint.h>
#include <stdio.h>






int
fn (const int slice_start, const int slice_end, const int width,
    float *img_out_f, float *map_factor_b, float *ypy, int h1)
{
  for (int x = 0, k = 0; x < slice_end - slice_start; x++)
    {
      int idx = h1 * width + x;
      img_out_f[idx] =
	(img_out_f[idx] + ypy[k++]) / map_factor_b[h1 * width + x];
}}
