#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;
typedef __uint16_t uint16_t;

int
fn (uint64_t * sat, const int src_linesize, int higher_x, uint64_t square_sum,
    const int radius, const int sat_linesize, int lower_y, uint64_t var,
    int lower_x, uint64_t sum, uint64_t * square_sat, const int sigma, int y,
    int x, const uint16_t * src, int dist_y, uint64_t mean, uint16_t * dst,
    int count, const int width, const int dst_linesize, int higher_y)
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
