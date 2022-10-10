#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int dst_linesize, int y, int x, int src_linesize, int src_w,
    uint8_t * dst_data, const uint8_t * src_data)
{
  for (x = 0; x < src_w / 2; x++)
    {
      dst_data[(y * dst_linesize) + x] =
	src_data[((y << 1) * src_linesize) + (x << 1)]
	|| src_data[((y << 1) * src_linesize) + (x << 1) + 1]
	|| src_data[(((y << 1) + 1) * src_linesize) + (x << 1)]
	|| src_data[(((y << 1) + 1) * src_linesize) + (x << 1) + 1];
      dst_data[(y * dst_linesize) + x] =
	((1) >
	 (dst_data[(y * dst_linesize) + x])
	 ? (dst_data[(y * dst_linesize) + x]) : (1));
    }
}
