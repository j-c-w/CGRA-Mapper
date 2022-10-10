#include <stdint.h>
#include <stdio.h>






int
fn (float *ypy, const int slice_start, float *img_out_f, int h1,
    const int width, float *map_factor_b, const int slice_end)
{
  for (int x = 0, k = 0; x < slice_end - slice_start; x++)
    {
      int idx = h1 * width + x;
      img_out_f[idx] =
	(img_out_f[idx] + ypy[k++]) / map_factor_b[h1 * width + x];
}}
