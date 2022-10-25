// Source is: /home/alex/.local/share/compy-Learn/1.0/ffmpeg/content/libavfilter/vf_yaepblur.c

#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;
typedef __uint16_t uint16_t;

int
fn (const int dst_linesize, uint64_t * square_sat, int higher_x,
    uint64_t * sat, int lower_x, int x, uint64_t var, const int width,
    const int sigma, int higher_y, const int radius, int dist_y, int y,
    int count, int lower_y, const uint16_t * src, const int sat_linesize,
    uint64_t sum, uint64_t square_sum, uint64_t mean, const int src_linesize,
    uint16_t * dst)
{
  for (x = 0; x < width; x++)
    {
      lower_x = x - radius < 0 ? 0 : x - radius;
      higher_x = x + radius + 1 > width ? width : x + radius + 1;
      count = dist_y * (higher_x - lower_x);
      sum =
	sat[higher_y * sat_linesize + higher_x] -
	sat[higher_y * sat_linesize + lower_x] - sat[lower_y * sat_linesize +
						     higher_x] +
	sat[lower_y * sat_linesize + lower_x];
      square_sum =
	square_sat[higher_y * sat_linesize + higher_x] -
	square_sat[higher_y * sat_linesize + lower_x] -
	square_sat[lower_y * sat_linesize + higher_x] +
	square_sat[lower_y * sat_linesize + lower_x];
      mean = sum / count;
      var = (square_sum - sum * sum / count) / count;
      dst[y * dst_linesize + x] =
	(sigma * mean + var * src[y * src_linesize + x]) / (sigma + var);
    }
}
