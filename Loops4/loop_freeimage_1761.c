// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/utils/quant_levels_utils.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int min_s, uint8_t map[256], double inv_q_level[256], int s,
    int q_level[256])
{
  int max_s = 255;
  for (s = min_s; s <= max_s; ++s)
    {
      const int slot = q_level[s];
      map[s] = (uint8_t) (inv_q_level[slot] + .5);
}}
