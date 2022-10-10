#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * dst, int i, int width)
{
  for (i = 0; i < width; i++)
    {
      dst[i] =
	((int)
	 (((dst[i]) >
	   (30189 << 4) ? (30189 << 4) : (dst[i])) * 4769U -
	  (39057361 << 2))) >> 12;
}}
