#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, const uint8_t * block)
{
  int sum = 0;
  for (int x = 0; x < w; x++)
    {
      sum += block[x];
}}
