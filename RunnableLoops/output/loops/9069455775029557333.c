#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int u_step, const uint8_t * color_rgba, uint8_t * b, int cblocks)
{
  for (int i = 0; i < cblocks; i++)
    {
      b[0] =
	(((-((int) ((0.16874) * (1 << 10) + 0.5)) * color_rgba[0] -
	   ((int) ((0.33126) * (1 << 10) + 0.5)) * color_rgba[1] +
	   ((int) ((0.50000) * (1 << 10) + 0.5)) * color_rgba[2] +
	   ((1 << (10 - 1))) - 1) >> (10)) + 128) - 128;
      b[1] = 0x16;
      b += u_step;
}}
