// Source is: /home/alex/.local/share/compy-Learn/1.0/freeimage/content/Source/LibWebP/src/utils/quant_levels_dec_utils.c

#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, int16_t * const lut, const int delta, const int threshold1,
    const int threshold2, const int max_threshold)
{
  for (i = 1; i <= ((1 << (8 + 2)) - 1); ++i)
    {
      int c =
	(i <= threshold2) ? (i << 0) : (i <
					threshold1) ? max_threshold *
	(threshold1 - i) / delta : 0;
      c >>= 2;
      lut[+i] = +c;
      lut[-i] = -c;
}}
