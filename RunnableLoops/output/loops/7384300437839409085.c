#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * brightsrc, const uint8_t * darksrc, const uint8_t * bsrc,
    int overshoot, uint8_t * dst, int undershoot, int w)
{
  for (int x = 0; x < w; x++)
    {
      dst[x] =
	((bsrc[x]) >
	 (darksrc[x] - undershoot) ? (bsrc[x]) : (darksrc[x] - undershoot));
      dst[x] =
	((dst[x]) >
	 (brightsrc[x] + overshoot) ? (brightsrc[x] + overshoot) : (dst[x]));
}}
