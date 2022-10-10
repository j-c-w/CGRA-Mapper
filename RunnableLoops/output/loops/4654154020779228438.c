#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * color_rgba, uint8_t * b, int y_step)
{
  for (int i = 0; i < 4; i++)
    {
      b[0] =
	((((((int) ((0.29900) * (1 << 10) + 0.5)) * (color_rgba[0]) +
	    ((int) ((0.58700) * (1 << 10) + 0.5)) * (color_rgba[1]) +
	    ((int) ((0.11400) * (1 << 10) + 0.5)) * (color_rgba[2]) +
	    ((1 << (10 - 1)))) >> 10) >
	  (255) ? (255)
	  : ((((int) ((0.29900) * (1 << 10) + 0.5)) * (color_rgba[0]) +
	      ((int) ((0.58700) * (1 << 10) + 0.5)) * (color_rgba[1]) +
	      ((int) ((0.11400) * (1 << 10) + 0.5)) * (color_rgba[2]) +
	      ((1 << (10 - 1)))) >> 10))) + 128;
      b[1] = 0x06;
      b += y_step;
}}
