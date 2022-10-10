#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int src_linesize, uint8_t * dst, int w, const uint8_t * src)
{
  for (i = 2; i < w - 2; i++)
    {
      dst[i] =
	((src[-2 * src_linesize + i - 2] +
	  src[2 * src_linesize + i - 2]) * 2 + (src[-2 * src_linesize + i -
						    1] +
						src[2 * src_linesize + i -
						    1]) * 4 +
	 (src[-2 * src_linesize + i] + src[2 * src_linesize + i]) * 5 +
	 (src[-2 * src_linesize + i + 1] +
	  src[2 * src_linesize + i + 1]) * 4 + (src[-2 * src_linesize + i +
						    2] +
						src[2 * src_linesize + i +
						    2]) * 2 +
	 (src[-src_linesize + i - 2] + src[src_linesize + i - 2]) * 4 +
	 (src[-src_linesize + i - 1] + src[src_linesize + i - 1]) * 9 +
	 (src[-src_linesize + i] + src[src_linesize + i]) * 12 +
	 (src[-src_linesize + i + 1] + src[src_linesize + i + 1]) * 9 +
	 (src[-src_linesize + i + 2] + src[src_linesize + i + 2]) * 4 +
	 src[i - 2] * 5 + src[i - 1] * 12 + src[i] * 15 + src[i + 1] * 12 +
	 src[i + 2] * 5) / 159;
    }
}
