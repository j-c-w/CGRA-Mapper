#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int height, int32_t * map)
{
  int y = 0;
  for (int i = 1; i < height; i++)
    {
      map[y + i] = map[y] + i;
}}
