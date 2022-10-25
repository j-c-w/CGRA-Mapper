// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_w3fdif.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int8_t int8_t;

int
fn (const int height, uint8_t * cur_data, const int8_t n_coef_hf[2], int y_in,
    uint8_t * in_lines_cur[5], const int filter, uint8_t * in_lines_adj[5],
    uint8_t * adj_data, const int cur_line_stride, int y_out, int j,
    const int adj_line_stride)
{
  for (j = 0; j < n_coef_hf[filter]; j++)
    {
      y_in = (y_out + 1) + (j * 2) - n_coef_hf[filter];
      while (y_in < 0)
	y_in += 2;
      while (y_in >= height)
	y_in -= 2;
      in_lines_cur[j] = cur_data + (y_in * cur_line_stride);
      in_lines_adj[j] = adj_data + (y_in * adj_line_stride);
    }
}
