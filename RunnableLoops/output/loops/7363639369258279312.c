#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (uint32_t * lut)
{
  for (int i = 0; i < 32; i += 2)
    {
      lut[i] = 0x68000;
      lut[i + 1] = 0;
}}
