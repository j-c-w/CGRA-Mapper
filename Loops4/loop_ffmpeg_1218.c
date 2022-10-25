// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavcodec/error_resilience.c

#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __uint32_t uint32_t;
typedef __int16_t int16_t;
typedef long int ptrdiff_t;

int
fn (int b_y, uint32_t (*dist)[4], ptrdiff_t stride, int b_x,
    int64_t weight_sum, int j, int16_t (*col)[4], int64_t guess)
{
  for (j = 0; j < 4; j++)
    {
      int64_t weight =
	256 * 256 * 256 * 16 / ((dist[b_x + b_y * stride][j]) >
				(1) ? (dist[b_x + b_y * stride][j]) : (1));
      guess += weight * (int64_t) col[b_x + b_y * stride][j];
      weight_sum += weight;
    }
}
