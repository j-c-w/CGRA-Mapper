#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const uint16_t * darksrc, uint16_t * dst, int overshoot,
    const uint16_t * brightsrc, const uint16_t * bsrc, int undershoot, int w)
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
