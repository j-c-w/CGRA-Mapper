// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/utils/quant_levels_utils.c

#include <stdint.h>
#include <stdio.h>






int
fn (int min_s, int num_levels, int i, double inv_q_level[256])
{
  int max_s = 255;
  for (i = 0; i < num_levels; ++i)
    {
      inv_q_level[i] =
	min_s + (double) (max_s - min_s) * i / (num_levels - 1);
}}
