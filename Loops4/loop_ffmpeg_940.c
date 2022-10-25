// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/dv_error_marker_bsf.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * color_rgba, int u_step, int cblocks, uint8_t * b)
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
