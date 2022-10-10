#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const int slicew_start, const int d2_signed_linesize, uint16_t * const d2,
    const int c1_shift_w, const uint16_t * c0_data, const int c2_shift_w,
    const int limit, int x, const uint16_t * c1_data,
    const int d1_signed_linesize, const int slicew_end,
    const int d0_signed_linesize, uint16_t * const d1, uint16_t * const d0,
    const int c0_shift_w, const uint16_t * c2_data)
{
  for (x = slicew_start; x < slicew_end; x++)
    {
      const int c0 =
	((c0_data[x >> c0_shift_w]) >
	 (limit) ? (limit) : (c0_data[x >> c0_shift_w]));
      const int c1 = c1_data[x >> c1_shift_w];
      const int c2 = c2_data[x >> c2_shift_w];
      *(d0 + d0_signed_linesize * c0 + x) = c0;
      *(d1 + d1_signed_linesize * c0 + x) = c1;
      *(d2 + d2_signed_linesize * c0 + x) = c2;
}}
