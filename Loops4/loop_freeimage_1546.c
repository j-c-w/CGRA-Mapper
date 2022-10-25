// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/enc/picture_tools_enc.c

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int uv_width, uint8_t * const a_ptr, const int V0, int x,
    uint8_t * const a_ptr2, uint8_t * const v, const int U0,
    uint8_t * const u)
{
  for (x = 0; x < uv_width; ++x)
    {
      const int alpha =
	a_ptr[2 * x + 0] + a_ptr[2 * x + 1] + a_ptr2[2 * x + 0] +
	a_ptr2[2 * x + 1];
      u[x] =
	((((U0) * (1020 - (alpha)) + (u[x]) * (alpha)) * 0x101 + 1024) >> 18);
      v[x] =
	((((V0) * (1020 - (alpha)) + (v[x]) * (alpha)) * 0x101 + 1024) >> 18);
}}
